#ifndef THREADPRIVATE_H
#define THREADPRIVATE_H

typedef struct structThread{
	int numberMaxThread;
	int idThread;
	char* password;
	int valCode;
}structThread;

typedef struct structParamsFunctionThread{
	int numberMaxThread;
	int idThread;
}structParamsFunctionThread;

void *thread(void *paramsThread);

#endif
