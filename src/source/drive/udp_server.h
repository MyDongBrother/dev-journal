#include "udp/udp_driver.h"
#include <iostream>
#include <thread>
#include <vector>

class UDPTestServer
{
  public:
    UDPTestServer(const std::string &client_ip, uint32_t server_port, uint32_t local_port)
        : client_ip_(client_ip),
          server_port_(server_port),
          local_port_(local_port),
          udp_server_("server")
    {
    }

    bool init()
    {
        // 初始化服务器的 UDP 驱动
        if (udp_server_.Init(client_ip_, server_port_, local_port_) != md_RETURN_SUCCESS)
        {
            std::cerr << "Failed to initialize UDP server." << std::endl;
            return false;
        }

        // 注册接收回调
        middleware::RecvCallback_t server_recv_callback = ServerRecvCallback;
        udp_server_.RecvInit(2, server_recv_callback);
        udp_server_.SendInit(1, 1000);

        return true;
    }

    void run()
    {
        static uint8_t server_count = 0;
        while (1)
        {
            // 模拟发送数据
            server_count++;
            std::vector<uint8_t> send_data = {1, 0x06, 0x07, server_count};
            udp_server_.UpdataSendData(1, send_data[0], send_data.size());
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

  private:
    std::string client_ip_;
    uint32_t server_port_;
    uint32_t local_port_;
    middleware::UDPDrive udp_server_;

    // 接收回调函数
    static void ServerRecvCallback(const uint8_t *data, uint16_t length)
    {
        std::cout << "Server received data (length " << length << "): ";
        for (int i = 0; i < length; ++i)
        {
            std::cout << std::hex << static_cast<int>(data[i]) << " ";
        }
        std::cout << std::dec << std::endl;
    }
};