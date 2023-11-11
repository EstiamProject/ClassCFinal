//
// Created by tuke on 11/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void calc(char * input){

    printf("%s", input);
}

void todo(char * input){

    printf("%s", input);
}
void moy(char * input){

    int numbers[255];
    int num = 0;
    float sum = 0;

    StringToListOfNumbers(input, numbers, &num);

    for (int i = 0; i < num; i++){

        sum += (float)numbers[i]; // calc la some de la liste
    }

    if (num != 0)
        printf("moyenne: %f\n", sum / (float)num);
}
void mode(char * input){

    printf("%s", input);
}