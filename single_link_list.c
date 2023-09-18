#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SZ  15

typedef struct student_rec {
	int id;
	char name[MAX_NAME_SZ+1];
	struct student_rec *next;
}st;

st *rec = NULL;

void delete(int id)
{
	st *ptr = rec;
	st *bfr = NULL;
	if	(ptr == NULL)	{
		printf("NO DATA");
		return;
	}

	while (ptr != NULL)	{
		if (ptr->id == id)	{
			if (ptr == rec)	{
				rec = ptr->next;
				free(ptr);
				return;
			}
			else	{
				bfr->next = ptr->next;
				free(ptr);
				return;			
			}
		}
		bfr = ptr;
		ptr = ptr->next;
	}
	return;
}

void print()
{
	st *ptr = NULL;
	for (ptr = rec; ptr !=NULL; ptr=ptr->next)	{
		printf("id:%d name:%s\n",ptr->id,ptr->name);
	}
	return;
}

void clear()
{
	st *ptr = NULL;

	while ( rec != NULL)	{
		ptr = rec;
		rec = ptr->next;
		free(ptr);
	}
	return;
}

void add_end()
{
	st *l_rec = NULL;
	if	(!(l_rec = (st *)malloc(sizeof (st))))	{
		printf("unable to add , memory issue\n");
		return;
	}
	printf("enter record id to add\n");
	scanf("%d",&l_rec->id);
	printf("enter name to add\n");
	scanf("%s",l_rec->name);

	if	(rec == NULL)	{
		rec = l_rec;
		l_rec->next = NULL;
	}
	else	{
		st *ptr = rec;
		while (ptr->next != NULL)
			ptr = ptr->next;

		l_rec->next = NULL;
		ptr->next = l_rec;
	}
	return;
}

void add_begin()
{
	st *l_rec = NULL;
	if	(!(l_rec = (st *)malloc(sizeof (st))))	{
		printf("unable to add , memory issue\n");
		return;
	}
	printf("enter record id to add\n");
	scanf("%d",&l_rec->id);
	printf("enter name to add\n");
	scanf("%s",l_rec->name);
	l_rec->next = rec; // for first entry rec will be null
	rec = l_rec;

	return;
}

int main()
{
	int id = 0;
	int num = 0;
	while	(1)	{

		printf("enter 1 : add in begining\n2 : add in end\n3 : delete\n4 : print\n");
		scanf(" %d",&num);
		if	(num == 1)
			add_begin();
		else if (num == 2)
			add_end();
		else if (num == 3)	{
			printf("enter id to delete\n");
			scanf(" %d",&id);
			delete(id);
		}
		else if (num == 4)
			print();
		else if (num == 9) {
			print();
			printf("exiting ch:%c\n",ch);
			clear();
			break;
		}
		else
			continue;
	}

	return 0;
}
