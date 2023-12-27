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

void reverse_node()
{
	st *p1 = NULL;
	st *p2 = NULL;

	if (head == NULL || head->next == NULL) {
		printf("not valid data operated");
		return;
	}
	
	p1 = head;
	p2 = head->next;

	p1->next = NULL;
	p1->prev = p2;

	while (p2 != NULL)	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2  = p2->prev;
	}
	head = p1;
	return;
}



void delete(int id)
{
	st *ptr = NULL;
	st *temp = NULL;
	st *l_prev = NULL;
	ptr = head;

	if (ptr == NULL)	{
		printf("no data available\n");
		return;
	}

	while (ptr != NULL)	{
		if (ptr->id == id)	{
			if (ptr == head)	{
				temp = ptr->next;
				if (temp != NULL)
					temp->prev = NULL;
				head = temp;
				free(ptr);
				return;
			}
			else if (ptr->next == NULL)	{
				temp  = ptr->prev;
				temp->next = NULL;
				free(ptr);
			}
			else {
				l_prev = ptr->prev;
		//		l_next = ptr->next;
				l_prev->next = ptr->next;
				l_prev->next->prev = l_prev;
				free(ptr);
			}

			
		}
		ptr = ptr->next;
	}
	return;
}
void clear()
{
	st *ptr = NULL;
	st *temp = NULL;
	
	if (head == NULL)	{
		printf("no data available\n");
		return;
	}
	
	ptr = head;
	while (ptr != NULL)	{
		temp = ptr->next;
		free(ptr);
		ptr= temp;

	}
	return;
}
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

void add_end()
{
	st *ptr = NULL;
	st *l_ptr = NULL;
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
		l_ptr = head;
		while (l_ptr->next != NULL)	{
			l_ptr = l_ptr->next;
		}
		l_ptr->next = ptr;
		ptr->prev = l_ptr;
		ptr->next = NULL;
	}
	
	return;
}

int main()
{
	int token = 0;
	int id = 0;
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
		else if (token == 3)	{
			//add after end node
			add_end();
		}
		else if (token == 4)	{
			printf("enter id to delete\n");
			scanf("%d",&id);
			delete(id);
		}
		else if (token == 5)	{
			reverse_node();
		}
		else if (token == 9)	{
			print();
			clear();
			break;
		}
	}
	return 0;
}
