cmake_minimum_required(VERSION 2.8)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
enable_testing()
add_test(NAME MyProject COMMAND Test)
