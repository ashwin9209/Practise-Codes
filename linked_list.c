#include <stdio.h>
#include <stdlib.h>

typedef struct sll
{
	int data;
	struct sll *next;

}LinkList;

int flag = 1;

LinkList *createList()
{
	int list_data;
	char c;
	LinkList *temp, *head;
	
	do
	{
		printf("\nEnter new list item: ");
		scanf("%d", &list_data);

		LinkList* newnode = (LinkList*) malloc (sizeof(LinkList));
		if (newnode == NULL)
		{
			printf("\nMemory not allocated.");
			exit(0);
		}
		newnode->data = list_data;
		newnode->next = NULL;

		if (flag == 1)
			//if the linked list is empty, add new element to head node
		{
			head = newnode;
			temp = newnode;
			flag = 0; //head node occupied
		}

		else
			//append new value to the end of the list
		{
			temp->next = newnode;
			temp = newnode;
		}

		printf("\nMore? Y/N: ");
		scanf(" %c", &c);
	} while(c == 'Y');

return head;
}

void displayList(LinkList* head)
{
	LinkList* temp = head;

	while(temp != NULL)
	{
		printf(" %d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main()
{
	int choice;
	LinkList *head = NULL;
	char c;
	
	do
	{
		printf("\n\n1. Create a Linked List\n2. Display the Linked List");
		scanf("%d", &choice);

		switch(choice)
		
		{
			case 1: head = createList();
					break;

			case 2: displayList(head);
					break;

			default: printf("\nSelect appropriate choices. (1/2)");
					break;
		}

		printf("\nContinue? ");
		scanf(" %c", &c);

	} while (c == 'y' || c == 'Y');
	return 0;
}