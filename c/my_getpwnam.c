#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define MAX_NAME_SIZ 36

struct passwd *my_getpwnam(const char *name)
{
	struct passwd *ps = NULL;
	if (name == NULL) {
		printf("name is null\n");
		return NULL;
	}

	setpwent();
	
	while ((ps = getpwent()) != NULL) {
		if (strcmp(ps->pw_name, name) == 0) {
			endpwent();
			return ps;
		}
	}
	
	endpwent();
	return NULL;	
}

int main(void)
{
	struct passwd *ps = NULL;
	char name[MAX_NAME_SIZ + 1] = "";

	printf("enter name:\n");
	scanf("%s", name);
	
	if (strlen(name) == 0 || strlen(name) > MAX_NAME_SIZ) {
		printf("invalid name length");
		return -1;
	}
	
	ps = my_getpwnam(name);

	if (ps == NULL) {
		printf("unable to get data for name: %s", name);
		return -1;
	}
	
	printf("name: %s is valid\n", ps->pw_name);

	return 0;
}

