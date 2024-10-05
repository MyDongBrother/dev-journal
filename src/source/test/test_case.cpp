#include "test_case.h"

namespace uss_source
{

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    int arr[10];
    int *ptr = arr;

    std::cout << "Size of arr: " << sizeof(arr) << " bytes" << std::endl;
    std::cout << "Size of arr[10]: " << sizeof(arr[10]) << " bytes" << std::endl;
    std::cout << "Size of pointer: " << sizeof(ptr) << " bytes" << std::endl;
    exit(1);
}
} // namespace uss_source
