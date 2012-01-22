#include <stdlib.h>
#include <stdio.h>

void error(char *message)
{
	printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}
