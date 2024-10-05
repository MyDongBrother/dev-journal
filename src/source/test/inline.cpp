/**
 * @file inline.cpp
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

#include "inline.h"

long long InlineDemo::inlineDemo(int n)
{
    long long result = 0;
    // 通过查看汇编文件查看 @function 有三个
    result = square(n);
    result = complexSequence(n);
    result = factorial(n);
    result = outline_factorial(n);
    result = inline_factorial(n);
    return result;
}

long long InlineDemo::outline_factorial(int n)
{
    if (n <= 0)
    {
        return 1; // 边界条件
    }
    else
    {
        return n * outline_factorial(n - 1); // 递归
    }
};

inline long long InlineDemo::inline_factorial(int n)
{
    if (n <= 0)
    {
        return 1; // 边界条件
    }
    else
    {
        return n * inline_factorial(n - 1); // 递归
    }
};