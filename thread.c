/*********************
asdasdasd
asdasda
sdasdasd
asdasd
*********************/

void createThreads(int numberThread){
	pthread_t threads[numberThread];
	structParamsFunctionThread[numberThread] paramsThread;
	for (int i = 0; i < numberThread; i++) {
		paramsThread[i].idThread = i;
		paramsThread[i].numberMaxThread = numberThread;  
		int code = pthread_create(&threads[i], NULL, thread, &paramsThread[i]);
		if (code != 0) {
			fprintf(stderr, "pthread_create failed!\n");
			return EXIT_FAILURE;
		}		
	}

	for (int i = 0; i < numberThread; i++) {
		if (pthread_join(threads[i], NULL) != 0) {
			perror("pthread_join");
			return EXIT_FAILURE;
		}	
	}
}

void *thread(void *paramsThread) {
	structThread strThread;
	strThread.idThread =  paramsThread.idThread;
	strThread.numberMaxThread = paramsThread.numberMaxThread; 
}
