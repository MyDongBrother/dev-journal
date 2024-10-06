#pragma once
#include "run_contex.h"
#include <memory>
#include "c_oop.h"

namespace uss_source
{

class TestCase
{
  public:
    // 构造函数
    TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex);
    ~TestCase() = default;

    void Init();
    void Run();

  private:
    std::shared_ptr<runcontex::RunContex> runcontex_;
    Shape *shape;
    Circle *circle;
};
} // namespace uss_source
