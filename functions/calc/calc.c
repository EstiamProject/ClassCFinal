//
// Created by tuke on 11/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../misc/utils.h"

void calc(char * input){

    int result = 0;
    char* token = strtok(input, " ");

    while (token != NULL) {
        if (!strcmp(token, "+")) {
            token = strtok(NULL, " ");
            result += atoi(token);
        }
        else if (!strcmp(token, "-")) {
            token = strtok(NULL, " ");
            result -= atoi(token);
        }
        else{
            result += atoi(token);
        }
        token = strtok(NULL, " ");
    }
    printf("%d\n", result);
}