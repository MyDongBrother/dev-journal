#include "test_case.h"

namespace uss_source
{
TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : SourceBase(f_runcontex)
{
}
int TestCase::Init() { return 0; }
int TestCase::Run() { return 0; }
} // namespace uss_source
