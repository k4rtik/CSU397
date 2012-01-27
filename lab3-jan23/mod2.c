/*
 * Implement a command svd for saving but it will not overwrite something that appears to be more up-to-date
 * Syntax: svd srcdir destdir
 */

#include <string.h>
#include <unistd.h>	//read, write
#include <fcntl.h>	//open, creat
#include "syscalls.h"	//error
#include <sys/stat.h>	// stat
#include <sys/types.h>	// various typedefs
#include <dirent.h>	// opendir

#define PERMS 0600
#define MAX_PATH 1024

int srcdnamesize = 0;

void dirwalk(char *dir, void (*fun)(char *, char *), char *dest)
{
	char dname[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;

	if ((dfd = opendir(dir)) == NULL)
		error("dirwalk: can't open %s", dir);

	while ((dp = readdir(dfd)) != NULL) {
		if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
			continue;
		if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(dname))
			error("dirwalk: name %s/%s too long", dir, dp->d_name);
		else {
			sprintf(dname, "%s/%s", dir, dp->d_name);
			(*fun)(dname, dest);
			printf("%s", dname);
		}
	}
	closedir(dfd);
}

void svd(char *src, char *dest)
{
	struct stat stbufsrc, stbufdest;

	if (stat(src, &stbufsrc) == -1)
		error("svd: can't acess %s", src);

	if ((stbufsrc.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(src, svd, dest);

	char buf[BUFSIZE];
	int sourcefd, destfd, count;
	char destfile[MAX_PATH];
	long mtimesrc, mtimedest = 0;

	strcat(destfile, dest);
	strcat(destfile, "/");
	strcat(destfile, src+srcdnamesize+1);

	mtimesrc = stbufsrc.st_mtime;

	if (stat(destfile, &stbufdest) != -1)
		mtimedest = stbufdest.st_mtime;

	if (mtimesrc > mtimedest) {
		if ((sourcefd = open(src, O_RDONLY)) == -1)
			error("svd: failed to open %s", src);
		if ((destfd = creat(destfile, PERMS)) == -1)
			error("svd: failed to open %s for writing", destfile);

		while ((count = read(sourcefd, buf, BUFSIZE)) > 0)
			if ((write(destfd, buf, count)) != count)
				error("svd: write error on file %s", destfile);
	}
	destfile[0] = '\0';
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		error("Usage: svd source-dir dest-dir");

	srcdnamesize = strlen(argv[1]);
	svd(argv[1], argv[2]);

	return 0;
}
