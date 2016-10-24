#ifndef THREADPRIVATE_H
#define THREADPRIVATE_H

//
typedef struct threadSt{
	int numberMaxThread;
	int idThread;

	int valCode;
}threadSt;


//params to thread function
typedef struct paramsSt{
	int numberThreads;
	int idThread;
	char hash[14];
	char salt[3];
	pthread_t *threads;
}paramsSt;

void *thread(void *paramsThread);

#endif
