#include "test_case.h"

namespace uss_source
{

TestCase::TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : runcontex_(f_runcontex)
{
    // 创建 Shape 实例
    shape = Shape_new();
    // 创建 Circle 实例
    circle = Circle_new(5.0);
}
void TestCase::Init() {}
void TestCase::Run()
{
    // 输出: Drawing a shape.
    shape->draw(shape);
    // 输出: Drawing a circle with radius: 5.00.
    circle->base.draw((Shape *)circle);
    // 释放内存
    free(shape);
    free(circle);
    exit(1);
}
} // namespace uss_source
