/*Uses swap() to swap numbers and reverse the numbers*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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

struct node * reverse12(struct node * a, struct node * b,int &count,int & present)
{
	if (a->next == NULL)
	{
		swap(&a->data, &b->data);
		b = b->next;
		return b;
	}
	else
	{
		count++;
		b = reverse12(a->next, b,count,present);
		if (count / 2 == present)
			return b;
		present++;
		swap(&a->data, &b->data);
		b = b->next;
	}
	return b;
}




void reverse(node **head)
{
	int count = 1, present = 1;
	if (head == NULL)
		return;
	reverse1(*head, NULL, head);
}

void main()
{
	int count = 0;
	struct node * temp = NULL;
	struct node * head = NULL, *new_node = head;
	for (int i = 0; i < 4; i++)
	{
		if (head == NULL)
		{
			head = (struct node *)malloc(sizeof(struct node));
			head->data = i + 3;
			head->next = NULL;
			new_node = head;
		}
		else
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = i + 3;
			temp->next = NULL;
			head->next = temp;
			head = head->next;
		}
	}
	struct node **b = &new_node;
	reverse(b);
	while (new_node != NULL)
	{
		printf("%d", new_node->data);
		if (new_node->next != NULL)
			printf(" --> ");
		new_node = new_node->next;
	}
	_getch();
}