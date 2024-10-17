set(static_source_drive_name source_drive_static)
set(dynamic_source_drive_name source_drive)

macro(source_group_by_dir all_files strip_path)

endmacro(source_group_by_dir)

file(GLOB_RECURSE module_header *.h)
source_group_by_dir(module_header ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE module_cxx "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
source_group_by_dir(module_cxx ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES ${module_header} ${module_cxx})

add_library(${static_source_drive_name} STATIC ${SOURCE_FILES})
add_library(${dynamic_source_drive_name} SHARED ${SOURCE_FILES})

install(TARGETS ${static_source_drive_name} DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(TARGETS ${dynamic_source_drive_name}
        DESTINATION ${CMAKE_INSTALL_LIBDIR})
