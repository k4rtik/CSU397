#include "shared.h"

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
