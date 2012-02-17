#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

void consume_item(int item) {
        ;
}

int main()
{
        int fifo, item = 0;

        if ((fifo = open("myfifo", O_RDONLY)) < 0) {
               printf("open: pipe doesn't exist");
                exit(-1);
        }
        while(1) {
                        read(fifo, &item, sizeof(item));
                        printf("consumer: %d\n", item);
                        consume_item(item);
        }
        
        close(fifo);

        return 0;
}
