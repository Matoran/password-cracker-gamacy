#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "thread.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	struct timespec start, finish;
	clock_gettime(CLOCK_MONOTONIC, &start);

	// code a compléter
	//createThreads(10);
	printf("%s\n",jumpToAlphabet(12,65));
	//printf("%s\n",inverseString("salut"));

	clock_gettime(CLOCK_MONOTONIC, &finish);
	double elapsed = finish.tv_sec - start.tv_sec;
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	printf("Time to find : %f s\n", elapsed);
	
	return 0;
}
