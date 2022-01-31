/*
Write a program to allow user to enter a hexadecimal number and print the
decimal and octal equivalent of it.
*/

#include <stdio.h>

int main()
{
	int num;
	
	// read hex value
	printf("Enter a hexadecimal number:");
	scanf("%x", &num);
	
	// use conversion specifiers %d & %o to print decimal anf octal values of number
	printf("\n The Decimal value of number is: %d", num);
	printf("\n\n The Octal value of the number is: %o", num);
	
    return 0;
}

