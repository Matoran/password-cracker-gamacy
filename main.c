#define _GNU_SOURCE
#include <crypt.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "thread.h"
#include "string.h"

int main(int argc, char const *argv[]){
	struct timespec start, finish;
	clock_gettime(CLOCK_MONOTONIC, &start);

	if(argc != 3){
        printf("usage: ./crack [hash] [number of threads]");
        return EXIT_FAILURE;
	}
	struct crypt_data cryptData;
    cryptData.initialized = 0;

    //printf("hashed = %s\n", crypt_r("0", "42", &cryptData));

	createThreads(argv[1], atoi(argv[2]));

	clock_gettime(CLOCK_MONOTONIC, &finish);
	double elapsed = finish.tv_sec - start.tv_sec;
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	printf("Time to find : %f s\n", elapsed);

	return 0;
}
