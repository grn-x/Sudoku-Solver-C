cmake_minimum_required(VERSION 3.16)  # 3.30
project(sudoku C)

set(CMAKE_C_STANDARD 11)  # 23

add_executable(sudoku
        main.c
        solver.c
        interactive.c
        interactive.h
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})