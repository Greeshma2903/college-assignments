// Fibonacci series: goto
#include <stdio.h>

int main() {
	int num;
	int a = 0, b = 1, i= 2, sum;
	
	// read limit
	printf("Enter fibonacci limit:");
	scanf("%d", &num);
	
	// generate fibonacci series based on limit
	if(num == 1) 
		 printf("%d", a);
	else if(num == 2) 
		 printf("%d %d", a, b);
	else 
	{
		printf("%d %d", a, b);
		
		start:
		{
			sum = a + b;
			a = b;
			b = sum;
			printf(" %d", sum);
			i++;
		}
		if(i < num) 		// goto condition
			goto start;
	}
	
	
	return 0;
}

