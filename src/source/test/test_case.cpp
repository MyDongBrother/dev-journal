#include "test_case.h"
#include "externc.h"

namespace uss_source
{

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run() { my_c_function(12); }
} // namespace uss_source
