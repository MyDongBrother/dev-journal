cmake_minimum_required(VERSION 3.7)
include(cmake/utils.cmake)
project(${project_name})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(${PLATFORM_QNX})
  message("QNX platform")
  add_definitions(-D__QNX_OS__)
  add_definitions(-D_QNX_SOURCE)
  set(QNX_OS TRUE)
else()
  message("LINUX platform")
  add_definitions(-D__LINUX_OS__)
  set(LINUX_OS TRUE)
endif()

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

if(${QNX_OS})
  # C Flasg
  set(C_FLAGS -fPIC -Werror=return-type -Wno-unused-parameter -rdynamic)
  string(REPLACE ";" " " CMAKE_C_FLAGS "${C_FLAGS}")
  # C++ FLAGS
  set(CXX_FLAGS -std=c++14 -fPIC -lsocket -pthread
                # -fsanitize=address
  )
  string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

else()
  # C Flasg
  set(C_FLAGS -fPIC -Werror=return-type -Wno-unused-parameter -rdynamic)
  string(REPLACE ";" " " CMAKE_C_FLAGS "${C_FLAGS}")
  set(CXX_FLAGS -std=c++14 -fPIC -g -O0
                # -fsanitize=address
  )
  string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
  set(THIRD_PARTY_LIB pthread ${LOG_LIB})
endif()

# OutPut Dir
set(OUTPUT_ROOT ${PROJECT_SOURCE_DIR}/output)

include_directories(${PROJECT_SOURCE_DIR}/src/main)
include_directories(${PROJECT_SOURCE_DIR}/src/middleware)
include_directories(${PROJECT_SOURCE_DIR}/src/runtime)
include_directories(${PROJECT_SOURCE_DIR}/src/source)

add_subdirectory(src/main)
add_subdirectory(src/middleware)
add_subdirectory(src/runtime)
add_subdirectory(src/source)
