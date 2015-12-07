#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

/*n1,n2,n3,n4,.....*/

int gcd(int a, int b)								/*GCD of two numbers*/
{
	if (a == 0 || b == 0)
		return 0;
	if (a >= b)
	{
		int c = a%b;
		while (c != 0)
		{
			a = b;
			b = c;
			c = a%b;
		}
		return b;
	}
	else
		return gcd(b, a);
}

int gcd_of_three(int a, int b, int c)
{
	int temp = gcd(a, b);
	return gcd(temp, c);
}

int lcm_t(int a, int b)				/*LCM of two numbers */
{
	if (a == 0 || b == 0 )
		return 0;
	int k = gcd(a, b), lcm = 1;
	while (k != 1)									/*No further division*/
	{
		lcm = lcm*k;
		a /= k;
		b /= k;
		k = gcd(a,b);
	}
	return lcm*a*b;									/*General LCM*/
}

int lcm_of_three_numbers(int a, int b,int c)				/*LCM of two numbers */
{
	if (a == 0 || b == 0 || c == 0)
		return 0;
	int k = gcd_of_three(a, b, c), lcm = 1;
	while (k != 1)									/*No further division*/
	{
		lcm = lcm*k;
		a /= k;
		b /= k;
		c /= k;
		k = gcd_of_three(a, b, c);
	}
	return lcm*a*b*c;									/*General LCM*/
}

int min(int a, int b, int c)
{
	return ((a < b&&a < c) ? a : (b < c)?b : c);
}

int generate(int a, int b,int c, int k)
{
	int lcm = lcm_of_three_numbers(a, b, c);
	int k1 = a, k2 = b, k3 = c, n = 0;
	int pos = k%lcm, temp = 0;
	int count = (lcm / a) + (lcm / b) + (lcm / c) - (lcm / lcm_t(a, b)) - (lcm / lcm_t(a, c));
	while (n < k%count)								/*Generating the number below the L.C.M.*/
	{
		if (k1 < k2 && k1 < k3)
		{
			temp = k1;
			k1 += a;
		}
		else if (k2 < k3)
		{
			temp = k2;
			k2 += b;
		}
		else
		{
			temp = k3;
			k3 += c;
		}
		if (k1 == k2)
		{
			k2 += b;
		}
		if (k1 == k3)
			k3 += c;
		if (k2 == k3)
		{
			k2 += b; k3 += c;
		}
		n++;
	}
	return temp + (lcm)*(k / count);
}

void main()
{
	int a, b, pos;
	for (int i = 0; i < 20; i++)
		printf("%d  -->  %d \n", i, generate(3, 4, 5 , i));
	_getch();
}