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

int lcm_of_two_numbers(int a, int b)				/*LCM of two numbers */
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
	return lcm*a*b;									/*General LCM*/
}

int generate(int a, int b, int k)
{
	int lcm = lcm_of_two_numbers(a, b);
	int k1 = a, k2 = b, n = 0;
	int pos = k%lcm, temp = 0;
	int count = (lcm / a) + (lcm / b) - 1;
	while (n < k%count)								/*Generating the number below the L.C.M.*/
	{
		if (k1 < k2)
		{
			temp = k1;
			k1 += a;
		}
		else
		{
			temp = k2;
			k2 += b;
		}
		n++;
	}
	return temp+(lcm)*(k/count);  
}

void main()
{
	int a, b, pos;
	for (int i = 0; i < 20; i++)
		printf("%d  -->  %d \n",i,generate(3,5,i));
	_getch();
}