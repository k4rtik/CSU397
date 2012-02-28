#include "shared.h"

int main(int argc, char *argv[])
{
	char filename[MAXSIZE];
	char word1[MAXSIZE], word2[MAXSIZE];
	
        int semid = create_semaphore_set();

	int fifo;
	
	if ((fifo = open("myfifo1", O_RDONLY)) < 0) {
	       printf("open: pipe doesn't exist");
	        exit(-1);
	}
	
        read(fifo, filename, MAXSIZE);
        printf("filename: %s\n", filename);
        read(fifo, word1, MAXSIZE);
        printf("word1: %s\n", word1);
        read(fifo, word2, MAXSIZE);
        printf("word2: %s\n", word2);
	
	close(fifo);
	
	char arg[100];
	
	strcat(arg, "s/");
	strcat(arg, word1);
	strcat(arg, "/");
	strcat(arg, word2);
	strcat(arg, "/g");

        semop(semid, &Wait, 1);
	// execv for sed
	if (fork() == 0) {
		execlp("sed", "sed", "-i", arg, filename, NULL);
	}
	wait(NULL);
        semop(semid, &Signal, 1);
        semop(semid, &signal1, 1);
	
	return 0;
}
