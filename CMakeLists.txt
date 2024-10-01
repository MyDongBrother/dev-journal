cmake_minimum_required(VERSION 3.7)
include(cmake/utils.cmake)
project(${project_name})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    message("Debug version")
    add_definitions(-D__DEBUG__)
    set(DEBUG TRUE)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Test")
    message("Test version")
    add_definitions(-D__TEST__)
    set(TEST TRUE)
else()
    message("Release version")
    add_definitions(-D__RELEASE__)
    set(RELEASE TRUE)
endif()



# C++ FLAGS DEBUG
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
# C++ FLAGS RELEASE -O3 no gdb
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# C FLAGS DEBUG
set(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
# C FLAGS RELEASE no gdb
set(CMAKE_C_FLAGS_RELEASE "$ENV{CXXFLAGS} -O0 -Wall")
# C Flasg
set(C_FLAGS -fPIC -Werror=return-type -Wno-unused-parameter -rdynamic)
string(REPLACE ";" " " CMAKE_C_FLAGS "${C_FLAGS}")
# C++ FLAGS
set(CXX_FLAGS
    -std=c++14
    -fPIC
    -DVALGRIND
    -DCHECK_PTHREAD_RETURN_VALUE
    -D_FILE_OFFSET_BITS=64
    -Wall
    -Wextra
    -Werror=return-type
    -Wno-unused-parameter
    -Wold-style-cast
    -Woverloaded-virtual
    -Wpointer-arith
    -Wwrite-strings
    -MMD
    -rdynamic
    -Wno-error=deprecated-declarations
    -Wno-deprecated-declarations
    -Wno-sign-conversion
    -Wno-sign-compare
    # -fsanitize=address
)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
set(THIRD_PARTY_LIB pthread ${LOG_LIB})

# OutPut Dir
set(OUTPUT_ROOT ${PROJECT_SOURCE_DIR}/output)

include_directories(${PROJECT_SOURCE_DIR}/src/main)
include_directories(${PROJECT_SOURCE_DIR}/src/runtime)
include_directories(${PROJECT_SOURCE_DIR}/src/source)

add_subdirectory(src/main)
add_subdirectory(src/runtime)
add_subdirectory(src/source)
