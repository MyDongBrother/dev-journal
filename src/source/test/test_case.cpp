#include "test_case.h"
#include "typedef_struct.h"

void Student() { std::cout << "A function with repeated names \"Student\"" << std::endl; }

namespace uss_source
{

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    StudentNoneTypedef me;
    StudentTypedef you;
    Student();
}
} // namespace uss_source
