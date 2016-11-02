#ifndef THREADPRIVATE_H
#define THREADPRIVATE_H

#define LENGTH_MAX 3
#define LENGTH_HASH 13
#define LENGTH_SALT 2

typedef struct paramsSt {
    int numberThreads;
    int idThread;
    char hash[LENGTH_HASH + 1];
    char salt[LENGTH_SALT + 1];
    char password[LENGTH_MAX + 1];
    int *found;
} paramsSt;

extern void *thread(void *paramsThread);

#endif
