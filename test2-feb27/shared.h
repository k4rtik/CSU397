#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <string.h>
#define MAXSIZE 25

#define MUTEX_ID 0
#define MUTEX1_ID 1
#define MUTEX2_ID 2
#define NSEM_SIZE 3

#define SEM_KEY "."

static struct sembuf wait1 = { MUTEX1_ID, -1, 0 };
static struct sembuf signal1 = { MUTEX1_ID, 1, 0 };
static struct sembuf signal2 = { MUTEX2_ID, 1, 0 };
static struct sembuf wait2 = { MUTEX2_ID, -1, 0 };

static struct sembuf Wait = { MUTEX_ID, -1, 0 };
static struct sembuf Signal = { MUTEX_ID, 1, 0 };

int create_semaphore_set();
