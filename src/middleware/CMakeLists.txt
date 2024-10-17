add_subdirectory(./udp)
add_subdirectory(./common)

file(GLOB_RECURSE middleware_SRCS *.cpp)

include_directories(./)

add_library(middleware SHARED ${middleware_SRCS})

target_link_libraries(middleware -Wl,--start-group middleware_udp_static
                      -Wl,--end-group)

install(TARGETS middleware DESTINATION ${CMAKE_INSTALL_LIBDIR})
