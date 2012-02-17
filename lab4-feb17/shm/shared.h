#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 10

#define SHM_KEY 9

int *create_shared_mem_buffer();
void clear_buffer(int *sbuf);
void print_buffer(int *sbuff);
