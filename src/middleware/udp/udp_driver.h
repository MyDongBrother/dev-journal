/**
 * @file udp_driver.h
 * @brief
 * @author jiandong.liu (jiandong_liu@forvision.com)
 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024 forvision
 *
 * @par Change Log:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-10-16 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */
#pragma once
#include <atomic>
#include <string>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <functional>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <mutex>
#include <utility>

namespace middleware
{
/**
 * @brief UDP配置
 *
 */

#define md_RETURN_SUCCESS       (0)
#define md_RETURN_INIT_FAILED   (-1)
#define md_RETURN_REPEAT_FAILED (-2)
#define md_RETURN_NOT_FOUND     (-1)
#define md_RETURN_NOT_INITED    (-1)
#define md_RETURN_RUNMODE_ERROR (-3)
#define md_RETURN_CONFIG_ERROR  (-3)

#define md_MAX_BYTES_OF_RAW_DATA ((1024) * (4))

using RecvCallback_t =
    std::function<void(const uint8_t *f_Data_pui8, uint16_t f_DataLength_ui16)>;

// 定义发送信息的结构体
struct SendInfo
{
    uint16_t cycle_ms;                               // 发送周期（毫秒）
    std::chrono::steady_clock::time_point timestamp; // 上次发送的时间戳
    std::vector<uint8_t> data;                       // 要发送的数据

    // 默认构造函数
    SendInfo() : cycle_ms(0), timestamp(std::chrono::steady_clock::now()) {}

    // 可以添加构造函数以简化初始化
    SendInfo(uint16_t cycle, std::vector<uint8_t> &data_to_send)
        : cycle_ms(cycle), timestamp(std::chrono::steady_clock::now()), data(data_to_send)
    {
    }
};

// 定义接收信息的结构体
struct RecvInfo
{
    RecvCallback_t callback; // 接收回调函数

    // 可以添加构造函数以简化初始化
    RecvInfo(RecvCallback_t cb) : callback(cb) {}
};

class UDPDrive
{
  public:
    /**
     * @brief 构造
     *
     * @param f_name_str 目标设备的实体名 ex:matis_app matis_dev
     */
    UDPDrive(std::string f_name_str);
    std::string name;

    /**
     * @brief 析构,销毁所有申请的资源
     *
     */
    ~UDPDrive();
    /**
     * @brief 网络资源,由插件申请
     *
     * @param f_target_ipaddr
     * @param f_target_port
     * @param f_local_port
     * @return int
     */
    int Init(std::string f_target_ipaddr, uint32_t f_target_port, uint32_t f_local_port);

    /**
     * @brief 提供给需要的插件使用
     *
     * @param f_func
     * @return int
     */
    int RecvInit(uint16_t f_modid, RecvCallback_t &f_func);
    int SendInit(uint16_t f_modid, uint16_t f_cycle_ms);
    int UpdataSendData(uint16_t f_modid, const uint8_t &f_Data_pui8,
                       uint16_t f_DataLength_ui16);

  private:
    /**
     * @brief UDP资源
     *
     */
    std::atomic_bool inited_;
    int udp_sock_fd_;                  // socket fd
    struct sockaddr_in udp_addr_serv_; // sockaddr_serv

  private:
    /**
     * @brief 线程资源
     *
     */
    std::atomic_bool recv_run_; // run flag
    std::atomic_bool send_run_; // run flag
    std::thread recv_thread_;   // RxThread
    std::thread send_thread_;   // RxThread
    int RecvProcessing(void);
    int SendProcessing(void);

  private:
    /**
     * @brief 数据
     *
     */
    std::mutex data_mutex_;
    std::map<uint16_t, SendInfo> send_map_;
    std::unordered_map<uint16_t, RecvInfo> recv_map_;
};
}; // namespace middleware