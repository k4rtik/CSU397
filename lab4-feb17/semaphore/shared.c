#include "shared.h"

int *create_shared_mem_buffer() {
        int *shmaddr = 0; /* buffer address */
        key_t key = SHM_KEY; /* use key to access a shared memory segment */

        int shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | SHM_R | SHM_W);
        if (errno > 0) {
                perror("shmget: failed to create shared memory segment");
                exit(EXIT_FAILURE);
        }

        shmaddr = (int*)shmat(shmid, NULL, 0);
        if (errno > 0) {
                perror ("shmat: failed to attach to shared memory segment");
                exit (EXIT_FAILURE);
        }

        return shmaddr;
}

int create_semaphore_set() {
        key_t key = ftok(SEM_KEY, 'E');

        int semid = semget(key, NSEM_SIZE, 0600 | IPC_CREAT);
        if (errno > 0) {
                perror("semget: failed to create semaphore array");
                exit (EXIT_FAILURE);
        } 

        semctl(semid, FULL_ID, SETVAL, 0);
        if (errno > 0) {
                perror("semctl: failed to set FULL semaphore");
                exit (EXIT_FAILURE);
        }

        semctl(semid, EMPTY_ID, SETVAL, BUFFER_SIZE);
        if (errno > 0) {
                perror("semctl: failed to set EMPTY sempahore");
                exit (EXIT_FAILURE);
        }

        semctl(semid, MUTEX_ID, SETVAL, 1);
        if (errno > 0) {
                perror("semctl: failed to create mutex");
        }

        return semid;
}

void clear_buffer(int *sbuff) {
        int i = 0;
        for (i = 0; i < BUFFER_SIZE; ++i)
                sbuff[i] = 0;
}

void print_buffer(int *sbuff) {
        int i = 0;
        for (i = 0; i < BUFFER_SIZE; ++i) {
                if (sbuff[i] == 1) printf("1");
        }
        printf("\n");
}
