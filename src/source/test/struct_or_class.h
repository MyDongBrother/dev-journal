/**
 * @file struct_or_class.h
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
struct MyStruct
{
    int a; // 默认 public
};

class MyClass
{
    int a; // 默认 private
};
struct BaseStruct
{
  public:
    int a;
};
class BaseClass
{
  public:
    int a;
};

struct DerivedStruct : BaseStruct
{
}; // 默认 public 继承
class DerivedClass : BaseClass
{
}; // 默认 private 继承
