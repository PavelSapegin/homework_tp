cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(task_10_double_convertation C)

set(DOUB_CONV_DIR ${CMAKE_CURRENT_DIR})

add_library(double_conv STATIC double_conv.c)
target_include_directories(double_conv PUBLIC ${DOUB_CONV_DIR})

add_library(tests test.c)
target_include_directories(tests PUBLIC ${DOUB_CONV_DIR})

add_executable(main main.c)
target_link_libraries(main PRIVATE tests double_conv)
