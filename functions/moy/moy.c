//
// Created by tuke on 11/11/2023.
//

#include <stdio.h>
#include <string.h>
#include "../../misc/utils.h"

int CheckIfInputIsValid(char * in){
    for (int i = 0; in[i] != '\0' ; i++){
        if (in[i] == ' ')
            continue;
        if (in[i] < '0' || in[i] > '9'){
            printf("invalid\n");
            return 1;
        }
    }
    return 0;
}

void moy(char * input){

    if (CheckIfInputIsValid(input))
        return;
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
