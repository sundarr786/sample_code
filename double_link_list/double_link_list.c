// coding is on progress

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SZ 15
typedef struct student {
	struct student *prev;
	int id;
	char name[MAX_NAME_SZ+1];
	struct student *next;
}st;

st *head = NULL;

void print()
{
	st *ptr = NULL;
	if (head == NULL)	{
		printf("No data\n");
		return;
	}
	
	ptr = head;
	while (ptr!=NULL)	{
		printf("id:%d name:%s\n",ptr->id,ptr->name);
		ptr = ptr->next;
	}
	return;
}

void add_begin()
{
	st *ptr = NULL;
	if ((ptr = (st*)malloc(sizeof(st)))==NULL)	{
		printf("unable to allocate memory\n");
		return;
	}
	printf("Enter student id\n");
	scanf("%d",&ptr->id);
	printf("Enter name:\n");
	scanf("%s",ptr->name);
	
	if (head == NULL)	{
		ptr->prev = NULL;
		ptr->next = NULL;
		head = ptr;
	}
	else	{
		head->prev = ptr;
		ptr->next = head;
		head = ptr;
	}
	
	return;
}

int main()
{
	int token = 0;
	char ch;
	while (1)	{
		printf("enter option\n");
		scanf("%d",&token);
		printf("you entered %d\n",token);
		if (token == 1)	{
			//add begin
			add_begin();
		}
		else if (token == 2)	{
			print();
		}
		else if (token == 9)	{
			print();
		//	clear();
		}
		printf("do you want to continue\n");
		
		fflush(stdin);
		scanf("%c",&ch);
		if (ch == 'n')
			break;
		
	}
	return 0;
}
