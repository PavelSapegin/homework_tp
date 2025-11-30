cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(task_10_bin_repr C)

set(BIN_REPR_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(double_repr STATIC double_repr.c)
target_include_directories(double_repr PUBLIC ${BIN_REPR_DIR})

add_library(tests test.c)
target_include_directories(tests PUBLIC ${BIN_REPR_DIR})

add_executable(main main.c)
target_link_libraries(main PRIVATE double_repr)
target_link_libraries(main PRIVATE tests)



