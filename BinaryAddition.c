/*
Author: Grétar Már Kjartansson
Date: 01/12/2022
Problem comes from www.codewars.com

Problem Description:
Name: Binary Addition
kyu: 7

Implement a function that adds two numbers together and returns their 
sum in binary. The conversion can be done before, or after the addition.

The binary number returned should be a string.

Examples:(Input1, Input2 --> Output (explanation)))

1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)

for 4294967295 + 4294967295, expected:
"111111111111111111111111111111110"
but got:
"11111111111111111111111111111110"
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

typedef unsigned long long ull;
typedef unsigned long ul;

char* binary_add(unsigned a, unsigned b, char* binary);
unsigned bitlen(ull n);
char* binary_add2(unsigned a, unsigned b, char* binary);
char* binary_add3(unsigned a, unsigned b, char* binary);
char* binary_add4(unsigned a, unsigned b, char* binary);

int main()
{
	unsigned a, b;
	a = 4294967295;
	b = 4294967295;
	// a+b = 5 should give 0101.
	//scanf("%d", &num);

	//char dec[] = {'1','1','\0'};
	//char *dec = malloc(40 * sizeof(char));

	printf("Sum = %s\n", binary_add(a, b, "111111111111111111111111111111110"));
	//printf("Sum = %s\n", dec);

	return 0;
}


//My solution

/* Not a good function, use the next one
char* binary_add(unsigned a, unsigned b, char* binary)
{

	long sum = a + b;

	if (sum == 0)
	{
		binary[0] = '0';
		binary[1] = '\0';
	}
	else
	{
		int temp;
		char str_val;

		int i = 0;
		for (; sum > 0; )
		{
			temp = sum % 2;
			sprintf_s(&str_val, "%d", temp);
			binary[i++] = str_val;
			sum /= 2;
		}

		size_t len = strlen(binary);
		char temp2;

		for (int p = 0; p < len; p++)
		{
			len--;
			temp2 = binary[p];
			binary[p] = binary[len];
			binary[len] = temp2;
		}
	}


	return binary;
}
*/


char* binary_add(unsigned a, unsigned b, char* binary)
{
	unsigned long long sum = (unsigned long long)a + (unsigned long long)b;

	if (sum == 0)
	{
		binary[0] = '0';
		binary[1] = '\0';
		return binary;
	}
	else
	{
		unsigned long long temp;
		//char str_val;

		int i = 0;
		for (; sum > 0; i++)
		{
			//temp = sum % 2;
			//sprintf(&str_val, "%d", temp);
			//binary[i++] = str_val;
			binary[i] = sum % 2 + '0';
			sum /= 2;
		}
		binary[i] = '\0';

		if (i == 1) { return binary; }

		unsigned long long len = strlen(binary);
		char temp2;

		for (int p = 0; p < len; p++)
		{
			len--;
			temp2 = binary[p];
			binary[p] = binary[len];
			binary[len] = temp2;
		}
	}


	return binary;
}



/* This is what was closest to the solution
#include <stdio.h>
#include <string.h>

char *binary_add (unsigned a, unsigned b, char *binary)
{
int sum = a + b;
	int k, j;
	//int i;

	//for (i = 0; *binary != '\0'; i++)
	//{
	//}
	int length_binary = strlen(binary);

	for (j = length_binary+1; j >= 0; j--)
  {
		k = sum >> j;
		if (k & 1)
		{
			binary[length_binary++] = '1';
			binary[length_binary] = '\0';
		}
		else
		{
			binary[length_binary++] = '0';
			binary[length_binary] = '\0';
		}
	}
	// write to the binary string and return it
	//*binary = '\0';
	//*binary = dec;
	return binary;
}
*/

//****************Solutions from other people*********************

// Best solution:
unsigned bitlen(ull n)
{
	return (n == 0) ? 0 : (1 + bitlen(n >> 1));
}

char* binary_add2(unsigned a, unsigned b, char* binary)
{
	ull sum = (ull)a + (ull)b;
	unsigned length = (sum == 0) ? 1 : bitlen(sum);

	for (int i = length - 1; i >= 0; i--) {
		binary[i] = '0' + (sum & 1);
		sum >>= 1;
	}
	binary[length] = '\0';
	return binary;
}

// Second best solution:
char* binary_add3(unsigned a, unsigned b, char* binary)
{
	ul sum = (ul)a + (ul)b, i = 1UL << 63;
	char* p = binary;

	// find where most significant bit set to one in sum begins
	while (!(i & sum) && i) i >>= 1;

	// compare every bit in the sum and write to char string
	do *(p++) = sum & i ? '1' : '0'; while (i >>= 1);

	*p = '\0';

	return binary;
}

//Thirs best solution:
char* binary_add4(unsigned a, unsigned b, char* binary)
{
	ull c = (ull)a + (ull)b;
	if (!c) {
		binary[0] = '0';
		binary[1] = '\0';
		return binary;
	};
	int j = floor(log2(c));
	binary[j + 1] = '\0';
	while (c) {
		binary[j--] = (c % 2) + '0';
		c /= 2;
	}

	return binary;
}
