#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 10
#define EMPTY_ID 0
#define FULL_ID 1
#define MUTEX_ID 2
#define NSEM_SIZE 3

#define SHM_KEY 9
#define SEM_KEY "."

static struct sembuf decEmpty = { EMPTY_ID, -1, 0 };
static struct sembuf incEmpty = { EMPTY_ID, 1, 0 };
static struct sembuf incFull = { FULL_ID, 1, 0 };
static struct sembuf decFull = { FULL_ID, -1, 0 };
static struct sembuf decMutex = { MUTEX_ID, -1, 0 };
static struct sembuf incMutex = { MUTEX_ID, 1, 0 };

int *create_shared_mem_buffer();
int create_semaphore_set();
int get_buffer_size(int *sbuff);
void clear_buffer(int *sbuf);
void print_buffer(int *sbuff);
