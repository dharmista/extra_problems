/*Inserting elements in linked list*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node * next;
};

struct node * insert(struct node * head,int k)
{
	struct node * temp = head, *temp2 = NULL, *mainLl = head;			/*Test cases*/
	if (temp == NULL)									/*Empty linked list*/
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->num = k;
		temp->next = temp;
		return temp;
	}
	if (head->next == head)								/*Only one element in linked list*/
	{
		if (temp->num >= k)
		{
			temp2 = (struct node *)malloc(sizeof(struct node));
			temp2->num = k;
			temp2->next = temp;
			temp->next = temp2;
			head = temp2;
			return head;
		}
		else
		{
			temp2 = (struct node *)malloc(sizeof(struct node));
			temp->next = temp2;
			temp2->next = temp;
			return temp;
		}
	}
	else
	{
		if (k < temp->num)								/*Insert at beginning of the linked list*/
		{
			temp2 = (struct node *)malloc(sizeof(struct node));
			temp2->num = k;
			temp2->next = temp;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = temp2;
			mainLl = temp2;
			return mainLl;
		}
		while (temp->next != NULL)						/*Inserting at middle of linked list*/
		{
			if (temp->num < k && k <= temp->next->num)
			{
				temp2 = (struct node *)malloc(sizeof(struct node));
				temp2->num = k;
				temp2->next = temp->next;
				temp->next = temp2;
				return mainLl;
			}
			temp = temp->next;
		}
		if (temp->num < k)								/*Inserting at the end of linked list*/
		{
			temp2 = (struct node *)malloc(sizeof(struct node));
			temp2->num = k;
			temp->next = temp2;
			temp2->next = head;
			return mainLl;
		}
	}
}

void main()
{
	int count = 0;
	struct node * temp = NULL;
	struct node * head = NULL, *new_node = head, *start = head;
	printf("Enter the maximum numbers :");
	scanf("%d", &count);
	printf("Insert the number u want to insert :");
	int numb;
	scanf("%d", &numb);
	printf("Enter the numbers :\n");
	for (int i = 0; i < count; i++)							
	{
		if (head == NULL)								
		{
			head = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &head->num);
			head->next = NULL;
			new_node = head;
		}
		else
		{
			temp = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &temp->num);
			temp->next = NULL;
			head->next = temp;
			head = head->next;
		}
	}
	printf("\n");
	new_node = insert(new_node,numb);
	printf("Linked list after insertion of given element : \n\n\n");
	for (int i = 0; i < (count+1)*2;i++)
	{
		printf("%d ", new_node->num);
		if (i + 1 < (count + 1) * 2)
			printf("--> ");
		else
			printf("...");
		new_node = new_node->next;
	}
	_getch();
}