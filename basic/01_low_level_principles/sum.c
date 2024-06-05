/**
 * @file 01_vas.cpp
 * @brief C++基础课程\01 深入学习C++语言先要练好的内功\掌握进程虚拟地址空间区域划分_ev
 * @author jiandong.liu (jiandong_liu@outlook.com)
 * @version 0.1
 * @date 2024-06-04
 *
 * @copyright Copyright (c) 2024 JiandongLiu56
 *
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-06-04 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */

int sum(int *a, int n)
{
    int i, s = 0;
    for (i = 0; i < n; i++)
    {
        s += a[i];
    }
    return s;
}