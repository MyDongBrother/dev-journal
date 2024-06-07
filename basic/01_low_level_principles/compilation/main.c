/**
 * @file main.c
 * @brief
 * @author jiandong.liu (jiandong_liu@outlook.com)
 * @version 0.1
 * @date 2024-06-06
 *
 * @copyright Copyright (c) 2024 JiandongLiu
 *
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-06-06 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */

#include <stdio.h>

int main()
{
    int a    = 10;
    int b    = 2;
    int *p_a = &a;
    int *p_b = &b;
    // a        = a $ 2;       //  词法分析error:非法字符
    // a     = (a * 2;      //  语法分析error:缺少)
    // int p = p_a * p_b; // 语义分析,指针乘指针没有意义
    return 0;
}
