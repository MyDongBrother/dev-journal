#include "test_case.h"
#pragma pack(push) // 保存当前的对齐状态
#pragma pack(1)    // 设置为 4 字节对齐

struct test_1byte
{
    char m1;   // 1 字节
    double m4; // 8 字节（可能会有填充）
    int m3;    // 4 字节
};
#pragma pack(4) // 设置为 4 字节对齐

struct test_4byte
{
    char m1;   // 4 字节
    double m4; // 8 字节（可能会有填充）
    int m3;    // 4 字节
};

#pragma pack(pop) // 恢复之前的对齐状态
struct test_default
{
    char m1;   // 8 字节
    double m4; // 8 字节（可能会有填充）
    int m3;    // 8 字节
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
    std::cout << "Size of test_1byte: " << sizeof(test_1byte) << " bytes" << std::endl;
    std::cout << "Size of test_4byte: " << sizeof(test_4byte) << " bytes" << std::endl;
    std::cout << "Size of test_default: " << sizeof(test_default) << " bytes"
              << std::endl;
    exit(1);
}
} // namespace uss_source
