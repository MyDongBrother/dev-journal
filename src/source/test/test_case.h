#pragma once
#include "run_contex.h"
#include "source_base.h"
#include <memory>

namespace uss_source
{

class TestCase : public SourceBase
{
  public:
    // 构造函数
    explicit TestCase(std::shared_ptr<runcontex::RunContex> f_runcontex);
    ~TestCase() = default;

    int Init();
    int Run();

  private:
    std::shared_ptr<runcontex::RunContex> runcontex_;
};
} // namespace uss_source
