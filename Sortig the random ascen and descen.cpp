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
	int ans[100];
}
test[5]=
{
	{ { 1, 2, 3, 4, 8, 7, 6, 5 }, 8, { 1, 2, 3, 4, 5, 6, 7, 8 } },
	{ { 1, 2, 4, 3 }, 4, { 1, 2, 3, 4 } },
	{ { 1, 3, 2 }, 3, { 1, 2, 3 } },
	{ NULL, 0, NULL }
};

void reverseRemaining(node *temp, node *prev, node **head)
{
	if (!temp->next)
	{
		*head = temp;
		temp->next = prev;
		return;
	}
	node *next = temp->next;
	temp->next = prev;
	reverseRemaining(next, temp, head);					/*Linking back to front*/
}
struct node * sort(node * a)
{
	node * temp = a;
	if (a == NULL)
		return NULL;
	while (a->next->data < a->next->next->data)
		a = a->next;
	node * k = a->next;
	reverseRemaining(k, NULL, &k);
	a->next = k;
	return temp;
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

void verify(struct testCases * test, int n)
{
	for (int i = 0; i < n; i++)
	{
		struct node * a1 = createLinkedList(test[i].a, test[i].n);
		node * temp = a1;
		printf("Question : ");
		while (a1 != NULL)
		{
			printf(" %d ", a1->data);
			if (a1->next != NULL)
				printf(" --> ");
			a1 = a1->next;
		}
		printf("\nExpected answer : ");
		a1 = createLinkedList(test[i].ans, test[i].n);
		while (a1 != NULL)
		{
			printf(" %d ", a1->data);
			if (a1->next != NULL)
				printf(" --> ");
			a1 = a1->next;
		}
		temp = sort(temp);
		a1 = temp;
		printf("\nAnswer :   ");
		while (a1 != NULL)
		{
			printf(" %d ", a1->data);
			if (a1->next != NULL)
				printf(" --> ");
			a1 = a1->next;
		}
		printf("\n\n");
	}
}


void main()
{
	/*int a[6] = { 1, 2, 3, 6, 5, 4 };
	node * k = createLinkedList(a, 6);
	sort(k);
	while (k != NULL)
	{
		printf("%d", k->data);
		if (k->next != NULL)
			printf(" --> ");
		k = k->next;
	}*/
	verify(test, 4);
	_getch();
}