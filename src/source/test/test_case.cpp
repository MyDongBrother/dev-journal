#include "test_case.h"
struct test_default
{
    unsigned int mode : 2;   // mode 占 2 位
    unsigned int status : 1; // status 占 1 位
    unsigned int error : 3;  // error 占 3 位
};
namespace uss_source
{

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
}
void TestCase::Init() {}
void TestCase::Run()
{
    test_default flags;
    flags.mode   = 4; // mode 占 2 位，因此最大值为 3（二进制11）
    flags.status = 2; // status 占 1 位，值为 1
    flags.error  = 9; // error 占 3 位，最大值为 7

    std::cout << "Mode: " << flags.mode << std::endl;
    std::cout << "Status: " << flags.status << std::endl;
    std::cout << "Error: " << flags.error << std::endl;
    std::cout << "Size of test_default: " << sizeof(test_default) << " bytes"
              << std::endl;
    exit(1);
}
} // namespace uss_source
