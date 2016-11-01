/*
 * Authors: LOPES Marco, ISELI Cyril and RINGOT Gaëtan
 * Purpose: Password cracker.
 * Language:  C
 * Year : 2016-2017
 */


#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/*
 * Function: main
 * ----------------------------
 *   Print the password, and the time elapsed to find it
 *
 *   argc: argument counter
 *   argv: table of arguments
 *
 *   returns: EXIT_FAILURE or EXIT_SUCCESS.
 */
int main(int argc, char const *argv[]) {
    char *string = malloc(sizeof(char) * 20);

    for (unsigned int i = 0; i < 18; ++i) {
        string[0] = 'C';
        string[1] = 'C';
        string[2] = 'C';
        string[3] = 'C';
        string[4] = '\0';
        printf("%s %d\n", jumpToAlphabetRelative(i, string), i);
    }

    return EXIT_SUCCESS;
}
