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
test[5] =
{
	{ { 1, 2, 3, 9, 8, 7, 1, 2, 3 }, 9, { 1, 1, 2, 2, 3, 3, 7, 8, 9 } },			       //[Ascen, Descen, Ascen]
	{ { 1, 2, 4, 3, 1, 2, 3, 4, 7, 6, 5 }, 11, { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 7 } },      //[Ascen, Descen, Ascen, Descen]
	{ { 1, 3, 2 }, 3, { 1, 2, 3 } },
	{ { 1, 2, 3, 4, 7, 6, 5, 8, 9, 10 }, 10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } },		   //With no duplicates
	{ NULL, 0, NULL }
};

node * addFromBeginning(node * a, node * temp)								/*Add to the beginning of the linked list*/
{
	node * k = temp, *k2 = temp;
	node * temp1 = (node *)malloc(sizeof(node));
	temp1->data = a->data;
	temp1->next = NULL;
	if (temp == NULL)
		temp = temp1;
	else if (temp->next == NULL)
	{
		if (temp->data <= temp1->data)
		{
			temp->next = temp1;
		}
		else
		{
			temp1->next = temp;
			temp = temp1;
		}
	}
	else
	{
		while (temp->next!=NULL)
		{
			if ((temp->data <=temp1->data) && (temp1->data <= temp->next->data))
			{
				temp1->next = temp->next;
				temp->next = temp1;
				return k;
			}
			else
				temp = temp->next;
		}
		while (k2->next != NULL)
			k2 = k2->next;
		k2->next = temp1;
		return k;
	}
	return temp;
}

void addANode(node * a, node * ret,node * temp)
{
	ret = temp;
	node * temp1 = (node *)malloc(sizeof(node));
	temp1->data = a->data;
	temp1->next = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = temp1;
	temp = temp->next;
}

node * addFromEnd(node * a, node * temp, node * ret)								/*Adds to end of the linked list*/
{
	if (a->next == NULL)													
	{
		addANode(a, ret, temp);
		return ret;
	}
	else if (a->next->next == NULL)
	{
		temp = addFromEnd(a->next, temp, ret);
		addANode(a, ret, temp);
		return ret;
	}
	else if ((a->data > a->next->data && a->next->data <= a->next->next->data))
	{
		addANode(a, ret, temp);
		return ret;
	}
	else
	{
		temp = addFromEnd(a->next, temp, ret);
		addANode(a, ret, temp);
		return ret;
	}
	return temp;
}

struct node * sort(node * a)
{
	node * temp = NULL;
	while (a != NULL)
	{
		if (a->next == NULL)												// If there is only single element in list
			temp = addFromBeginning(a, temp);
		else if (a->data < a->next->data)									// If [1 *] --> [2 *]
			temp = addFromBeginning(a, temp);
		else
		{
			temp = addFromEnd(a, temp, temp);
			if (a->next == NULL || a->next->next == NULL)
				return temp;
			if (a->next != NULL)
			{
				while (a->next->data > a->next->next->data)
				{
					a = a->next;
					if (a->next == NULL || a->next->next == NULL)
						return temp;
				}
			}
		}
		a = a->next;
	}
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
	verify(test, 5);
	_getch();
}