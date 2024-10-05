#include "test_case.h"
#include <iostream>
#include <thread>
#include <chrono>

namespace uss_source
{

bool falg                   = false; // 不带 volatile 的变量
volatile bool volatile_flag = false; // 带 volatile 的变量

void worker()
{
    // 模拟一些工作
    std::this_thread::sleep_for(std::chrono::seconds(1));
    volatile_flag = true; // 修改带 volatile 的变量
    falg          = true; // 修改不带 volatile 的变量
}

void non_volatile_monitor()
{
    while (!falg) // 读取不带 volatile 的变量
    {
        // busy-waiting
    }
    std::cout << "f" << std::endl;
    exit(1);
}

void volatile_monitor()
{
    while (!volatile_flag) // 读取带 volatile 的变量
    {
        // busy-waiting
    }
    std::cout << "v" << std::endl;
    exit(1);
}

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init()
{
    std::thread t1(worker);
    std::thread t2(non_volatile_monitor);
    std::thread t3(volatile_monitor);

    t1.join();
    t2.join();
    t3.join();
}
void TestCase::Run() {}

} // namespace uss_source
