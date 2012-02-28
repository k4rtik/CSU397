#include "shared.h"

int create_semaphore_set() {
        key_t key = ftok(SEM_KEY, 'F');

        int semid = semget(key, NSEM_SIZE, 0600 | IPC_CREAT);
        if (errno > 0) {
                perror("semget: failed to create semaphore array");
                exit (EXIT_FAILURE);
        } 

        semctl(semid, MUTEX1_ID, SETVAL, 0);
        if (errno > 0) {
                perror("semctl: failed to set MUTEX1");
                exit (EXIT_FAILURE);
        }

        semctl(semid, MUTEX2_ID, SETVAL, 0);
        if (errno > 0) {
                perror("semctl: failed to set MUTEX2");
                exit (EXIT_FAILURE);
        }
        
        semctl(semid, MUTEX_ID, SETVAL, 1);
        if (errno > 0) {
                perror("semctl: failed to set MUTEX");
                exit (EXIT_FAILURE);
        }

        return semid;
}
