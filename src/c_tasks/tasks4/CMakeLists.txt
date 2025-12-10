cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(optsort C)
set(CURR_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(bubble_sort ${CURR_DIR}/bubble_sort.c)
target_compile_options(bubble_sort PRIVATE -O2)
