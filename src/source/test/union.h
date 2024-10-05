/**
 * @file union.h
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

union UnionTest_init_i {
    UnionTest_init_i() : i(10) {};
    int i;
    long d;
};

union UnionTest_init_d {
    UnionTest_init_d() : d(10) {};
    int i;
    long d;
};

static union {
    int i;
    long d;
};

union union_test {
    int i;
    long d;
};