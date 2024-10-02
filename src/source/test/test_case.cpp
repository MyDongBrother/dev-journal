#include "test_case.h"
#include "const.h"

namespace uss_source
{

const int const_global = 3;

// #3.4 const不能修饰全局函数
// int getConstGlobal()const { return const_global; };

const int const_A = 3;
int value_A       = 3;

// #6.0 const修饰函数返回值
// #6.1 const修饰返回常数
// #6.1.2 主要目的是为了返回值不被修改,比如返回一个引用或指针时
const int getConstA() { return const_A; };
// #6.1.2.3 返回一个非const修饰的也是一样
// const int getConstA() { return value_A; };
// #6.1.2.4 并没有一个int getValueC()作为重载,因为返回值是不作为函数签名的
// int getValueA() { return value_A; };

const int const_B = 3;
int value_B       = 3;
// #6.2 const修饰返回指针变量
// #6.2.1 const int * 表示指向常量的指针
const int *getConst_Int_ptr_B() { return &const_B; };
// #6.2.2 int const *等同const int *
int const *getInt_Const_Ptr_B() { return &const_B; };
// #6.3 int * const表示常量指针
int *const getInt_Ptr_Const_B()
{
    int *const const_b_ptr = &value_B;
    return const_b_ptr;
};
// #6.4 const int *const 表示指向常量的常量指针
// #无论是该指针还是指向的值都不可以被修改
const int *const getConst_Int_Ptr_Const_B()
{
    int *const const_b_ptr = &value_B;
    return const_b_ptr;
};

const int const_C = 3;
int value_C       = 3;

// #6.5 const int& 表示常量引用
const int &getConst_Int_Ref_C() { return value_C; };
// #6.5.2  int& const 是语法错误的，因为引用一旦绑定到某个对象，就不能再改变
// int &const getInt_Ref_Const_C() { return value_C; };

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

    const int *run_const_b = getInt_Const_Ptr_B();
    int *run_Value_b       = &run_Value_a;
    // #6.2.3 指向常量的指针的值不可以修改
    // *run_Value_b           = 9;
    // #6.2.4 指向常量的指针可以被修改
    run_const_b = run_Value_b;

    int *const run_const_ptr_b = getInt_Ptr_Const_B();
    int *run_Value_ptr_b       = &run_Value_a;
    // #6.3.1 常量指针的值是可以被修改的
    *run_const_ptr_b = 9;
    // #6.2.4 常量指针不可以被修改
    // run_const_ptr_b = run_Value_ptr_b;

    const int &run_Value_c = getConst_Int_Ref_C();
    // 6.5.1 不能修改常量引用引用的值
    // run_Value_c            = 100;
}

} // namespace uss_source
