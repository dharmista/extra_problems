#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int gcd(int a, int b)
{
	if (a > b)
		return gcd(b, a);
	else
	{
		int c = b%a;
		while (c != 0)
		{
			b = a;
			a = c;
			c = b%a;
		}
		return a;
	}
}

int gcd_of_n_numbers(int * a, int n)
{
	int i = 0, g = 1;
	while (i < n)
	{
		g = gcd(g, a[i]);
		i++;
	}
	return g;
}


int lcm_of_two(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	int k = gcd(a, b), lcm = 1;
	while (k != 1)									/*No further division*/
	{
		lcm = lcm*k;
		a /= k;
		b /= k;
		k = gcd(a, b);
	}
	return lcm*a*b;
}

int lcm_of_n_numbers(int * a, int n)							//LCM of n numbers
{
	int lcm = 1;
	for (int i = 0; i < n; i++)
	{
		lcm = lcm_of_two(lcm, a[i]);
	}
	return lcm;
}

int minimum_of_int_array(int * a, int n)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[ret] > a[i])
			ret = i;
	}
	return ret;
}

int generate(int * a,int n, int k)
{
	int * b = (int *)malloc(sizeof(int)*n);
	int lcm = lcm_of_n_numbers(a, n);
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	int part1 = 0, part2 = 0;
	for (int i = 0; i < n; i++)
	{
		part1 += (lcm / a[i]);
	}
	for (int i = 1; i < n; i++)
	{
		part2 += (lcm / lcm_of_two(a[0], a[i]));
	}
	int count = part1 - part2;
	int pos = k%lcm, temp = 0;
	int p = 0;
	while (p < k%count)								/*Generating the number below the L.C.M.*/
	{
		int temp_pos = minimum_of_int_array(b, n);
		temp = b[temp_pos];
		b[temp_pos] = b[temp_pos] + a[temp_pos];
		for (int i = 0; i < n; i++)
		{
			if (b[temp_pos] == b[i])
				b[i] += a[i];
		}
		p++;
	}
	return temp + (lcm)*(k / count);
}

void main()
{
	int a[4] = { 3, 5,6,8 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d", generate(a,size,10));
	_getch();
}