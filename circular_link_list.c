// coding is on progress

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_SZ 15
typedef struct student {
	//struct student *prev;
	int id;
	char name[MAX_NAME_SZ+1];
	struct student *next;
}st;

st *head = NULL;

void clear()
{
	st *ptr = NULL;
	st *temp = NULL;
	int count = 0;

	if (head == NULL)	{
		printf("no data available\n");
		return;
	}

	ptr = head->next;
	
	do {	
		if (ptr->next != ptr)	{
		ptr = ptr->next;
		temp = ptr->next;
		printf("clear--->addr:%p\n",ptr);
		free(ptr);
		count++;		
		ptr = temp;
		}
	}while (ptr!=head->next);
		if (head->next == ptr)	{
		printf("clear--->addr:%p\n",ptr);
			ptr->next = ptr;
			free(ptr);
		count++;		
		}
	head = NULL;	

	
	printf("cleared node_count:%d",count);
	return;
}


void print()
{
	st *ptr = NULL;
	if (head == NULL)	{
		printf("no data\n");
		return;
	}
	
	ptr = head->next;
	do {
		printf("id:%d name:%s\n",ptr->id,ptr->name);
		ptr = ptr->next;
	}while(ptr != head->next);
	
	return;
}

void add_begin()
{
	st *ptr = NULL;
	if	(!(ptr = (st *)malloc(sizeof (st))))	{
		printf("unable to add , memory issue\n");
		return;
	}
	printf("enter record id to add\n");
	scanf("%d",&ptr->id);
	printf("enter name to add\n");
	scanf("%s",ptr->name);

	if (head == NULL)	{
		ptr->next = ptr;
		head = ptr;
	}
	else	{
		ptr->next = head->next;
		head->next = ptr;

	}
	printf("add--->addr:%p\n",ptr);
	return;
}


int main()
{
	int token = 0;
	while (1)	{
		printf("enter the option\n");
		scanf("%d",&token);
		if (token == 1)	{
			add_begin();
		}
		else if (token == 2)	{
			print();
		}	
		else if (token == 9)	{
			print();
			clear();
		}
	}
	return 0;
}
