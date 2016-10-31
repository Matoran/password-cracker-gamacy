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
 * Function: error
 * ----------------------------
 *   Print an error message
 *
 *   msg: error to print 
 *  
 */
void error(char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}


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
    for (int i = 0; i < numberThreads; i++) {
        paramsThread[i].idThread = i;
        paramsThread[i].numberThreads = numberThreads;
        strncpy(paramsThread[i].hash, hash, 13);
        paramsThread[i].hash[13] = '\0';
        strncpy(paramsThread[i].salt, hash, 2);
        paramsThread[i].salt[2] = '\0';
        paramsThread[i].threads = threads;
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
    int old_state, old_type;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &old_state);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &old_type);

    paramsSt *params = (paramsSt *) paramsThread;

    struct crypt_data cryptData;
    cryptData.initialized = 0;
    unsigned long long int i = params->idThread + 1;
    while (1) {
        char *password = jumpToAlphabet(i, params->password);
        char *hash = crypt_r(password, params->salt, &cryptData);
        if (strcmp(hash, params->hash) == 0) {

            for (int numberThread = 0; numberThread < params->numberThreads; numberThread++) {
                if (numberThread != params->idThread) {
                    int code = pthread_cancel(params->threads[numberThread]);
                    if (code == ESRCH)
                        printf("cancel: thread already finished!\n");
                    else if (code != 0)
                        error("cancel: pthread_cancel FAILED");
                }
            }
            printf("password = %s\n", password);
            return NULL;
        }
        i += params->numberThreads;
    }

}
