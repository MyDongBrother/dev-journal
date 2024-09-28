cmake_minimum_required(VERSION 2.8)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/internal_utils.cmake)

set(PROPERTY_FILE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/build.properties")
set(PROPERTY_FILE_LOCAL "${CMAKE_BINARY_DIR}/build.properties.local")

# load properties into ${PROPERTIES}
macro(READ_PROPERTIES PROPERTIES)
  if((NOT (EXISTS ${PROPERTY_FILE})) AND (NOT (EXISTS ${PROPERTY_FILE_LOCAL})))
    message(
      FATAL_ERROR
        "CONFIG FILE `${PROPERTY_FILE}` and `${PROPERTY_FILE_LOCAL}` not EXISTS"
    )
  endif()
  if(EXISTS ${PROPERTY_FILE})
    message(STATUS "READ CONFIG FROM FILE:${PROPERTY_FILE}")
    load_property(${PROPERTIES} ${PROPERTY_FILE})
  endif()
  if(EXISTS ${PROPERTY_FILE_LOCAL})
    message(STATUS "READ CONFIG FROM FILE:${PROPERTY_FILE_LOCAL}")
    load_property(${PROPERTIES} ${PROPERTY_FILE_LOCAL})
  endif()
endmacro()

# init build type
macro(INIT_TYPE PROPERTIES)
  map_get(${PROPERTIES} build_type build_type)
  if(${build_type} STREQUAL "debug")
    set(CMAKE_BUILD_TYPE Debug)
    message(STATUS "BUILD TYPE:debug")
    set(HOBOT_BUILD_DEBUG "TRUE")
  elseif(${build_type} STREQUAL "test")
    set(CMAKE_BUILD_TYPE Test)
    set(HOBOT_BUILD_DEBUG "TRUE")
    message(STATUS "BUILD TYPE:test")
  else()
    set(CMAKE_BUILD_TYPE Release)
    message(STATUS "BUILD TYPE:Release")
  endif()
endmacro()

# init platform info from ${PROPERTIES}
macro(INIT_PLATFORM_INFO PROPERTIES)
  map_get(${PROPERTIES} project_name project_name)
  map_get(${PROPERTIES} platform platform)
  map_get(${PROPERTIES} architecture architecture)
  if(${platform} STREQUAL "linux")
    set(PLATFORM_LINUX TRUE)
    set(CMAKE_SYSTEM_NAME Linux)
    map_get(${PROPERTIES} cmake_c_compiler C_COMPILER)
    map_get(${PROPERTIES} cmake_cxx_compiler CXX_COMPILER)
    map_get(${PROPERTIES} cmake_find_root_path FIND_ROOT_PATH)

    if(${C_COMPILER} STREQUAL "undefined")

    else()
      set(CMAKE_C_COMPILER ${C_COMPILER})
    endif()

    if(${CXX_COMPILER} STREQUAL "undefined")

    else()
      set(CMAKE_CXX_COMPILER ${CXX_COMPILER})
    endif()

    if(${FIND_ROOT_PATH} STREQUAL "undefined")

    elseif(NOT ${CMAKE_MAJOR_VERSION} LESS 3)
      set(CMAKE_FIND_ROOT_PATH ${FIND_ROOT_PATH})
      set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
      set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
      set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
      message("find root path: ${CMAKE_FIND_ROOT_PATH}")
    endif()
  else()
    message(
      FATAL_ERROR
        "platform `${platform}` not suppored, choose from [linux | android | win | mac]"
    )
  endif()
endmacro()

read_properties(properties)
init_type(properties)
init_platform_info(properties)
