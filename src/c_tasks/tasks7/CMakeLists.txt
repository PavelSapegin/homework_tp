cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(task7 C)

set(TASK5_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../tasks5)


# собираем stack
add_library(stack STATIC ${TASK5_DIR}/stack.c)
target_include_directories(stack PUBLIC ${TASK5_DIR})


# собираем cool_brackets
add_executable(cool_brackets ${TASK5_DIR}/brackets.c)
target_link_libraries(cool_brackets PRIVATE stack)
target_compile_options(cool_brackets PRIVATE -Wall -Wextra -Wpedantic)

# собираем sort_station

add_executable(sort_station ${TASK5_DIR}/sort_station.c)
target_link_libraries(sort_station PRIVATE stack)
target_compile_options(sort_station PRIVATE -Wall -Wextra -Wpedantic)

