// factorial using goto
#include<stdio.h>

int main() {
	
	int num;
	
	// read number
	printf("\n Enter a number:");
	scanf("%d", &num);
	
	int fact = 1;
	int count = 1;
	
	// calculate factorial
	first:	
		fact *= count;
		count ++;		// increment counter
		
	if (count <= num) 	// goto condition
 	   goto first;
	
	printf("\n\t The factorial of %d is: %d", num, fact);	
	
	return 0;
}
