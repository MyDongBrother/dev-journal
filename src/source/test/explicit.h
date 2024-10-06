/**
 * @file explicit.h
 * @brief
 * @author jiandong.liu (jiandong.liu@outlook.com)
 * @version 0.1
 * @date 2024-10-06
 *
 * @copyright Copyright (c) 2024 jiandong.liu
 *
 * @par Change Log:
 * <table>
 * <tr><th>Date       <th>Version  <th>Author       <th>Description
 * <tr><td>2024-10-06 <td>1.0      <td>jiandong.liu     <td>first version
 * </table>
 */

struct noneExplicitDemo
{
    int value;
    noneExplicitDemo(int val) : value(val) {}
    operator bool() const { return value != 0; }
};

struct explicitDemo
{
    int value;
    explicit explicitDemo(int val) : value(val) {}
    explicit operator bool() const { return value != 0; }
};
