//
// Created by tuke on 11/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../misc/utils.h"

void todo(char * input){

    // setup file

    FILE *file;

    char c;

    file = fopen("list.txt", "r"); // open list

    if (file == NULL) { // is file open, if failed then try to make new file
        fclose(file);
        printf("failed to open list making file\n");
        file = fopen("list.txt", "w"); // create file
    }

    fclose(file); // close file

    // treat command instructions so we know what to do

    int len = 0;
    char instruction[255];

    memset(instruction, 0, sizeof(instruction)); // clear string (had errors)

    while (1) {

        if( input[len] == ' ' && len != 0 || input[len] == '\0')
            break;

        if (len >= 255){
            printf("command invalid\n");
            return;
        }
        instruction[len] = input[len];

        len++;
    }

    chop_start(input, len);
    remove_character(instruction, ' ');

    if (!strcmp(instruction,"add")) {

        file = fopen("list.txt", "a"); // open in append mode

        if (file == NULL) {
            printf("could not open list\n"); // shouldn't happen but who knows
            return;
        }
        fprintf(file, "%s\n",input );

        fclose(file); // close file ofc because operation is done

    } else if (!strcmp(instruction,"show")) {

        file = fopen("list.txt", "r"); // open file to read it

        if (file == NULL) { //

            printf("failed to open list\n");
            return;
        }

        fseek(file, 0, SEEK_END);
        if (ftell(file) == 0) { // is file empty?
            printf("empty\n");
            fclose(file);
            return;
        }

        rewind(file); // go back to start

        while ((c = (char)fgetc(file)) != EOF) { // print the full file

            putchar(c);
        }
        fclose(file); // close file

    } else if (!strcmp(instruction,"delete")) {

        int del_line = atoi(input);

        int currentLine = 1;
        char buffer[512];

        file = fopen("list.txt", "r+"); //open file to read and write
        if (file == NULL) {
            printf("couldn't open file\n");
            return;
        }

        FILE *tempFile = fopen("temp.txt", "w"); //open file to just write
        if (tempFile == NULL) {
            printf("couldn't open file\n");
            fclose(file);
            return;
        }

        while (fgets(buffer, sizeof(buffer), file) != NULL) { //get all lines except the one we are removing
            if (currentLine != del_line) {
                fputs(buffer, tempFile);
            }
            currentLine++;
        }

        // close both files
        fclose(file);
        fclose(tempFile);

        if (remove("list.txt") != 0) { // delete old list
            printf("failed deleting the original file.\n");
            return;
        }

        if (rename("temp.txt", "list.txt") != 0) { //rename temp file
            printf("failed renaming the temporary file.\n");
            return;
        }

    } else {
        printf("command invalid :%s:\n", instruction);
    }
}