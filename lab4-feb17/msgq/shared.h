#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 10

#define MSGQ_KEY 9

int create_msgq();
void print_buffer(int *sbuff);
