#include "shared.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("format: %s <filename>\n", argv[0]);
		exit(-1);
	}
	char filename[MAXSIZE];
	strcpy(filename, argv[1]);
	char word1[MAXSIZE], word2[MAXSIZE], word3[MAXSIZE];
	
        int semid = create_semaphore_set();
	
	scanf("%s", word1);
	scanf("%s", word2);
	scanf("%s", word3);
	
	
	int fifo1, fifo2;

	remove("myfifo1");
	remove("myfifo2");

	if (mkfifo("myfifo1", 0600))
	{
	        printf("mkfifo: error creating named pipe");
		exit(-1);
	}

	if((fifo1 = open("myfifo1", O_WRONLY)) < 0) {
	        printf("open: pipe doesn't exist");
	        exit(-1);
	}
	if (fork() == 0) {
		execlp("./p2", "./p2", NULL);
	}
	write(fifo1, filename, MAXSIZE);
	printf("P1: Sending filename to P2\n");

	write(fifo1, word1, MAXSIZE);
	printf("P1: Sending word1 to P2\n");
	write(fifo1, word2, MAXSIZE);
	printf("P1: Sending word2 to P2\n");
	
	close(fifo1);
	
	if (mkfifo("myfifo2", 0600))
	{
	        printf("mkfifo: error creating named pipe");
		exit(-1);
	}

	if((fifo2 = open("myfifo2", O_WRONLY)) < 0) {
	        printf("open: pipe doesn't exist");
	        exit(-1);
	}
	if (fork() == 0) {
		execlp("./p3", "./p3", NULL);
	}
	write(fifo2, filename, MAXSIZE);
	printf("P1: Sending filename to P3\n");

	write(fifo2, word3, MAXSIZE);
	printf("P1: Sending word3 to P3\n");
	
	close(fifo2);
	

	semop(semid, &wait1, 1);
	semop(semid, &wait2, 1);
	
	execlp("cat", "cat", filename, NULL);

	return 0;
}
