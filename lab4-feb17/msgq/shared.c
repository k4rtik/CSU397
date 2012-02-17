#include "shared.h"

int create_msgq() {
        int *addr = 0; /* buffer address */
        key_t key = MSGQ_KEY; /* use key to access message queue */

        int msgqid = msgget(key, IPC_CREAT | 0600);
        if (errno > 0) {
                perror("msgget: failed to initialize message queue");
                exit(EXIT_FAILURE);
        }

        return msgqid;
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
