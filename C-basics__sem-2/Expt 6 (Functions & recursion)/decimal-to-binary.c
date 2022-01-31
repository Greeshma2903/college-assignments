/*
A positive integer is entered through the keyboard, write a function to find the
binary equivalent of this number :
(1) Without using recursion
(2) Using recursion
*/

#include <stdio.h>

int main()
{
	// function declarations
    void convertToBinary(int num);
    int convertToBinaryRecursion(int n);

    int number;
    printf("--- Covert integer to it's binary form ---\n");

    printf("Without Recursion:-\n");
    printf("Enter integer:");
    scanf("%d", &number);
    
//	print the binary form of number
    printf("Binary form of %d is: ", number);
    convertToBinary(number);
    
    printf("Binary form of (using recursion) %d is: ", number);
    int value = convertToBinaryRecursion(number);
    printf("%d", value);

    return 0;
}

void convertToBinary(int num)
{
    int binary = 0;
    int digit, c = 1;

    // Convert to binary
    while (num != 0)
    {
        // collect reminder
        digit = num % 2;
        binary = binary + (digit * c);
        c *= 10;
        num /= 2;
    }
    printf("%d\n", binary);
}

int convertToBinaryRecursion(int n)
{
    if (n==0)
        return 0;
    else
        return ((n % 2)+ 10 * convertToBinaryRecursion(n/2));
}

// printf("digit:%d\n", digit);
