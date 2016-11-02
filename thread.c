/*
 * Authors: LOPES Marco, ISELI Cyril and RINGOT Gaëtan
 * Purpose: Management of threads.
 * Language:  C
 * Year : 2016-2017
 */

#define _GNU_SOURCE

#include <crypt.h>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"
#include "thread.h"
#include "threadprivate.h"

/*
 * Function: createThreads
 * ----------------------------
 *   Generate a number of thread
 *
 *   hash: hash to decode
 *   numberThreads: number of thread to decode.
 *
 */
void createThreads(const char *hash, int numberThreads) {
    pthread_t threads[numberThreads];
    paramsSt paramsThread[numberThreads];
    int found = 0;
    for (int i = 0; i < numberThreads; i++) {
        paramsThread[i].idThread = i;
        paramsThread[i].numberThreads = numberThreads;
        strncpy(paramsThread[i].hash, hash, 13);
        paramsThread[i].hash[13] = '\0';
        strncpy(paramsThread[i].salt, hash, 2);
        paramsThread[i].salt[2] = '\0';
        paramsThread[i].found = &found;
        int code = pthread_create(&threads[i], NULL, thread, &paramsThread[i]);
        if (code != 0) {
            fprintf(stderr, "pthread_create failed!\n");
        }
    }
    for (int i = 0; i < numberThreads; i++) {
        if (pthread_join(threads[i], NULL) != 0) 
        {
            perror("pthread_join");
        }
    }
    if(!found)
        printf("No match found\n");
}


/*
 * Function: thread
 * ----------------------------
 *   Tasks of a single thread
 *
 *   paramsThread: 
 *
 */
void *thread(void *paramsThread) {
    paramsSt *params = (paramsSt *) paramsThread;

    struct crypt_data cryptData;
    cryptData.initialized = 0;
    unsigned long long int i = params->idThread + 1;
    while (1) {
        char *password = jumpToAlphabet(i, params->password);
        char *hash = crypt_r(password, params->salt, &cryptData);
        if (strcmp(hash, params->hash) == 0) {
            //printf("password = %s\n", password);
            *params->found = 1;
            return NULL;
        }
        if (*params->found || strlen(password) > LENGTH_MAX)
        {
            return NULL;
        }
        i += params->numberThreads;
    }

}
