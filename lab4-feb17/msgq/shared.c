#include "shared.h"

int create_msgq() {
        int *addr = 0; /* buffer address */
        int msgqid;
        key_t key = MSGQ_KEY; /* use key to access message queue */

        if ((msgqid = msgget(key, IPC_CREAT | 0600)) < 0) {
                perror("msgget: failed to initialize message queue");
                exit(EXIT_FAILURE);
        }

        return msgqid;
}

void print_buffer(int *sbuff) {
        int i = 0;
        for (i = 0; i < BUFFER_SIZE; ++i) {
                if (sbuff[i] == 1) printf("1");
        }
        printf("\n");
}
