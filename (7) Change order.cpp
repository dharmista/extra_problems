#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data;
	struct node * next;
};

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void arrange(struct node * curr)
{
	if (curr == NULL || curr->next == NULL)				/*If list is empty*/
		return;
	struct node * a = NULL, *b  = NULL;
	while (curr->next != NULL)
	{
		if (curr->data < curr->next->data);
		else
		{
			a = curr;
			break;
		}
		curr = curr->next;
	}
	curr = curr->next;
	if (a == NULL)										/*If the list is perfect*/
		return;
	if (curr->next == NULL)								/*If the mistake is found at end of list*/
	{
		swap(&a->data, &curr->data);
		return;
	}
	while (curr->next != NULL)
	{
		if (curr->data < curr->next->data);
		else
		{
			b = curr->next;								
			break;
		}
		curr = curr->next;
	}
	swap(&a->data, &b->data);							/*Swapping the address at which data is present*/
}

void main()
{
	int count = 0;
	struct node * temp = NULL;
	struct node * head = NULL, *new_node = head;
	int a[7] = { 1,2,3,4,5,6,7};
	for (int i = 0; i < 7; i++)
	{
		if (head == NULL)
		{
			head = (struct node *)malloc(sizeof(struct node));
			head->data = a[i];
			head->next = NULL;
			new_node = head;
		}
		else
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = a[i];
			temp->next = NULL;
			head->next = temp;
			head = head->next;
		}
	}
	arrange(new_node);
	while (new_node != NULL)
	{
		printf("%d", new_node->data);
		if (new_node->next != NULL)
			printf(" --> ");
		new_node = new_node->next;
	}
	_getch();
}