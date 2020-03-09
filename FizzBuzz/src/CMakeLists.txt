cmake_minimum_required(VERSION 2.8)
add_library(FizzBuzz STATIC fizzbuzz.c)

add_executable(Demo main.c)
target_link_libraries(Demo FizzBuzz)
