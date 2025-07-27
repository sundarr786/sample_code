#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "err_func.h"

void usageErr(const char *format, ...)
{
	va_list arg_list;
	fflush(stdout);

	fprintf(stderr, "Usage: ");

	va_start(arg_list, format);
	vfprintf(stderr, format, arg_list);
	va_end(arg_list);

	fflush(stderr);

	exit(EXIT_FAILURE);
}

void errExit(const char *format, ...)
{
	va_list arg_list;

	fflush(stdout);
	
	fprintf(stderr, "Err: ");

	va_start(arg_list, format);
	vfprintf(stderr, format, arg_list);
	va_end(arg_list);

	fflush(stderr);

	exit(EXIT_FAILURE);

}
