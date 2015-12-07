#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

bool findLoops(struct node * a)
{
	int ans[2];
	node * first = a, *second = a;
	while (first != NULL || second != NULL)
	{
		second = second->next->next;
		first = first->next;
		if (first == second)
			return true;
	}
	return false;
}

void insert(node ** temp, int n)
{
	node * temp1 = (node *)malloc(sizeof(struct node));
	temp1->data = n;
	temp1->next = *temp;
	*temp = temp1;
}

void main()
{
	struct node * head = NULL;
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	head->next->next->next->next = head;
	if (findLoops(head))
		printf("Loop is found...");
	else
		printf("No loops are found...");
	_getch();
}