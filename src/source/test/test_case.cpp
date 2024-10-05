#define NDEBUG
#include "test_case.h"
#include <cassert>

namespace uss_source
{

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    int p;
    std::cout << "Processing value: " << p << std::endl;
    assert(p == 0);
}

} // namespace uss_source
