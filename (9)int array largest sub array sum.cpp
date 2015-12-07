#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int * maxSubArraySum(int a[], int size)
{
	int temp_i = 0, temp_j = 0;
	int result[3];
	result[0] = 0, result[1] = 0;
	int max_temp = a[0];
	int max_value = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] > a[i] + max_temp)						/*Comparing present value with previous temp sum*/
		{
			temp_i = i;
			max_temp = a[i];
		}
		else
		{
			max_temp = a[i] + max_temp;
		}		
		if (max_value < max_temp)						/*Comparnig present temp and maximum temp*/
		{
			max_value = max_temp;
			result[0] = temp_i;
			result[1] = i;
		}
	}
	result[2] = max_value;
	return result;
}

/* Driver program to test maxSubArraySum */
int main()
{
	int a[] = { 1, -2, 4, 7, 6, -5, -13, 1, 8, 14 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	int * max_sum = maxSubArraySum(a, n);
	printf("\nMaximum sum is %d and is formed between the places %d and %d", max_sum[2],max_sum[0],max_sum[1]);
	_getch();
}