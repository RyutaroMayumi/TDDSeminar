cmake_minimum_required(VERSION 2.8)

# set runtime directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# setup google test
find_package(GTest REQUIRED)

# set test target
add_executable(Test fizzbuzz_test.cpp)
target_link_libraries(Test
  FizzBuzz
  pthread
  GTest::GTest
  GTest::Main   # GTest::Mainをリンクすると自分でmain関数を書く必要がなくなる
)
