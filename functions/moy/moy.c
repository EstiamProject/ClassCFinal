//
// Created by tuke on 11/11/2023.
//

#include <stdio.h>
#include "../../misc/utils.h"

void moy(char * input){

    for (int i = 0; input[i] != '\0' ; i++){ // make sure input is valid
        if (input[i] == ' ')
            continue;
        if (input[i] < '0' || input[i] > '9'){
            printf("invalid\n");
            return;
        }
    }

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
