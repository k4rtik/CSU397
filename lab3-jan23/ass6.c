/*
 * 6. Write a C program to implement 'ls | sort', using fork() & pipe() 
 * system calls. 
 */

#include <unistd.h>
#include "syscalls.h"
#include <string.h>

int main(int argc, char **argv)
{
	char *dir;
	if (argc == 1)
		dir = NULL;
	else
		dir = argv[1];

	int fd[2], pid;
	if (pipe(fd) == -1)
		error("sortedlist: error creating pipe");
	if ((pid = fork()) < 0)
		error("sortedlist: error while forking");

	if (pid > 0) {
		close(1);
		dup(fd[1]);
		close(fd[0]);
		close(fd[1]);
		execlp("ls", "ls", dir, NULL);
	}
	else if (pid == 0) {
		close(0);
		dup(fd[0]);
		close(fd[0]);
		close(fd[1]);
		execlp("sort", "sort", "-r", NULL);
	}

	return 0;
}
