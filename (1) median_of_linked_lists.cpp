#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct test
{
	int a[100];
	int n;
	float ans;
}
test[3]=
{
	{ { 1, 2, 3, 4, 5 },5,3.0 },
	{ { 1, 2, 3, 4 },4,2.5 },
	{ { -4, -3, -2, -1, 0, 1, 2, 3, 4 },9,0 }
};

struct node
{
	int num;
	struct node * next;
};


float median(struct node * head)
{
	int n = 0;
	struct node * temp = head;
	while (head->next != NULL)
	{
		head = (head->next);
		n++;
	}
	if (n % 2 != 0)								/*Odd number*/
	{
		n /= 2;
		while (n != 0)
		{
			temp = temp->next;
			n--;
		}
		return temp->next->num;
	}
	else
	{
		n /= 2;
		while (n != 0)
		{
			temp = temp->next;
			n--;
		}
		return (float)(temp->num + (temp->next)->num) / 2;
	}
}

void verify(struct test * test,int n)
{
	for (int i = 0; i < n; i++)
	{
		struct node * temp = NULL;
		struct node * head = (struct node *)malloc(sizeof(struct node)), *new_node = head;
		for (int i = 0; i < test[i].n; i++)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->num = test[i].a[i];
			temp->next = NULL;
			head->next = temp;
			head = head->next;
		}
		float f = median(new_node);
		if (f == test[i].ans)
			printf("Passed - %d\n", i + 1);
		else
			printf("Failed - %d\n", i + 1);
	}
}

void main()
{
	int count = 0;
	struct node * temp = NULL;
	struct node * head = (struct node *)malloc(sizeof(struct node)), *new_node = head;
	printf("Enter the maximum numbers :");
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &temp->num);
		temp->next = NULL;
		head->next = temp;
		head = head->next;
	}
	printf("Median of given list : %.3f", median(new_node));
	//verify(test, 3);
	_getch();
}
