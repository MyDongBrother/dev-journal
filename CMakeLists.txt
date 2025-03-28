cmake_minimum_required(VERSION 3.10)
project(StaticExample)

# 设置源码路径
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 添加静态库 mymath_lib
add_library(mymath_lib STATIC
    ${SRC_DIR}/mymath/mymath.c
)

# 指定头文件路径（让 main.c 能找到 mymath_lib.h 和 mymath/mymath.h）
target_include_directories(mymath_lib PUBLIC
    ${SRC_DIR}
)

# 添加可执行文件
add_executable(SimpleCppProject
    ${SRC_DIR}/main.c
)

# 链接静态库到可执行文件
target_link_libraries(SimpleCppProject PRIVATE mymath_lib)