cmake_minimum_required(VERSION 3.27)
project(PP C)

set(CMAKE_C_STANDARD 23)

add_executable(PP src/main.c
        src/accounts/accounts.h
        src/fileIO/fileIO.h
        src/fileIO/fileIO.c
        src/accounts/accounts.c)
