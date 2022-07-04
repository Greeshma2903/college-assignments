/* 
Write a program to accept 5 numbers and display the sum of their remainders
when you divide the numbers by 3.
*/

#include <stdio.h>

int main()
{
	int num1, num2, num3, num4, num5;
	int sum;

	printf("Enter five numbers:");
	scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

	// Evaluate sum of reminders
	sum = (num1 % 3) + (num2 % 3) + (num3 % 3) + (num4 % 4) + (num5 % 3);

	// display sum 
	printf("\nThe sum of reminders is : %d", sum);

	return 0;
}
