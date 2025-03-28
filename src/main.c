
#include "stdio.h"
#include "mymath_lib.h"
#include "mymathio.h"

// 这里没有包含mymath.h,而是在mymathio.h中定义了a_type
// 但是依旧可以声明到a
extern a_type a;

int main()
{
    int num = sum();
    printf("num = %d\n", num);
    // 更有趣的是：mymath.h定义的a_type是没有成员num3的
    // 这里打印的结果实际是b.num1 = 5
    printf("a = %d\n", a.num3);
    while (1)
    {
        /* code */
    }

    return 0;
}
