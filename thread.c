/*
 * Authors: LOPES Marco, ISELI Cyril and RINGOT Gaëtan
 * Purpose: Management of threads.
 * Language:  C
 * Date : 2 november 2016
 */

#define _GNU_SOURCE

#include <crypt.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"
#include "threadprivate.h"

/*
 *   Generate a number of threads
 *
 *   hash: hash to bruteforce
 *   numberThreads: number of threads to perform the bruteforce
 *
 */
void createThreads(const char *hash, int numberThreads) {
    pthread_t threads[numberThreads];
    paramsSt paramsThread[numberThreads];
    int found = 0;
    for (int i = 0; i < numberThreads; i++) {
        paramsThread[i].idThread = i;
        paramsThread[i].numberThreads = numberThreads;
        strncpy(paramsThread[i].hash, hash, LENGTH_HASH);
        paramsThread[i].hash[LENGTH_HASH] = '\0';
        strncpy(paramsThread[i].salt, hash, LENGTH_SALT);
        paramsThread[i].salt[LENGTH_SALT] = '\0';
        paramsThread[i].found = &found;
        int code = pthread_create(&threads[i], NULL, thread, &paramsThread[i]);
        if (code != 0) {
            fprintf(stderr, "pthread_create failed!\n");
        }
    }
    for (int i = 0; i < numberThreads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
        }
    }
    if (!found)
        printf("No match found\n");
}


/*
 *   Task of a single thread
 *
 *   paramsThread: struct which contain all information to perform the task
 *
 */
void *thread(void *paramsThread) {
    paramsSt *params = (paramsSt *) paramsThread;

    struct crypt_data cryptData;
    cryptData.initialized = 0;
    unsigned long long int i = params->idThread + 1;
    char *password = NULL;

    do {
        password = jumpToAlphabet(i, params->password);
        char *hash = crypt_r(password, params->salt, &cryptData);
        if (strcmp(hash, params->hash) == 0) {
            printf("password = %s\n", password);
            *params->found = 1;
            return NULL;
        }
        i += params->numberThreads;
    } while (!*params->found && strlen(password) <= LENGTH_MAX);
    return NULL;
}
