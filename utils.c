//
// Created by tuke on 11/10/2023.
//
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void chop_start(char *str, size_t n){
    assert(n != 0 && str != 0);
    size_t len = strlen(str);
    if (n > len)
        return;  // Or: n = len;
    memmove(str, str+n, len - n + 1);
}

void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int get_length(char* s){
    for (int i = 0; i < 255; i++){
        if (s[i] == '\0')
            return i;
    }
}
int count_spaces(char*s){
    int spaces = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            spaces++;
        }
    }
    return spaces;
}
void StringToListOfNumbers(char*s, int*list, int*num){

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