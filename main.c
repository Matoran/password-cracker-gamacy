#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	struct timespec start, finish;
	clock_gettime(CLOCK_MONOTONIC, &start);

	// code a compléter

	clock_gettime(CLOCK_MONOTONIC, &finish);
	double elapsed = finish.tv_sec - start.tv_sec;
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	printf("Time to find : %d s\n", elapsed);
	
	return 0;
}
