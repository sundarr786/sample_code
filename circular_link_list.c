// coding is on progress

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_SZ 15
typedef struct student {
	struct student *prev;
	int id;
	char name[MAX_NAME_SZ+1];
	struct student *next;
}st;

int main()
{
	
	return 0;
}
