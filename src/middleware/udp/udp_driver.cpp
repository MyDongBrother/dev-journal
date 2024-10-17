#include "udp_driver.h"
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#ifdef __QNX_OS__
#include <net/if.h>
#include <cstdlib>
#else
#include <sys/prctl.h>
#endif
namespace middleware
{
UDPDrive::UDPDrive(std::string f_name_str)
{
    name = f_name_str; // set name
}

UDPDrive::~UDPDrive()
{
    // 关闭接收和发送线程
    recv_run_ = false;
    send_run_ = false;

    // 等待线程结束
    if (recv_thread_.joinable())
    {
        recv_thread_.join();
    }
    if (send_thread_.joinable())
    {
        send_thread_.join();
    }

    // 关闭套接字
    if (udp_sock_fd_ > 0)
    {
        close(udp_sock_fd_);
    }
}
/**
 * @brief 网络资源
 *
 * @param f_name_str
 * @return int
 */
int UDPDrive::Init(std::string f_target_ipaddr, uint32_t f_target_port,
                   uint32_t f_local_port)
{
    int retVal = md_RETURN_INIT_FAILED;
    if (inited_.load())
    {
        return md_RETURN_REPEAT_FAILED;
    }

    // #2 udp socket handle
    struct sockaddr_in local_addr;
    local_addr.sin_family      = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port        = htons(f_local_port);

    udp_sock_fd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (udp_sock_fd_ < 0)
    {
        perror("udp socket");
        exit(1);
    }
#ifdef __QNX_OS__
    // #2.2 Set info
    // struct ifreq ifopt;
    // strncpy(ifopt.ifr_name, "vlan4", IFNAMSIZ); // vlan13
    // if (setsockopt(udp_sock_fd_, SOL_SOCKET, SO_BINDTODEVICE, (char *)&ifopt,
    //                sizeof(ifopt)) < 0)
    // {
    //     perror("udp setsockopt");
    //     exit(1);
    // }
#endif
    // #2.2 bind local addr
    if (bind(udp_sock_fd_, (struct sockaddr *)&local_addr, sizeof(local_addr)) < 0)
    {
        perror("bind local address error");
        exit(1);
    }

    // #2.2 socket serv info
    memset(&udp_addr_serv_, 0, sizeof(udp_addr_serv_));
    udp_addr_serv_.sin_family      = AF_INET;
    udp_addr_serv_.sin_addr.s_addr = inet_addr(f_target_ipaddr.c_str());
    udp_addr_serv_.sin_port        = htons(f_target_port);

    inited_ = true;              // init flag
    retVal  = md_RETURN_SUCCESS; // return

    std::this_thread::sleep_for(std::chrono::seconds(1));

    return retVal;
}
/**
 * @brief 接收处理线程资源
 *
 * @return int
 */
int UDPDrive::RecvInit(uint16_t f_modid, RecvCallback_t &f_func)
{
    std::lock_guard<std::mutex> lock(data_mutex_);
    if (recv_run_ == false)
    {
        recv_run_               = true;
        recv_thread_            = std::thread(&UDPDrive::RecvProcessing, this);
        std::string thread_name = name + "_udpr_th";
        pthread_setname_np(recv_thread_.native_handle(), thread_name.c_str());
        recv_thread_.detach();
    }
    RecvInfo recv_info(f_func);
    recv_map_.emplace(f_modid, recv_info);
    return md_RETURN_SUCCESS;
}
/**
 *
 */
int UDPDrive::UpdataSendData(uint16_t f_modid, const uint8_t &f_Data_pui8,
                             uint16_t f_DataLength_ui16)
{
    std::lock_guard<std::mutex> lock(data_mutex_);

    auto it = send_map_.find(f_modid);
    if (it != send_map_.end())
    {
        // 更新数据
        it->second.data.assign(&f_Data_pui8, &f_Data_pui8 + f_DataLength_ui16);
        return md_RETURN_SUCCESS;
    }
    else
    {
        return md_RETURN_NOT_FOUND; // 未找到对应的 modid
    }
}

/**
 * @brief 发送处理线程资源
 *
 * @return int
 */
int UDPDrive::SendInit(uint16_t f_modid, uint16_t f_cycle_ms)
{
    std::lock_guard<std::mutex> lock(data_mutex_);
    if (send_run_ == false)
    {
        send_run_               = true;
        send_thread_            = std::thread(&UDPDrive::SendProcessing, this);
        std::string thread_name = name + "_udpt_th";
        pthread_setname_np(send_thread_.native_handle(), thread_name.c_str());
        send_thread_.detach();
    }
    std::vector<uint8_t> buff_data_;
    SendInfo send_info(f_cycle_ms, buff_data_);
    send_map_.emplace(f_modid, send_info);
    return md_RETURN_SUCCESS;
}
/**
 * @brief 接收处理函数
 *
 * @return int
 */
int UDPDrive::RecvProcessing(void)
{
    uint8_t buffer[1024]; // 预定义的缓冲区大小
    while (recv_run_)
    {
        ssize_t recv_len =
            recvfrom(udp_sock_fd_, buffer, sizeof(buffer), 0, nullptr, nullptr);
        if (recv_len > 0)
        {
            // 提取 modid（前两个字节）
            uint16_t modid = buffer[0];

            auto it = recv_map_.find(modid);
            if (it != recv_map_.end())
            {
                // 调用注册的回调函数
                RecvCallback_t &callback = it->second.callback;
                callback(buffer, static_cast<uint16_t>(recv_len));
            }
            else
            {
                // 处理未注册的 modid
            }
        }
    }
    return md_RETURN_SUCCESS;
}

/**
 * @brief 发送处理函数
 *
 * @return int
 */
int UDPDrive::SendProcessing()
{
    while (send_run_)
    {
        auto current_time = std::chrono::steady_clock::now();

        // 遍历 send_map_，发送每个 modid 对应的数据
        {
            std::lock_guard<std::mutex> lock(data_mutex_); // 确保线程安全
            for (auto &entry : send_map_)
            {
                const SendInfo &send_info = entry.second;

                // 判断是否满足发送周期
                if (current_time >=
                    send_info.timestamp + std::chrono::milliseconds(send_info.cycle_ms))
                {
                    // 发送数据
                    ssize_t sent_bytes = sendto(
                        udp_sock_fd_, send_info.data.data(), send_info.data.size(), 0,
                        (struct sockaddr *)&udp_addr_serv_, sizeof(udp_addr_serv_));
                    if (sent_bytes < 0)
                    {
                        perror("sendto failed");
                    }

                    // 更新发送时间戳
                    send_map_[entry.first].timestamp = current_time;
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // 1毫秒的颗粒度
    }
    return md_RETURN_SUCCESS;
}

}; // namespace middleware