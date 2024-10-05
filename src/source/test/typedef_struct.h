/**
 * @file typedef_struct.c
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

// 定义一个结构体,函数竟然可以和结构体重名
struct Student
{
    int age;
};
#ifdef __cplusplus
extern "C"
{
#endif
    // 不使用typedef定义别名
    struct StudentNoneTypedef
    {
        int age;
    };

    // 使用typedef定义别名
    typedef struct Student_Typedef
    {
        int age;
    } StudentTypedef;

#ifdef __cplusplus
}
#endif