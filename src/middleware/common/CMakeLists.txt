file(GLOB_RECURSE module_header *.h)

source_group_by_dir(module_header ${CMAKE_CURRENT_SOURCE_DIR})

install(FILES ${module_header} DESTINATION include)
