#include <stdio.h>
#include <string.h>

#include "functions.h"
#include "utils.h"

int main(){

    char input[255] = ""; // le input de l'utilisateur
    char func[255] = ""; // la partie qui appel la fonction ex: calc, moy...
    char rest[255] = ""; // la partie 3 + 4 - 4 par exemple

    while (1) {

        printf(">>");
        fgets(input, sizeof(input), stdin); // get user input

        if (!strncmp(input, "quit", 4)) {

            printf("quitting %s\n", input);
            return 0;
        }

        int len = 0; // pour savoir la taille de func
        bool loop = 1;

        while (loop) {

            func[len] = input[len];

            if (input[len] == ' ')
                loop = 0;

            else if (len >= 255){

                printf("input invalid\n");
                return 1;
            }
            len++;
        }

        strcpy(rest, input); //copier input dans rest
        chop_start(rest, len); // enlever la partie commande

        if (!strcmp(func, "calc ")) {

            calc(rest);

        } else if (!strcmp(func, "todo ")) {

            todo(rest);

        } else if (!strcmp(func, "moy ")) {

            moy(rest);

        } else if (!strcmp(func, "mode ")) {

            mode(rest);

        } else {

            printf("input incorrect\n");
        }
    }
}