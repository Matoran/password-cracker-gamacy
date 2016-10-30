//
// Created by matoran on 10/28/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("usage: ./crack [salt] [password]\n");
        return EXIT_FAILURE;
    }
    printf("%s = %s\n", argv[2], crypt(argv[2], argv[1]));
    return EXIT_SUCCESS;
}

