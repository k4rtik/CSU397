#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 10

#define MSGQ_KEY 9

struct msgbuf {
	long mtype;       /* message type, must be > 0 */
        int mtext[BUFFER_SIZE];    /* message data */
} *msgp;

int *create_msgq();
void clear_buffer(int *sbuf);
void print_buffer(int *sbuff);
