/*
 * 2. Write a C program to read 'n' characters from position 't' of a given 
 * file.
 */

#include <unistd.h>	//read, write
#include <fcntl.h>	//open, creat
#include "syscalls.h"	//error

int main(int argc, char *argv[])
{
	if (argc != 4)
		error("Usage: %s <file> <chars> <pos>", argv[0]);

	char buf[BUFSIZE];
	int fd, count;
	int n = atoi(argv[2]), t = atoi(argv[3]);

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error("cp: failed to open %s", argv[1]);

	if (lseek(fd, t, SEEK_SET) >= 0)
		if (n < BUFSIZE) {
			count = read(fd, buf, n);
			write(1, buf, count);
		}
		else
			while (n > 0) {
				count = read(fd, buf, BUFSIZE-1);
				write(1, buf, count);
				if ((n -= count) > BUFSIZE)
					continue;
				else {
					read(fd, buf, n);
					write(1, buf, n);
					break;
				}
			}
	else
		error("readnt: can't seek to position %s", argv[3]);
	write(1, "\n", 1); //introduces one more char, if checked with wc
 
	return 0;
}
