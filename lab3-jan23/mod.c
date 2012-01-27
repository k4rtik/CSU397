/*
 * Implement a command sv for saving but it will not overwrite something that appears to be more up-to-date
 * Syntax: sv file dir
 */

#include <string.h>
#include <unistd.h>	//read, write
#include <fcntl.h>	//open, creat
#include "syscalls.h"	//error
#include <sys/stat.h>	// stat

#define PERMS 0600
#define MAX_PATH 1024

int main(int argc, char *argv[])
{
	if (argc != 3)
		error("Usage: sv source dest-dir");

	char buf[BUFSIZE];
	int sourcefd, destfd, count;
	char destfile[MAX_PATH];
	long mtimesrc, mtimedest = 0;

	strcat(destfile, argv[2]);
	strcat(destfile, "/");
	strcat(destfile, argv[1]);

	struct stat stbufsrc, stbufdest;

	if (stat(argv[1], &stbufsrc) == -1)
		error("sv: can't acess %s", argv[1]);

	mtimesrc = stbufsrc.st_mtime;

	if (stat(destfile, &stbufdest) != -1)
		mtimedest = stbufdest.st_mtime;

//	printf("%ld, %ld\n", mtimesrc, mtimedest);

	if (mtimesrc > mtimedest) {
		if ((sourcefd = open(argv[1], O_RDONLY)) == -1)
			error("sv: failed to open %s", argv[1]);
		if ((destfd = creat(destfile, PERMS)) == -1)
			error("sv: failed to open %s for writing", destfile);

		while ((count = read(sourcefd, buf, BUFSIZE)) > 0)
			if ((write(destfd, buf, count)) != count)
				error("sv: write error on file %s", destfile);
	}

	return 0;
}
