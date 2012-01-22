#include <unistd.h>	//read, write
#include <fcntl.h>	//open
#include "syscalls.h"	//error

int main(int argc, char *argv[])
{
	if (argc != 3)
		error("Usage: cp source destination");

	char buf[1024];
	int sourcefd, destfd;
	int count;

	if ((sourcefd = open(argv[1], O_RDONLY)) < 0)
		error("open failed for specified source file.");
	destfd = open(argv[2], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

	while ((count = read(sourcefd, buf, sizeof(buf))) > 0)
		write(destfd, buf, count);

	return 0;
}
