/*
 * 1. Write a C program to implement 'cp' command in linux.
 * (Source and destination files should be taken from command line)
 */

#include <unistd.h>	//read, write
#include <fcntl.h>	//open, creat
#include "syscalls.h"	//error

#define BUFSIZE 1000
#define PERMS 0600

int main(int argc, char *argv[])
{
	if (argc != 3)
		error("Usage: cp source destination");

	char buf[BUFSIZE];
	int sourcefd, destfd, count;

	if ((sourcefd = open(argv[1], O_RDONLY)) == -1)
		error("cp: failed to open %s", argv[1]);
	if ((destfd = creat(argv[2], PERMS)) == -1)
		error("cp: failed to open %s for writing", argv[2]);

	while ((count = read(sourcefd, buf, BUFSIZE)) > 0)
		if ((write(destfd, buf, count)) != count)
			error("cp: write error on file %s", argv[2]);

	return 0;
}
