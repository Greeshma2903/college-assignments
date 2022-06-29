// check if number is prime: using goto

#include <stdio.h>

int main() {
	int num;
	
	// read a number
	printf("\nEnter a number:");
	scanf("%d", &num);
	
	int count = 0, i=2;
	
	start:					// checking primality
		if(num % i==0){
			count++;		// flag increment
			goto result;	// skip to 'result:' label if number not prime
		}
		i++;
		
		if(i <= num/2)		// goto condition
	 		 goto start;
		
	result:							// print number is prime or not prime
		if(count != 0){
				printf("\n The number is Not prime");
		} else {
			printf("\nThe number is Prime");
		}
		
	
	return 0;
}

