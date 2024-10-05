#include "test_case.h"
#include "union.h"

namespace uss_source
{

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    UnionTest_init_i u_init_i;
    UnionTest_init_d u_init_d;
    union_test u_t;
    union {
        int i;
        long d;
    };

    union u_fun {
        int i;
        long d;
    };

    std::cout << u_init_i.i << std::endl; // 输出 UnionTest 联合的 10
    std::cout << u_init_i.d << std::endl; // 输出 UnionTest 联合的 10

    std::cout << u_init_d.i << std::endl; // 输出 UnionTest 联合的 10
    std::cout << u_init_d.d << std::endl; // 输出 UnionTest 联合的 10

    ::i = 20;
    ::d = 21;
    std::cout << ::i << std::endl; // 输出全局静态匿名联合的 20
    std::cout << ::d << std::endl; // 输出全局静态匿名联合的 20

    i = 30;
    d = 31;
    std::cout << i << std::endl; // 输出局部匿名联合的 30
    std::cout << d << std::endl; // 输出局部匿名联合的 30

    u_t.i = 40;
    u_t.d = 41;
    std::cout << u_t.i << std::endl; // 输出局部匿名联合的 30
    std::cout << u_t.d << std::endl; // 输出局部匿名联合的 30

    exit(1);
}
} // namespace uss_source
