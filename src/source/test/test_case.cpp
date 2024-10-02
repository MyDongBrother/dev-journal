#include "test_case.h"
#include "static.h"

namespace uss_source
{
TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    int run_value = StaticDemo::static_a;
    std::cout << "exp::100   real:" << run_value << std::endl;
    StaticDemo::static_a = 10;
    run_value            = StaticDemo::static_a;
    std::cout << "exp::10   real:" << run_value << std::endl;
    run_value = StaticDemo::getValueA();
    std::cout << "exp::10   real:" << run_value << std::endl;
    exit(1);
}

} // namespace uss_source
