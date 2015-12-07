/*Addition two linked lists using recursion by addig zeroes to least number...*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node * add(struct node *, struct node *);
struct node
{
	int data;
	struct node * next;
};

int count(struct node *a)
{
	int count = 0;
	while (a != NULL)
	{
		count++;
		a = a->next;
	}
	return count;
}

struct node * addZeroes(struct node * a,struct node * b,int c1,int c2)
{
	if (c1 < c2)
	{
		b = addZeroes(b, a, c2, c1);
		return b;
	}
	else
	{
		int pos = c2;
		while (pos++ != c1)
		{
			struct node * temp = (struct node *)malloc(sizeof(struct node));
			temp->data = 0;
			temp->next = b;
			b = temp;
		}
		return b;
	}
}

void sumUp(struct node * num1,struct node * num2, int & cary)
{
	num1->data = (num1->data + num2->data + cary);
	cary = (num1->data >= 10) ? 1 : 0;
	if (num1->data >= 10)
	{
		num1->data = num1->data - 10;
	}
	return;
}

void add1(struct node * a, struct node * b,int &cary)
{
	if (a->next == NULL)
		sumUp(a, b, cary);
	else
	{
		add1(a->next, b->next,cary);
		sumUp(a, b, cary);
	}
}

struct node * add(struct node * a, struct node * b)		/*Add function*/
{
	int c = 0,c1 = count(a),c2 = count(b);
	if (c1 < c2)
		a = addZeroes(a, b, c1, c2);
	else
		b = addZeroes(a, b, c1, c2);
	add1(a, b, c);
	if (c != 0)
	{
		struct node * temp = (struct node *)malloc(sizeof(struct node));
		temp->data = c;
		temp->next = a;
		a = temp;
	}
	return a;
}		

struct node * createLinkedList(int * a,int count)
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

void main()
{
	int a[5] = { 9, 9, 9, 9 };
	struct node * new_node = createLinkedList(a, 4);
	int b[4] = { 9, 9, 9, 9 };
	struct node * new_node1 = createLinkedList(b, 4);
	new_node1 = add(new_node1, new_node);
	while (new_node1!= NULL)
	{
		printf("%d", new_node1->data);
		if (new_node1->next != NULL)
			printf(" --> ");
		new_node1 = new_node1->next;
	}
	_getch();
}