set(static_middleware_udp_name middleware_udp_static)
set(dynamic_middleware_udp_name middleware_udp)

macro(source_group_by_dir all_files strip_path)

endmacro(source_group_by_dir)

file(GLOB_RECURSE module_header *.h)
source_group_by_dir(module_header ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE module_cxx "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
source_group_by_dir(module_cxx ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES ${module_header} ${module_cxx})

add_library(${static_middleware_udp_name} STATIC ${SOURCE_FILES})
add_library(${dynamic_middleware_udp_name} SHARED ${SOURCE_FILES})

install(TARGETS ${static_middleware_udp_name}
        DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(TARGETS ${dynamic_middleware_udp_name}
        DESTINATION ${CMAKE_INSTALL_LIBDIR})
