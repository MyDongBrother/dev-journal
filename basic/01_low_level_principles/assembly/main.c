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
#include "stdio.h"

extern int sum2(int a, int b);

int sum(int a, int b) { return a + b; }

int gdata1 = 10;
int gdata2 = 0;
int gdata3;

static int gdata4 = 11;
static int gdata5 = 0;
static int gdata6;

extern int gdata7;

int *gdata8  = &gdata1;
int *gdata9  = &gdata7;
int *gdata10 = &gdata3;

char array[12] = "hello world";

int main()
{
    int a = 12;
    int b = 0;
    int c;

    static int d = 13;
    static int e = 0;
    static int f;

    b = sum(a, b);
    e = sum2(d, e);

    printf("gdata1:%d\n", gdata1);
    printf("gdata2:%d\n", gdata2);
    printf("gdata3:%d\n", gdata3);
    printf("gdata4:%d\n", gdata4);
    printf("gdata5:%d\n", gdata5);
    printf("gdata6:%d\n", gdata6);
    printf("gdata7:%d\n", gdata7);
    printf("gdata8:%d\n", *gdata8);
    printf("gdata9:%d\n", *gdata9);
    printf("gdata10:%d\n", *gdata10);
    printf("a:%d\n", a);
    printf("b:%d\n", b);
    printf("c:%d\n", c);
    printf("d:%d\n", d);
    printf("e:%d\n", e);
    printf("f:%d\n", f);
    printf("%s\n", array);
    return 0;
}