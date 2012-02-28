#include "shared.h"

int main(int argc, char *argv[])
{
	char filename[MAXSIZE];
	char word3[MAXSIZE];
	
        int semid = create_semaphore_set();

	int fifo;
	
	if ((fifo = open("myfifo2", O_RDONLY)) < 0) {
		printf("open: pipe doesn't exist");
	        exit(-1);
	}
	
        read(fifo, filename, MAXSIZE);
        printf("filename: %s\n", filename);
        read(fifo, word3, MAXSIZE);
        printf("word3: %s\n", word3);
	
	close(fifo);
	
	char arg[100] = "";
	
	strcat(arg, "s/");
	strcat(arg, word3);
	strcat(arg, "//g");
	
        semop(semid, &Wait, 1);
	// execv for sed
	if (fork() == 0) {
		execlp("sed", "sed", "-i", arg, filename, NULL);
	}
	wait(NULL);
        semop(semid, &Signal, 1);
        semop(semid, &signal2, 1);
        
	return 0;
}
