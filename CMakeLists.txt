cmake_minimum_required(VERSION "3.15.4") 
project("Algorithms and Data Structures" VERSION 0.3.0)

find_package(Catch2 REQUIRED)
add_executable(test test.cpp)
target_link_libraries(test PRIVATE Catch2::Catch2)
target_compile_options(test PRIVATE -Wall -Wextra -pedantic -Werror)