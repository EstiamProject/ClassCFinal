//
// Created by tuke on 11/11/2023.
//
#include <stdio.h>
#include <string.h>
#include "../../misc/utils.h"

void mode(char * input){

    if (!strcmp(input, "calc")){
        printf("mode calc selected");
    } else if (!strcmp(input, "moy")) {
        printf("mode moy selected");
    } else if (!strcmp(input, "todo")) {
        printf("mode todo selected");
    } else if (!strcmp(input, "exit")) {
        printf("quitting modes");
    } else {
        printf("mode not detected");
    }

}