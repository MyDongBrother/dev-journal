#include "test_case.h"
#include "this.h"

namespace uss_source
{
TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    // 链式调用示例
    ThisDemo thisClass_A(1);
    int run_this_value = thisClass_A.setA(8).sumB();
    std::cout << run_this_value << std::endl;

    // 重载操作符示例
    ThisDemo thisClass_B(2);
    thisClass_B = thisClass_A;
    std::cout << thisClass_B.value << std::endl;

    // 递归示例
    int result       = 0;
    thisClass_B.next = &thisClass_A;
    thisClass_B.cumsum(result);
    std::cout << result << std::endl;

    exit(1);
}

} // namespace uss_source
