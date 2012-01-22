/*
 * 5.Write a C program to impelemnt a directory walk using opendir() and 
 * readdir() system calls. (All the file names(in the directory) should be 
 * printed as output.)
 */

#include <sys/types.h>	// various typedefs
#include <dirent.h>	// opendir
#include <sys/stat.h>	// stat
#include <fcntl.h>	// read, write
#include "syscalls.h"	// error
#include <stdio.h>
#include <string.h>

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fun)(char *))
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
			(*fun)(dname);
		}
	}
	closedir(dfd);
}

void list(char *file)
{
	struct stat stbuf;

	if (stat(file, &stbuf) == -1)
		error("list: can't acess %s", file);

	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(file, list);
	printf("%s\n", file);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		list(".");
	else
		while (--argc > 0)
			list(*(++argv));

	return 0;
}
