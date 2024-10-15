/**@mainpage   NIO_ALPS_DOM
 * <table>
 * <tr><th>Project  <td>run
 * <tr><th>Author   <td>jiandong.liu
 * <tr><th>Source
 *<td>https://gitlab1.forvision-tech.com/customer/nio/nt3/nt3_soc/-/tree/platform
 * </table>
 * @section   Description
 * -# main 主函数
 *
 * @section   GettingStarted
 * -# runtime: 运行调度
 *
 * @section   FirmwareUpdate
 * <table>
 * <tr><th>Date        <th>S_Version  <th>Author    <th>Description  </tr>
 * <tr><td>20240928    <td>platform1.0.0.0   <td>jiandong.liu  <td>创建初始版本
 * </tr>
 * </table>
 **********************************************************************************
 */

#include "run_contex.h"
#include <memory>
#ifdef __TEST__
#include "source_base.h"
#endif
/**
 * @brief 主函数，程序入口
 *
 * @param argc 命令行参数数量
 * @param argv 命令行参数数组
 * @return int 返回值
 */
int main(int argc, char *argv[])
{

    auto run_ctx = std::make_shared<runcontex::RunContex>();

    // #2 Init
    run_ctx->Init();
#ifdef __TEST__
    uss_source::SourceManager source_manager(run_ctx);
    source_manager.Init();
#endif

    // #3 Start
    run_ctx->Start();

#ifdef __TEST__
    auto test_func = [&] { source_manager.Run(); };
    std::thread(test_func).detach();
#endif

    //  run_ctx->Stop();

    //  run_ctx->Deinit();

    run_ctx->Loop();

    return 0;
}
