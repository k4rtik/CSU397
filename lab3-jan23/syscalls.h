#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void error(char *message, ...)
{
	va_list args;

	va_start(args, message);
	fprintf(stderr, "error: ");
	vfprintf(stderr, message, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}
