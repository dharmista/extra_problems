#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void lastKLines1(char * filename,int p)
{
	FILE * k = fopen(filename,"r");
	int count = 0;
	while (!feof(k))					/*End of file*/
	{
		char ch = getc(k);
		if (ch == '\n')
			count++;
	}
	int maincount = count - p;
	fclose(k);
	FILE * k1 = fopen(filename, "r"); int i = 0;
	while (!feof(k1))
	{
		char ch = getc(k1);
		if (ch == '\n')
			i++;
		if (i>maincount)
			printf("%c", ch);
	}
	fclose(k1);
}

void lastKLines(char * filename, int p)
{
	FILE * first = fopen(filename, "r");
	int count1 = 0;
	FILE * second= fopen(filename, "r");
	while (!feof(second), count1 != p)				/*Incrementing the second pointer to maintain difference*/
	{
		char ch = getc(second);
		if (ch == '\n')
			count1++;
	}
	while (!feof(second))
	{
		char ch1 = 'a';
		while (ch1 != '\n')							/*Incrementing the first pointer*/
		{
			ch1 = getc(first);
		}
		char ch2 = 'a';
		while ((ch2 != '\n'))						/*Incrementing the second pointer*/
		{
			if (feof(second))
				break;
			ch2 = getc(second);
		}
	}
	while (!feof(first))							/*Printing the lines*/
	{
		printf("%c", getc(first));
	}
}

void main()
{
	lastKLines("1.txt",4);
	_getch();
}