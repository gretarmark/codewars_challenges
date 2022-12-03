/*
Author: Grétar Már Kjartansson
Date: 30/11/2022
Problem comes from www.codewars.com

Problem Description:
Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, 
continue reducing in this way until a single-digit number is produced. The input 
will be a non-negative integer.

Example:
    16  -->  1 + 6 = 7
   942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
*/



#include <stdio.h>




int digital_root(int n);
int digital_root2(int Z); //Solution from another people on codewars


int main()
{
	int num;
	num = 493193;
	//scanf("%d", &num);

	printf("Sum of digits = %d\n", digital_root(num));
	printf("Sum of digits 2 = %d\n", digital_root2(num));

	return 0;
}

int digital_root(int n) {

	int sumDig = 0;

	if(n < 0) //n cannot be less than 0
	{
		n = n * (-1);
	}

	while(n > 0)
	{	
		int mod = n % 10; //Split the last digit from a number
		sumDig += mod;
		n = n / 10;
	}

	//Check if the number have more than one digit
	if (sumDig < 10 && sumDig > 0)
	{
		return sumDig;
	}
	else
	{
		return digital_root(sumDig);
	}
}

int digital_root2(int Z) {
	return --Z % 9 + 1;
}

