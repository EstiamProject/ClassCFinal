cmake_minimum_required(VERSION 3.26)
project(ClassC C)

set(CMAKE_C_STANDARD 23)

add_executable(ClassCFinal
        main.c
        misc/utils.h
        misc/utils.c
        functions/todo/todo.c
        functions/moy/moy.c
        functions/mode/mode.c
        functions/calc/calc.c
        functions/todo/todo.h
        functions/moy/moy.h
        functions/mode/mode.h
        functions/calc/calc.h
)
