/*Addition of two linked lists reversing them --> Adding --> Again reversing the answer*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * next;
};

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

struct node * createLinkedList(int * a, int count)
{
	struct node * temp = NULL;
	struct node * head = NULL, *new_node = head;
	for (int i = 0; i < count; i++)
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
	return new_node;
}

void sumUp(struct node * num1, struct node * num2, int & cary)
{
	num1->data = (num1->data + num2->data + cary);
	cary = (num1->data >= 10) ? 1 : 0;
	if (num1->data >= 10)
	{
		num1->data = num1->data - 10;
	}
	return;
}

void addLl(node * a, node * b, int & cary)
{
	while (a != NULL , b != NULL)
	{
		sumUp(a, b, cary);
		a = a->next;
		b = b->next;
	}
}

struct node * add(node * a, node * b)
{
	reverse(a, NULL, &a);
	reverse(b, NULL, &b);
	int cary = 0;
	addLl(a, b, cary);
	reverse(a, NULL, &a);
	if (cary != 0)
	{
		struct node * temp = (node *)malloc(sizeof(struct node));
		temp->data = cary;
		temp->next = a;
		a = temp;
	}
	return a;
}

void main()
{
	int a[5] = { 9, 2, 3, 4, 5 };
	int b[5] = { 3, 4, 5 };
	struct node * s1 = createLinkedList(a, 5);
	struct node * s2 = createLinkedList(b, 3);
	struct node * k = add(s1, s2);
	while (k != NULL)
	{
		printf(" %d ", k->data);
		if (k->next != NULL)
			printf("-->");
		k = k ->next;
	}
	_getch();
}