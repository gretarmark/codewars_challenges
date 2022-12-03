/*
Author: Grétar Már Kjartansson
Date: 01/12/2022
Problem comes from www.codewars.com

Problem Description:
Name: Beginner Series #3 Sum of Numbers

Given two integers a and b, which can be positive or negative, 
find the sum of all the integers between and including them and 
return it. If the two numbers are equal return a or b.

Note: a and b are not ordered!

Examples (a, b) --> output (explanation):
(1, 0) --> 1 (1 + 0 = 1)
(1, 2) --> 3 (1 + 2 = 3)
(0, 1) --> 1 (0 + 1 = 1)
(1, 1) --> 1 (1 since both are same)
(-1, 0) --> -1 (-1 + 0 = -1)
(-1, 2) --> 2 (-1 + 0 + 1 + 2 = 2)
*/

#include <stdio.h>

int get_sum(int a, int b);

int main()
{
	int a,b;
	a = 1;
	b = 2;
	//scanf("%d", &num);

	printf("Sum = %d\n", get_sum(a,b));

	return 0;
}

//My solution
int get_sum(int a, int b) {
	if (a == b )
	{
		return a;
	}
	else
	{
		int sum;

		if (a < b)
		{
			sum = a;

			for (int i = a+1; i <= b; i++)
			{
				sum += i;
			}
		}
		else
		{
			sum = b;

			for (int i = b + 1; i <= a; i++)
			{
				sum += i;
			}
		}

		return sum;
	}
}

//Solutions from another people
int get_sum2(int a, int b) {

	int start = b;
	int finish = a;

	if (a < b) {
		start = a;
		finish = b;
	}

	int sum = 0;
	for (; start <= finish; start++) {
		sum += start;
	}

	return sum;
}

int get_sum3(int a, int b)
{
	return ((a + b) * 0.5) * (abs(a - b) + 1);
}

int get_sum4(int a, int b) {
	if (a == b) {
		return a;
	}
	int max, min;
	max = a > b ? a : b;
	min = a < b ? a : b;
	int sum = 0;

	for (int i = min; i <= max; i++) {
		sum += i;
	}
	return sum;
}

int get_sum5(int a, int b) {
	// Good luck
	if (b < a) {
		a ^= b;
		b ^= a;
		a ^= b;
	}

	return (a + b) / 2.0 * (b - a + 1);
}



