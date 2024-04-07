cmake_minimum_required(VERSION 3.27)
project(PP C)

set(CMAKE_C_STANDARD 23)

add_executable(PP main.c
        accounts.h
        fileIO.h
        fileIO.c
        accounts.c)
