/**
 * @file source_base.h
 * @brief 基类，所有的 source 将作为 RunContex 的输入
 *
 * 该类负责管理 source 数据，并确保每一个 source 都能够作为 `RunContex`
 * 的输入。source 对象负责为运行上下文提供必要的数据或状态，`RunContex`
 * 将根据这些输入执行相应的逻辑。
 *
 * @note 所有的 source 都会成为 `runcontex::RunContex` 的输入，确保运行时的
 * 数据或状态的一致性。
 * @author jiandong.liu (jiandong_liu@forvision.com)
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024 forvision
 *
 * @par Change Log:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-10-08 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */
#pragma once
#include "run_contex.h"
#include <cassert>
#include <memory>

namespace uss_source
{

class SourceBase
{
  public:
    /**
     * @brief 构造函数，初始化 source 并将其作为 RunContex 的输入
     *
     * 此构造函数需要传入一个指向 `runcontex::RunContex` 实例的共享指针，
     * 该指针所指的 `RunContex` 将会接收该 source 作为输入。
     *
     * @param f_runcontex 指向 `RunContex` 对象的共享指针。
     *
     * @note 该构造函数保证所有的 source 都将作为 `RunContex` 的输入。
     */
    explicit SourceBase(std::shared_ptr<runcontex::RunContex> f_runcontex)
        : runcontex_(std::move(f_runcontex))
    {
        // 确保传入的运行上下文有效
        assert(runcontex_ &&
               "RunContex cannot be null! All sources must originate from a valid "
               "RunContex.");
    }

    virtual int Init()    = 0;
    virtual int Run()     = 0;
    virtual ~SourceBase() = default;
    ///! RunContex 实例，将接收 source 作为输入
    std::shared_ptr<runcontex::RunContex> runcontex_;
};

class SourceManager
{
  public:
    explicit SourceManager(std::shared_ptr<runcontex::RunContex> f_runcontex);
    int Init();
    int Run();

  private:
    std::shared_ptr<uss_source::SourceBase> sources_;
};

} // namespace uss_source
