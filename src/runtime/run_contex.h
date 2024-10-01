/**
 * @file runcontex.h
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
#pragma once
/*--------------------------------------------------------------------------*/
/*- include files                                                          -*/
/*--------------------------------------------------------------------------*/
#include <iostream>
#include <functional>
#include <thread>
#include <atomic>

namespace runcontex
{
using GetTimeStamp_t = std::function<uint64_t(void)>;
class RunContex
{
  public:
    RunContex();
    ~RunContex();
    int Init(void);
    int Start(void);
    int Stop(void);
    int Deinit(void);
    int Loop(void);

  public:
    int SetTimeStampFunction(GetTimeStamp_t f_cb);
    int SetConfig(const uint8_t f_ConfigId_ui8, const uint8_t &f_Config_pui8,
                  const uint16_t f_ConfigLength_ui16);
    int GetConfig(const uint8_t f_ConfigId_ui8, uint8_t &f_Config_pui8,
                  const uint16_t f_ConfigLength_ui16);
    int SetInput(const uint8_t f_DataId_ui8, const uint8_t &f_Data_pui8,
                 const uint16_t f_DataLength_ui16);
    int GetOutput(const uint8_t f_DataId_ui8, uint8_t &f_Data_pui8,
                  const uint16_t f_DataLength_ui16);

  private:
    void setInputData(void);
    void setOutputData(void);
    void taskMain(void);
    void taskMainProcessing(void);
    void taskObserver(void);
    void taskObserverProcessing(void);

  private:
    std::atomic<bool> thread_run_{};             // run flag
    std::atomic<bool> process_run_{};            // uss flag
    std::thread *thread_main_task_{nullptr};     //  main Task
    std::thread *thread_observer_task_{nullptr}; // observer Task
    GetTimeStamp_t time_stamp_;                  // time synchronization
    class Impl;
    std::unique_ptr<Impl> pImpl_;
};
} // namespace runcontex