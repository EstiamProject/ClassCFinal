//
// Created by tuke on 11/10/2023.
//

#include <assert.h>
#include <string.h>
#include <stdlib.h>

void chop_start(char *str, size_t n){ // removes start of string n being the amount of characters

    assert(n != 0 && str != 0);
    size_t len = strlen(str);
    if (n > len)
        return;  // Or: n = len;
    memmove(str, str+n, len - n + 1);
}

void remove_character(char* s, char c) { // removes certain character in a string
    char* d = s;
    do {
        while (*d == c) {
            ++d;
        }
    } while (*s++ = *d++);
}

void StringToListOfNumbers(char*s, int*list, int*num){ // pretty logical :)

    int maxSize = 100;
    int numbers[maxSize];
    int count = 0;
    char *token = strtok(s, " ");


    while (token != NULL && count < maxSize) {
        numbers[count] = atoi(token);
        count++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < count; i++) {
        list[i] = numbers[i];
    }
    *num = count;
}