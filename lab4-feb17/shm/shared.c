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
