// Write a program to check if a number is a palindrome.
#include<stdio.h>

int main()
{
	int sum, rev, i, num, lastDigit, initialNum;
	sum = 0;
	printf("Enter a number:");
	scanf("%d", &num);
	
	initialNum = num;	// to compare later
	
	// to produce reverse of number
	while(num>0)
	{
		lastDigit = num%10;
		rev = (rev *10) + lastDigit;
		num /= 10;
	}
	
	// if initial number = reversed number, then number is palindrome
	if(initialNum == rev)
	{
		printf("\nThe number %d is a palindrome.", initialNum);
	} 
	else 
	{
		printf("\nThe number is not a palindrome.");
	}
	
	return 0;
}

