// Write a C program to find maximum between three numbers.
#include<stdio.h>

int main()
{
 	int num1, num2, num3;
 	
 	// read numbers
 	printf("Enter 3 numbers:");
 	scanf("%d %d %d", &num1, &num2, &num3);
 	
 	// find max of three values
 	
 	if(num1 > num2) {
 		 if(num1 > num3) 
 		 {
 			printf("\n%d is the largest of three numbers.", num1);
		 }
		 else 
		 {
		  	 printf("\n%d is the largest of three numbers", num3);	
		 }
	 }
	 else 
	 {
	 	 if(num2 > num3)
	 	 {
	 		printf("\n%d is the largest of three numbers", num2);
		 }
		 else 
		 {
		 	printf("\n%d is the largest of three numbers.", num3);
		 }
	 }
 	
	return 0;
}

