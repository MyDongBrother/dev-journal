/**
 * @file runtime.cpp
 * @brief
 * @author jiandong.liu (jiandong_liu@forvision.com)
 * @version 0.1
 * @date 2024-09-28
 *
 * @copyright Copyright (c) 2024 forvision
 *
 * @par Change Log:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-09-28 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */

#include "run_contex.h"
#include <unistd.h>

namespace runcontex
{

class RunContex::Impl
{
  public:
    Impl() {}
    void Init() {}
};

RunContex::RunContex() : pImpl_(std::make_unique<Impl>()) {}

RunContex::~RunContex() {}

int RunContex::Init()
{
    this->thread_run_ = true;
    // 主任务的线程资源
    thread_main_task_ = new std::thread(&RunContex::taskMainProcessing, this);
    pthread_setname_np(thread_main_task_->native_handle(), "fvmain_th");
    thread_main_task_->detach();
    // observer的线程资源
    thread_observer_task_ = new std::thread(&RunContex::taskObserverProcessing, this);
    pthread_setname_np(thread_observer_task_->native_handle(), "fvobs_th");
    thread_observer_task_->detach();
    return 0;
}
int RunContex::Start()
{
    this->uss_run_ = true;
    return 0;
}
int RunContex::Stop()
{
    this->uss_run_ = false;
    return 0;
}
int RunContex::Deinit()
{
    this->uss_run_    = false;
    this->thread_run_ = false;
    return 0;
}
int RunContex::Loop()
{
    while (thread_run_)
    {
        sleep(3600);
    }
    return 0;
}

void RunContex::setInputData() {}
void RunContex::setOutputData() {}
void RunContex::taskMain() { std::cout << "taskMain" << std::endl; }
void RunContex::taskMainProcessing()
{
    while (thread_run_)
    {
        if (uss_run_)
        {
            taskMain();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}
void RunContex::taskObserver() { std::cout << "taskObserver" << std::endl; }
void RunContex::taskObserverProcessing()
{
    while (thread_run_)
    {
        if (uss_run_)
        {
            taskObserver();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    }
}

int RunContex::SetTimeStampFunction(GetTimeStamp_t f_cb) { return 0; }
int RunContex::SetConfig(const uint8_t f_ConfigId_ui8, const uint8_t &f_Config_pui8,
                         const uint16_t f_ConfigLength_ui16)
{
    return 0;
}
int RunContex::GetConfig(const uint8_t f_ConfigId_ui8, uint8_t &f_Config_pui8,
                         const uint16_t f_ConfigLength_ui16)
{
    return 0;
}
int RunContex::SetInput(const uint8_t f_DataId_ui8, const uint8_t &f_Data_pui8,
                        const uint16_t f_DataLength_ui16)
{
    return 0;
}
int RunContex::GetOutput(const uint8_t f_DataId_ui8, uint8_t &f_Data_pui8,
                         const uint16_t f_DataLength_ui16)
{
    return 0;
}

} // namespace runcontex