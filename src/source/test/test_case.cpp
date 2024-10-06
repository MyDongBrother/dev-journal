#include "test_case.h"
#include "explicit.h"

namespace uss_source
{
void doNoneExplicitDemo(noneExplicitDemo demo) {}
void doExplicitDemo(explicitDemo demo) {}
TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    // 直接初始化
    noneExplicitDemo none_explicit_a(10);
    explicitDemo explicit_a(10);

    // 复制初始化
    noneExplicitDemo none_explicit_b = 10;
    // explicitDemo explicit_b          = 10;

    // 直接列表初始化
    noneExplicitDemo none_explicit_c{10};
    explicitDemo explicit_c{10};

    // 复制列表初始化
    // noneExplicitDemo none_explicit_c = {10};
    // explicitDemo explicit_c          = {10};

    // 显式转化
    noneExplicitDemo none_explicit_d = (noneExplicitDemo)10;
    explicitDemo explicit_d          = (explicitDemo)10;

    // 隐式转化
    doNoneExplicitDemo(10);
    // doExplicitDemo(10);

    // 隐式转化,但是 explicitDemo 按语境转化
    if (none_explicit_a)
        ;
    if (explicit_a)
        ;

    // 隐式转化,但是 explicitDemo 按语境转化
    bool bool_buff(none_explicit_a);
    bool bool_buff_explicit(explicit_a);

    // 隐式转化
    bool_buff = none_explicit_a;
    // bool_buff_explicit = explicit_a;

    // 显式转化
    bool_buff          = static_cast<bool>(none_explicit_a);
    bool_buff_explicit = static_cast<bool>(explicit_a);

    exit(1);
}
} // namespace uss_source
