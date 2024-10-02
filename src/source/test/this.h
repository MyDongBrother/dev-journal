/**
 * @file this.h
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

class ThisDemo
{
  private:
    int a;
    const int b = 1;

  public:
    ThisDemo *next;
    int value;
    ThisDemo(int f_value) : value(f_value) { next = nullptr; }
    // 显式引用场景一:链式调用
    ThisDemo &setA(int a)
    {
        // 这里为了凸显this的作用,采用
        // 成员函数的形参和成员变量重名方式,这是不规范的
        this->a = a;
        return *this;
    }

    int sumB() { return (a + b); }

    // 显式引用场景二:在重载操作符时，显式使用 this 指针
    // 避免对象自我赋值的情况，防止未定义行为或效率问题。
    ThisDemo &operator=(const ThisDemo &other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->value = other.value;
        return *this;
    }

    // 显式引用场景三:复杂数据结构,用于递归或迭代访问
    void cumsum(int &result)
    {
        result += value;
        if (this->next != nullptr)
        {
            this->next->cumsum(result);
        }
    }
};
