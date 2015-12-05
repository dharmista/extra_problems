#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<io.h>

struct node
{
	int data;
	struct node * next;
};

void swap(int * a, int * b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void reverse(node *temp, node *prev, node **head)
{
	if (!temp->next)
	{
		*head = temp;
		temp->next = prev;
		return;
	}
	node *next = temp->next;
	temp->next = prev;
	reverse(next, temp, head);					/*Linking back to front*/
}


void main()
{
	int count = 0;
	struct node * temp = NULL;
	struct node * head = NULL, *new_node = head;
	printf("Enter the maximum numbers :");
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		if (head == NULL)
		{
			head = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &head->data);
			head->next = NULL;
			new_node = head;
		}
		else
		{
			temp = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &temp->data);
			temp->next = NULL;
			head->next = temp;
			head = head->next;
		}
	}
	reverse(new_node, NULL, &new_node);
	while (new_node != NULL)
	{
		printf("%d --> ", new_node->data);
		new_node = new_node->next;
	}
	_getch();
}