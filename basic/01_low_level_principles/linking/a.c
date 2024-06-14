/**
 * @file a.c
 * @brief
 * @author jiandong.liu (jiandong_liu@outlook.com)
 * @version 0.1
 * @date 2024-06-14
 *
 * @copyright Copyright (c) 2024 JiandongLiu
 *
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-06-14 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */

extern int shared;

int main()
{
    int a        = 100;
    static int b = 0;
    swap(&a, &shared);
}