//Write a program to add first seven terms of the following series using a for loop: 1/1! + 2/2! + 3/3!......
#include<stdio.h>

int main()
{
	int length, n, i;
	float sum, fac;
	n = 1;
	sum =0;
	
	printf("Enter the length of the series:");
	scanf("%d", &length);
	
	printf("\n1/1! ");
	
	while(n <= length)
	{
		fac = 1;
		
		// calculate factorial of nth number
		for(i=1; i<=n; i++)
		{
			fac *= i;
		}
		
		// sum of series
		sum += (n/fac);
		
		// increment to next number in series
		n++;
		
		// print series
		if(n <= length)
			 printf("+ %d/%d! ", n, n);
	}

	// print sum of series
	printf(" =  %f", sum);
	printf("\nHence the sum of the series is %f.", sum);
	
	return 0;
}

