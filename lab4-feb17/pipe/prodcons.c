#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int produce_item() {
        return 1;
}

void consume_item(int item) {
        ;
}

int main()
{
        int item = 0;
        int pipefd[2];
	pid_t pid;

	if (pipe(pipefd) == -1)	{
                printf("pipe: error creating pipe");
		exit(-1);
	}
	
	pid = fork();
	
	if (pid == 0) { //consumer
                close(pipefd[1]);
                while(1) {
                        read(pipefd[0], &item, sizeof(item));
                        
                        printf("consumer: %d\n", item);
                        consume_item(item);
                }
        }
        else { //producer
                close(pipefd[0]);
                while(1) {
                        item = produce_item();                      
                        write(pipefd[1], &item, sizeof(item));
                        printf("producer: %d\n", item);
                }
        }

        return 0;
}
