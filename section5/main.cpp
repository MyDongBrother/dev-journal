#include <iostream>
#include <cstring>
using namespace std;

struct my_struct
{
    char name[12];
    char gender;
    int age;
} __attribute__((packed));

struct test_struct
{
    char name[12];
    char gender;
    int age;
};

int test_memory()
{
    const char *test_str = "this is a test";
    /**     字符格式显示
    (gdb) x/16cb test_str
    0x555555556004: 116 't' 104 'h' 105 'i' 115 's' 32 ' '  105 'i' 115 's' 32 ' '
    0x55555555600c: 97 'a'  32 ' '  116 't' 101 'e' 115 's' 116 't' 0 '\000'        32 ' '
     */

    int itest = 0x12345678;
    /**     机器是以小端的方式保存数据
    (gdb) x/4xb &itest
    0x7fffffffd604: 0x78    0x56    0x34    0x12
     */

    struct test_struct test;
    struct my_struct my_test;
    memset(&test, 0, sizeof(test));
    memset(&my_test, 0, sizeof(my_test));
    test.age    = 25;
    my_test.age = 25;
    strcpy(test.name, "SimpleSoft");
    strcpy(my_test.name, "SimpleSoft");
    test.gender    = 'm';
    my_test.gender = 'm';
    cout << test_str << " " << itest << endl;
    /**     test_struct是四字节对齐  test_struct是一字节对齐
    (gdb) x/20db &test
    0x7fffffffd630: 83      105     109     112     108     101     83      111
    0x7fffffffd638: 102     116     0       0       109     0       0       0
    0x7fffffffd640: 25      0       0       0
    (gdb) x/20db &my_test
    0x7fffffffd610: 83      105     109     112     108     101     83      111
    0x7fffffffd618: 102     116     0       0       109     25      0       0
    0x7fffffffd620: 0       0       0       0
    */

    memcpy(&my_test, &test, sizeof(test_struct));
    /**     使用memcpy后age的值是错误的，0x19000000 = 419430400
    (gdb) p my_test
    $7 = {
      name = "SimpleSoft\000",
      gender = 109 'm',
      age = 419430400
    }
    (gdb) x/20xb &my_test
    0x7fffffffd610: 0x53    0x69    0x6d    0x70    0x6c    0x65    0x53    0x6f
    0x7fffffffd618: 0x66    0x74    0x00    0x00    0x6d    0x00    0x00    0x00
    0x7fffffffd620: 0x19    0x00    0x00    0x00
     */
    return 0;
}

int main(int argc, char **argv)
{
    test_memory();

    return 0;
}
