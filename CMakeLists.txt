cmake_minimum_required (VERSION 3.0)

project(BZ205)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable (BZ205 "main.cpp" "student_stack.cpp" "student_avl_tree.cpp" "sorting.cpp")
