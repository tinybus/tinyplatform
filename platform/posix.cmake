cmake_minimum_required(VERSION 3.20)

# "tb_interface" is a source-less library that encapsulates all the global
# compiler options needed by all source files. All zephyr libraries, including
# the library named "tb" link with this library to obtain these flags.
# https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#interface-libraries
add_library(tinylibs_interface INTERFACE)
tiny_library_named(tinylibs)
tiny_include_directories(${TINYPLATFORM_DIR}/include)
add_subdirectory(${TINYPLATFORM_DIR}/src)

add_executable(app ${CMAKE_CURRENT_SOURCE_DIR}/platform/empty_file.c)
target_link_libraries(app PUBLIC tinylibs)
