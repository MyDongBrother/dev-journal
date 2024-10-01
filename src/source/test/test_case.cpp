#include "test_case.h"
#include "const.h"

namespace uss_source
{

const int const_A = 3;
int value_A       = 3;
const int const_C = 3;

// #3.4 const不能修饰全局函数
// int getConstC()const { return const_C; };

// #6.0 const修饰函数返回值
// #6.1 const修饰返回常数
// #6.1.2 主要目的是为了返回值不被修改,比如返回一个引用或指针时
const int getConstA() { return const_A; };
// #6.1.2.3 返回一个非const修饰的也是一样
// const int getConstA() { return value_A; };
// #6.1.2.4 并没有一个int getValueC()作为重载,因为返回值是不作为函数签名的
// int getValueC() { return value_c; };

// #6.2 const修饰返回指针变量
// const int *getConstA_p() { return &const_A; };
// int const *getConstA_p() { return &const_A; };
// int *getConstA_p() { return &const_A; };
// int *const getConstA_pp()
// {
//     const int *const_A_p = &const_A;
//     return const_A_p;
// };

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    ConstDemo const_class_a(5, 0);

    // #1.2.4 打印的值为0 等于初始化列表的值
    std::cout << const_class_a.getValueB() << std::endl;
    // #1.2.4.1 为什么常成员变量可以被修改?
    // #1.2.4.2 百度的结果:const修饰的全局变量是保存在.rodata段
    // #1.2.4.3 const修饰的局部变量是保存在栈上的
    // #1.2.4.4 常成员变量是随着对象存储的,所以堆,栈 数据段 .bss段都可能

    // #5.0 const可以修饰兑现,称为常对象
    const ConstDemo const_class;
    // #5.1 常对象只能调用常成员函数
    const_class.getValueAsumC();
    // #5.2.1 常对象不能调用普通的成员函数
    // const_class.getValueBsumC();
    // #5.3.1 普通对象可以调用常成员函数
    const_class_a.getValueBsumC_const();

    // #6.1.2.1 获取了const返回值依然可以修改
    // #6.1.2.2 该函数返回值 const 可有可无,没实际作用
    int run_Value_a = getConstA();
    run_Value_a     = 8;
}

} // namespace uss_source
