//
// Created by tuke on 11/11/2023.
//
#include <stdio.h>
#include <string.h>
#include "../../misc/utils.h"
#include "../moy/moy.h"
#include "../todo/todo.h"
#include "../calc/calc.h"

int detect_mode(char* in) {

    if (!strcmp(in, "calc")) {


        return 0;
    } else if (!strcmp(in, "moy")) {


        return 1;
    } else if (!strcmp(in, "todo")) {


        return 2;
    } else if (!strcmp(in, "exit")) {

        return 3;
    } else {

        return 4;
    }
}

void call_functions(char* in, int mode) {
    switch (mode) {
        case 0:

            calc(in);
            printf("calc >>");
            break;
        case 1:

            moy(in);
            printf("moy >>");
            break;
        case 2:

            todo(in);
            printf("todo >>");
            break;

    }
}

void mode(char * input){

    int mode = detect_mode(input);
    if(mode == 4)
        return;
    int prevmode = mode;
    while (mode != 3){

        switch (mode) {
            case 0:
                printf("mode calc selected\n");
                break;
            case 1:
                printf("mode moy selected\n");
                break;
            case 2:
                printf("mode todo selected\n");
                break;
            case 4:
                call_functions(input, prevmode);
                break;
        }

        fgets(input, 255, stdin); // get user input
        remove_character(input, '\n');
        mode = detect_mode(input);
        prevmode = mode != 4 ? detect_mode(input) : prevmode;
    }
}