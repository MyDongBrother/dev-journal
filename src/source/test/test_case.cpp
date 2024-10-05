#include "test_case.h"
#include "struct_or_class.h"

namespace uss_source
{

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    MyStruct my_struct;
    my_struct.a = 0;
    MyClass my_class;
    // my_class.a = 0;
    DerivedStruct derived_struct;
    derived_struct.a = 0;
    DerivedClass derived_class;
    // derived_class.a = 0;
}
} // namespace uss_source
