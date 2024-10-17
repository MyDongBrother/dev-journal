#pragma once
#include "run_contex.h"
#include "source_base.h"
#include <memory>

namespace uss_source
{

class Drive : public SourceBase
{
  public:
    // 构造函数
    explicit Drive(std::shared_ptr<runcontex::RunContex> f_runcontex);
    ~Drive() = default;

    int Init();
    int Run();

  private:
    std::shared_ptr<runcontex::RunContex> runcontex_;
};
} // namespace uss_source
