add_subdirectory(./test)
add_subdirectory(./drive)

file(GLOB_RECURSE source_SRCS *.cpp)

include_directories(./)

add_library(source SHARED ${source_SRCS})

target_link_libraries(source -Wl,--start-group source_test_static
                      source_drive_static -Wl,--end-group)

install(TARGETS source DESTINATION ${CMAKE_INSTALL_LIBDIR})
