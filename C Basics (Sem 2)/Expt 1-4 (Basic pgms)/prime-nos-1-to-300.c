//Write a program to print all prime numbers from 1 to 300. (Hint: Use nested loops, break and continue)
#include<stdio.h>

int main()
{
	int num = 2;
	int i;
	int count = 0;
	
	printf("The prime numbers between 1 and 300 are:\n");
	
	
	while(num <= 300)
	{
		// verify prime number
		for(i=2; i<=num/2; i++)
		{
			if(num%i == 0)
			{
				count++;
				break;
			}
		}	
		
		// check if number is prime and print 
		if(count == 0)
		{
			printf("%d ", num);
		} 
		else {
			count = 0;	// if number not prime reset count
		}
		
		// increment number
		num++;
	}	

	return 0;
}

