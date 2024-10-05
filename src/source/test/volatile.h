/**
 * @file volatile.h
 * @brief
 * @author jiandong.liu (jiandong.liu@outlook.com)
 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024 jiandong.liu
 *
 * @par Change Log:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-10-05 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */

class VolatileDemo
{
    void worker()
    {
        run_flag = true; // 修改 flag 的值
    }

    void monitor()
    {
        while (!flag)
        { // 检查 flag
          // busy-waiting
        }
        std::cout << "Monitor thread: flag is true!" << std::endl;
    }

  public:
    bool run_flag;
    volatile bool run_flag;
};