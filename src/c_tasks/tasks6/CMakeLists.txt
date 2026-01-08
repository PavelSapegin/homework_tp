cmake_minimum_required(VERSION 3.13)
project(task_6 C)

option(counter "compile counter" OFF)
set(SOURCES)

if(counter)
    message(STATUS "compile counter")
    list(APPEND SOURCES brackets.c)
else()
    message(STATUS "compile sortedlist")
    list(APPEND SOURCES sortedlist.c)
endif()

add_executable(app ${SOURCES})
