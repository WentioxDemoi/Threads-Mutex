#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <pthread.h>
#include <semaphore.h>

#define _NB_THREADS_ 16

sem_t *semaphore;
pthread_mutex_t mutex;