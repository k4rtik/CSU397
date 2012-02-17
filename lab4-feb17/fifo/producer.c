#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int produce_item() {
        return 1;
}

int main()
{
        int fifo, item = 0;
	
	remove("myfifo");

	if (mkfifo("myfifo", 0600))
	{
                printf("mkfifo: error creating named pipe");
		exit(-1);
	}

        if((fifo = open("myfifo", O_WRONLY)) < 0) {
                printf("open: pipe doesn't exist");
                exit(-1);
        }
        while(1) {
                item = produce_item();
                write(fifo, &item, sizeof(item));
                printf("producer: %d\n", item);
        }
        
        close(fifo);

        return 0;
}
