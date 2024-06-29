//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SZ  15

typedef struct student_rec {
	int id;
	char name[MAX_NAME_SZ+1];
	struct student_rec *next;
}st;

st *rec = NULL;

/* 
finding last node logic:
------------------------
	ptr = rec;
	while (ptr->next !=NULL)	{
		ptr = ptr->next;	
	}
*/

/*
find  second last node:
----------------------

ptr = rec;
while (ptr->next->next!=NULL)	{
	ptr = ptr->next;
}
*/

void reverse_node()
{
	st *ptr = NULL;
	st *prev = NULL;	
	st *next = NULL;	
	ptr = rec;
	
	while (ptr != NULL)	{
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}	
	rec = prev;

	return;
}


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

void search_by_id(int id)
{
	st *l_ptr = NULL;
	int count = 0;

	l_ptr = rec;
	
	while (l_ptr!=NULL)	{
		count++;
		printf("count:%d\n",count);
		if (l_ptr->id == id)	{
			printf("id:%d found at position:%d\n",id,count);
			break;
		}
		l_ptr = l_ptr->next;
		if (l_ptr == NULL)	{
			printf("id:%d is not in list\n",id);
		}
	}
	
	return;
}

void count_and_print()
{
	st *l_ptr = NULL;
	int count = 0;

	if (rec == NULL)	{
		printf("0 elements in list\n");
		return;
	}
	else	{
		l_ptr = rec;
		
		while (l_ptr!=NULL)	{
			count++;
			l_ptr = l_ptr->next;
		}
		printf("Total number of nodes:%d\n",count);
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

		ptr->next = l_rec;
		l_rec->next = NULL;
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
	
	//below order is important
	l_rec->next = rec; // for first entry rec will be null
	rec = l_rec;

	return;
}

int main()
{
	int id = 0;
	int num = 0;
	atexit(clear);
	while	(1)	{

		printf("enter your choice:\n1 : add in begining\n2 : add in end\n3 : search by id\n4 : count\n");
		printf("5 : delete by id\n6 : print\n9 : print,clear and exit\n**********\n");
		scanf(" %d",&num);
		if	(num == 1)
			add_begin();
		else if (num == 2)
			add_end();
		else if (num == 3)	{
			printf("enter id to search\n");
			scanf(" %d",&id);
			search_by_id(id);
		}
		else if (num == 4)
			count_and_print();
		else if (num == 5)	{
			printf("enter id to delete\n");
			scanf(" %d",&id);
			delete(id);
		}
		else if (num == 6)
			print();
		else if (num == 7)	{
			//add in middle
		}
		else if (num == 8)	{
			reverse_node();
		}
		else if (num == 9) {
			print();
			clear();
			break;
		}
		else
			continue;
	}

	return 0;
}
