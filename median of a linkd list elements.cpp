#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

struct testCases
{
	int a[100];
	int n;
	float ans;
}
test[5]=
{
	{ { 1, 2, 3, 4, 5, 6 }, 6, 3.5 },
	{ { 1, 2 }, 2, 1.5 },
	{ { 1 }, 1, 1 },
	{ { 1, 2, 3, 4, 5, 6, 7 }, 7, 4.0 },
	{ NULL, 0, NULL }
};

float median(struct node * temp)
{
	if (temp == NULL)
		return NULL;
	node * first=temp, * second=temp;
	while (1)												/*Infinate loop*/
	{
		if (second->next == NULL)							/*For odd numbes*/
		{
			return (float)first->data;
		}
		if (second->next->next == NULL)						/*For even numbers*/
		{
			return (float)(first->data + first->next->data) / 2;
		}
		first = first->next;								/*Shifting the first pointer*/
		second = second->next->next;						/*Shifting the second pointer*/
	}
}

struct node * createLinkedList(int * a, int count)
{
	if (a == NULL)
		return NULL;
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

void verify(struct testCases * k, int n)
{
	for (int i = 0; i < n; i++)
	{
		node * temp = createLinkedList(k[i].a, k[i].n);
		if (median(temp) == k[i].ans)
			printf("Passed - %d\n", i + 1);
		else
			printf("Failed - %d\n", i + 1);
	}
}

void main()
{
	verify(test, 5);
	_getch();
}