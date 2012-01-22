/*
 * 3. Write a C function 'fsize' which prints the size of a given file (in 
 * linux, a directory is also a kind of file). If the file is a directory    
 * make a directory walk to to apply 'fsize' on all files in it. The 
 * output in this case should be the name(s) of files in the directory 
 * and its size.
 */

#include <sys/types.h>	// various typedefs
#include <dirent.h>	// opendir
#include <sys/stat.h>	// stat
#include <fcntl.h>	// read, write
#include "syscalls.h"	// error
#include <stdio.h>
#include <string.h>

#define MAX_PATH 1024

void fsize(char *);

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

void fsize(char *file)
{
	struct stat stbuf;

	if (stat(file, &stbuf) == -1)
		error("fsize: can't acess %s", file);

	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(file, fsize);
	printf("%8ld %s\n", stbuf.st_size, file);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		fsize(".");
	else
		while (--argc > 0)
			fsize(*(++argv));

	return 0;
}
