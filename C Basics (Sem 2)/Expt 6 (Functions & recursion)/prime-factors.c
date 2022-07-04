/*
A positive integer is entered through the keyboard. Write a function to obtain the
prime factors of this number. For example, prime factors of 24 are 2, 2, 2 and 3,
whereas prime factors of 35 are 5 and 7.
*/

#include <stdio.h>

int main()
{
	int findPrimeFactors(int num); // function declaration

	int num;
	printf("Enter the number whose prime factors are to be found:");
	scanf("%d", &num);

	printf("The prime factors of %d are:\n", num);
	findPrimeFactors(num);
	return 0;
}

int findPrimeFactors(int n)
{
	int i;
	// check for even factor 2
	while (n % 2 == 0)
	{
		printf("2\n");
		n /= 2;
	}

	// Check other odd factors
	for (i = 3; i <= n; i = i+2)
		while (n % i == 0)
		{
			// If number divisible by i, then it is number's prime factor
			printf("%d\n", i);

			// reduce the number
			n /= i;
		}
}



