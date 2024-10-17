#include "source_base.h"
#include "test/test_case.h"
#include "drive/drive.h"

namespace uss_source
{
SourceManager::SourceManager(std::shared_ptr<runcontex::RunContex> f_runcontex)
    : sources_(std::make_unique<uss_source::Drive>(
          f_runcontex)) // 使用 unique_ptr 存储单一实例
{
}

int SourceManager::Init()
{
    return sources_->Init(); // 调用子类的 Init 方法
}

int SourceManager::Run()
{
    return sources_->Run(); // 调用子类的 Run 方法
}

} // namespace uss_source
