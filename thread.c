/*********************
asdasdasd
asdasda
sdasdasd
asdasd
*********************/
#include "thread.h"
#include "threadprivate.h"
#include <pthread.h>
#include <stdio.h>	

void createThreads(char *hash, int numberThread){
	pthread_t threads[numberThread];
	structParamsFunctionThread paramsThread[numberThread];
	for (int i = 0; i < numberThread; i++) {
		paramsThread[i].idThread = i;
		paramsThread[i].numberMaxThread = numberThread;  
		int code = pthread_create(&threads[i], NULL, thread, &paramsThread[i]);
		if (code != 0) {
			fprintf(stderr, "pthread_create failed!\n");
		}		
	}

	for (int i = 0; i < numberThread; i++) {
		if (pthread_join(threads[i], NULL) != 0) {
			perror("pthread_join");
		}	
	}
}

void *thread(void *paramsThread) {
	structThread strThread;
	//cast *
	structParamsFunctionThread* params = (structParamsFunctionThread*)paramsThread;
	//printf("%d\n", params->idThread);
	strThread.idThread = params->idThread;
	//printf("%d\n", params->numberMaxThread);
	strThread.numberMaxThread = params->numberMaxThread; 
}
