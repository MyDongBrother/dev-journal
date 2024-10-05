#include "test_case.h"
#include "inline.h"

namespace uss_source
{
TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    // 宏函数与内联函数调用示例,结果是不同的
    std::cout << "define fun:" << SQUARE(1 + 2) << std::endl;
    std::cout << "inline fun:" << square(1 + 2) << std::endl;

    exit(1);
}

} // namespace uss_source
