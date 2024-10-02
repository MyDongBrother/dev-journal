/**
 * @file static.h
 * @brief
 * @author jiandong.liu (jiandong.liu@outlook.com)
 * @version 0.1
 * @date 2024-10-02
 *
 * @copyright Copyright (c) 2024 jiandong.liu
 *
 * @par Change Log:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-10-02 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */

class StaticDemo
{
  private:
    int value_b;

  public:
    static int static_a;
    static int getValueA() { return static_a; }
    // 静态函数中不可以调用非静态成员对象
    // static int getValueAsumB() { return (value_a + value_b); }
};
// 静态成员变量必须且仅可以定义一次
int StaticDemo::static_a = 100;
