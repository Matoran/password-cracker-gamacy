#ifndef THREADPRIVATE_H
#define THREADPRIVATE_H

//params to thread function
typedef struct paramsSt{
	int numberThreads;
	int idThread;
	char hash[14];
	char salt[3];
    char password[20];
	pthread_t *threads;
}paramsSt;

void *thread(void *paramsThread);

#endif
