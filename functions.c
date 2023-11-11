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
    float sum = 0.0f; // 0.0f

    StringToListOfNumbers(input, numbers, &num); // make numbers actually usable

    for (int i = 0; i < num; i++){ // iterate trough whole list

        sum += (float)numbers[i]; // calc la somme de la list
    }
    if (num != 0)
        printf("moyenne: %f\n", sum / (float)num); // print la somme
}

void mode(char * input){

    printf("%s", input);
}