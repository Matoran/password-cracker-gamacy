/*
 * Authors: LOPES Marco, ISELI Cyril and RINGOT Gaëtan
 * Purpose: Password cracker.
 * Language:  C
 * Date : 2 november 2016
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "thread.h"

/*
 *   Call the function create threads and calc executed time
 *
 *   argc: argument counter
 *   argv: table of arguments
 *
 *   returns: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char const *argv[]) {
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);

    if (argc != 3) {
        printf("usage: ./crack [hash] [number of threads]\n");
        return EXIT_FAILURE;
    }
    if (atoi(argv[2]) <= 0) {
        printf("usage: ./crack [hash] [min number of threads: 1]\n");
        return EXIT_FAILURE;
    }
    createThreads(argv[1], atoi(argv[2]));

    clock_gettime(CLOCK_MONOTONIC, &finish);
    double elapsed = finish.tv_sec - start.tv_sec;
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Executed time: %f s\n", elapsed);
    return EXIT_SUCCESS;
}
