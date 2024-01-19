/*
practise: stack implementation using linked list
The new node is added at begging of node, while pop it will delete begining of node.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_SZ 31

typedef struct student_record {
	int id;
	char name[MAX_NAME_SZ+1];
	struct student_record *next;
}st;

st *head = NULL;

void clean()
{
	st *ptr = NULL;
	
	while (head != NULL)	{
		ptr = head;
		head = ptr->next;
		free(ptr);
		ptr = NULL;
	}
	return;
}

void push()
{
	st *ptr = NULL;
	ptr = (st *)malloc(sizeof (st));
	if (ptr == NULL)	{
		printf("unable to allocate memory\n");
		return;
	}
	printf("enter id:\n");
	scanf("%d",&ptr->id);
	printf("enter name:\n");
	scanf("%s",ptr->name);
	
	if (head == NULL)	{
		ptr->next = NULL;
		head = ptr;
	}
	else {
		ptr->next = head;
		head = ptr;
	}
	
	printf("data pushed to stack\n");
	
	return;	
}

void pop()
{
	st *ptr = NULL;

	if (head == NULL) {
		printf("no data in stack\n");
		return;
	}	
	
	ptr = head;
	head = ptr->next;
	printf("data poped from stack\nid:%d name:%s\n",ptr->id,ptr->name);
	free(ptr);
	ptr = NULL;
	return;
}

int main()
{
	int opt = 0;	
	while (1)	{
		printf("Enter the required option\n:");
		printf("---- 1-push 2-pop 3-exit ----\n");
		scanf("%d",&opt);
		if (opt == 1)	{
			push();
		}	
		else if (opt == 2)	{
			pop();
		}
		else	{
			break;
		}	
	}
	clean();
	return 0;
}
