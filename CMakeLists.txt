cmake_minimum_required(VERSION 3.26)
project(ClassC C)

set(CMAKE_C_STANDARD 23)

add_executable(ClassCFinal main.c
        functions.h
        functions.c
        utils.h
        utils.c)
