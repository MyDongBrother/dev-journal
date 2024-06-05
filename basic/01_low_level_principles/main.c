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
int sum(int *a, int n);

int gdata1 = 10;
int gdata2 = 0;
int gdata3;

static int gdata4 = 11;
static int gdata5 = 0;
static int gdata6;

int array[2] = {1, 2};
int main()
{
    int a = 12;
    int b = 0;
    int c;

    static int e = 13;
    static int f = 0;
    static int g;

    int val = sum(array, 2);
    return 0;
}