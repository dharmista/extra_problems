/*Sorting two linked lists which are in asceding order*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node * next;
};

int length(struct node * a)
{
	int count = 0;
	while (a->next != NULL)
	{
		count++;
		a = a->next;
	}
	return count;
}

struct node * merge(struct node * pt1, struct node * pt2)
{
	if (length(pt1) >= length(pt2))					/*Merging smallest length linked list with largest one*/
	{
		struct node * ans = pt1, *temp2 = NULL;
		struct node * temp = (struct node *)malloc(sizeof(struct node));
		if (pt1 == NULL)							/*If first linked list is NULL*/
		{
			pt1 = pt2;
			return pt1;
		}
		while (pt2 != NULL)							/*If second linked list is NULL*/
		{
			if (pt1 == NULL)						/*Pointer 1 NULL inn process*/
			{
				pt1->next = pt2;
				break;
			}
			if (pt1->num > pt2->num)				/*Pointer 1 > pointer 2*/
			{
				if (temp2 == NULL)					/*temp2 is just a processing element*/
				{
					temp = pt2->next;
					pt2->next = pt1;
					pt1 = pt2;
					pt2 = temp;
					temp2 = pt1;
				}
				else
				{
					temp = pt2->next;
					temp2->next = pt2;
					pt2->next = pt1;
					pt2 = temp;
				}
			}
			if (pt1->next == NULL && pt2 != NULL)
			{
				pt1->next = pt2;
				break;
			}
			if (pt2 == NULL || pt1->next == NULL)	/*If the second linked list is empty (or) If there are no elements in linked list 1*/
				break;
			else if ((pt1->num <= pt2->num) && (pt1->next->num >= pt2->num))
			{										/*Inserting element in linked list-2 to linked list-1*/
				temp = pt2->next;
				pt2->next = pt1->next;
				pt1->next = pt2;
				pt2 = temp;
			}
			pt1 = pt1->next;
		}
		return ans;
	}
	else
		return merge(pt2, pt1);
}

void main()
{
	int count = 0;
	struct node * temp = NULL;
	struct node * head = NULL, *new_node = head;
	printf("Enter the maximum numbers :");
	scanf("%d", &count);
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
	int count1 = 0;
	struct node * temp1 = NULL;
	struct node * head1 = NULL, *new_node1 = head1;
	printf("Enter the maximum numbers :");
	scanf("%d", &count1);
	for (int i = 0; i < count1; i++)
	{
		if (head1 == NULL)
		{
			head1 = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &head1->num);
			head1->next = NULL;
			new_node1 = head1;
		}
		else
		{
			temp1 = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &temp1->num);
			temp1->next = NULL;
			head1->next = temp1;
			head1 = head1->next;
		}
	}
	struct node * k = merge(new_node, new_node1);
	while (k != NULL)
	{
		printf("%d ", k->num);
		k = k->next;
		if (k!= NULL)
			printf(" --> ");
	}
	_getch();
}