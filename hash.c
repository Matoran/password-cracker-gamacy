/*
 * Authors: LOPES Marco, ISELI Cyril and RINGOT Gaëtan
 * Purpose: Hash a password with a salt
 * Language:  C
 * Date : 2 november 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>

/*
 *   Hash a password
 *
 *   argc: argument counter
 *   argv: table of arguments
 *
 *   returns: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("usage: ./crack [salt] [password]\n");
        return EXIT_FAILURE;
    }
    printf("%s = %s\n", argv[2], crypt(argv[2], argv[1]));
    return EXIT_SUCCESS;
}
