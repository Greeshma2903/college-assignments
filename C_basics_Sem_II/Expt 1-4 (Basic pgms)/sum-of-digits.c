// Write program to compute sum of digits of a number and reduce the sum to a single digit.
#include<stdio.h>

int main()
{
	int sum, num, i, lastDigit;
	sum = 0;
	
	printf("Enter a number(which has two-digits or more):");
	scanf("%d", &num);
	
	start:		// calculate sum of digits
		while(num > 0 ){
			lastDigit = num%10;
			sum+= lastDigit;
			num /= 10;
		}
	
	// if sum is a two-digit value, then re-execute above loop till single digit sum
	if(sum > 9)
	{
		num = sum;
		sum = 0;
		goto start;
	}
	
	printf("\nThe sum of the digits is %d.", sum);

	return 0;
}

