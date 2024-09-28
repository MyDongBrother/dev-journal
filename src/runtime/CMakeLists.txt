file(GLOB_RECURSE runtime_SRCS *.cpp)

include_directories(./)

add_library(runtime SHARED ${runtime_SRCS})

target_link_libraries(runtime -Wl,--start-group -Wl,--end-group)

install(TARGETS runtime DESTINATION ${CMAKE_INSTALL_LIBDIR})
