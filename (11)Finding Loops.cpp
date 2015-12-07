#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node * next;
	bool count;
};

int * findLoop(struct node * temp)
{
	while (1)
	{
		if (temp->next->count == true)
			break;
		temp->count = true;
			temp = temp->next;
	}
	int * a = (int *)malloc(sizeof(int)*2);
	a[0] = temp->num;
	a[1] = temp->next->num;
	return a;
}

void main()
{
	int count = 0;
	struct node * temp = NULL;
	struct node * head = (struct node *)malloc(sizeof(struct node)), *new_node = head, *address = (struct node *)malloc(sizeof(struct node));
	printf("Enter the maximum numbers :");
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &temp->num);
		temp->next = NULL;
		if (temp->num == 3)
			address = temp;
		head->next = temp;
		head = head->next;
	}
	head->next = address;
	int * a = findLoop(new_node->next);
	printf("Loop formed at : %d\nCorrupted node : %d", a[0],a[1]);
	_getch();
}