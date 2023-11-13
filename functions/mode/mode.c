//
// Created by tuke on 11/11/2023.
//
#include <stdio.h>
#include <string.h>
#include "../../misc/utils.h"

int detect_mode(char * input) {

    if (!strcmp(input, "calc")) {

        printf("mode calc selected\n");
        return 0;
    } else if (!strcmp(input, "moy")) {

        printf("mode moy selected\n");
        return 1;
    } else if (!strcmp(input, "todo")) {

        printf("mode todo selected\n");
        return 2;
    } else if (!strcmp(input, "exit")) {

        printf("quitting modes\n");
        return 3;
    } else {

        return 4;
    }
}
void mode(char * input){

}