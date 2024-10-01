/**
 * @file const.h
 * @brief
 * @author jiandong.liu (jiandong.liu@outlook.com)
 * @version 0.1
 * @date 2024-10-01
 *
 * @copyright Copyright (c) 2024 jiandong.liu
 *
 * @par Change Log:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-10-01 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */

class ConstDemo
{
  private:
    // #1.0 const修饰对象成员,称为常对象成员
    // #1.1 常成员对象可以使用初始化列表初始化
    const int value_a;
    // #1.2 常成员对象可以使用类内初始化
    const int value_b = 5;
    int value_c       = 6;

  public:
    // #1.1.2 常成员对象,使用初始化列表
    ConstDemo() : value_a(6) {};
    // #1.1.3 常成员对象,使用初始化列表
    ConstDemo(int f_a) : value_a(f_a) {};
    // #1.2.2 常成员对象,类内初始化后也可以使用初始化列表初始化
    ConstDemo(int f_a, int f_b) : value_a(f_a), value_b(f_b) {};
    // #1.2.3 用于验证类内初始化后也可以使用初始化列表初始化等于谁
    int getValueB() { return value_b; }

    // #3.0 const修饰成员函数,称为常成员函数
    // #3.1 可用于重载.原理:常成员函数的函数签名带有 const
    int getValueAsumC() const { return value_a + value_c; };

    // #3.2 特点:常成员函数中不能修改成员的值,否则会编译报错
    // int getValueAsumC() const
    // {
    //     value_c = 10;
    //     return value_a + value_c;
    // };

    // #3.3 普通成员函数,用于区分const修饰的常量成员函数getValueAsumC
    int getValueAsumC()
    {
        value_c = 10;
        return value_a + value_c;
    };

    // #5.2.2 普通成员函数,验证常对象不能调用普通的成员函数
    int getValueBsumC()
    {
        value_c = 10;
        return value_b + value_c;
    };

    // #5.3.2 常成员函数,验证普通对象不能调用常成员函数
    int getValueBsumC_const() const { return value_b + value_c; };
};