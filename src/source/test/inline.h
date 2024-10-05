/**
 * @file inline.h
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

// 1.宏函数，内联函数与普通函数
// 宏函数和内联函数都是将函数里面的内容替换调用函数处
// 但是宏函数更偏重替换
#define SQUARE(x) (x * x)
// 内联函数的更偏重函数
inline int square(int x) { return x * x; }

// 2.复杂的内联函数,不会被编译器当作内联函数来处理
// 尝试将复杂数列计算的函数定义为 inline
inline long long complexSequence(int n)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        int result = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (i % 2 == 0)
            {
                result += complexSequence(i - 1) * 2; // 递归调用
            }
            else
            {
                result += complexSequence(i - 2) + 3; // 递归调用
            }
        }
        return result; // 计算结果
    }
}

class InlineDemoBase
{
  public:
    inline virtual void base() { return; }
};

class InlineDemo : public InlineDemoBase
{
  private:
  public:
    // 3.在类声明中定义的函数，除了虚函数的其他函数都会自动隐式地当成内联函数。
    long long factorial(int n)
    {
        if (n <= 0)
        {
            return 1; // 边界条件
        }
        else
        {
            return n * factorial(n - 1); // 递归
        }
    };
    // 与类内声明 factorial 做对比,除函数名以外都相同
    long long outline_factorial(int n);
    // 与类内声明 factorial 做对比,添加了inline
    inline long long inline_factorial(int n);

    long long inlineDemo(int n);
};