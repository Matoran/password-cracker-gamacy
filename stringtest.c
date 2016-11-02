/*
 * Authors: LOPES Marco, ISELI Cyril and RINGOT Gaëtan
 * Purpose: Password cracker.
 * Language:  C
 * Date : 2 november 2016
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

/*
 *   Print the password, and the time elapsed to find it
 *
 *   argc: argument counter
 *   argv: table of arguments
 *
 *   returns: EXIT_FAILURE or EXIT_SUCCESS.
 */
int main(int argc, char const *argv[]) {
    char *string = malloc(sizeof(char) * 20);
    char *string2 = malloc(sizeof(char) * 20);
    for (unsigned int i = 0; i < 10000; ++i) {
        string[0] = 'A';
        string[1] = '\0';
        string2[0] = 'A';
        string2[1] = '\0';
        if(strcmp(jumpToAlphabetRelative(i, string), jumpToAlphabet(i+1, string2)) != 0){
            printf("error");
        }
    }
    return EXIT_SUCCESS;
}
