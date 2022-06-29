/*

Accept three floating point values from the user and compute the results of the
following expressions:
1. x+y+z 
2. (x+y)/z 
3.(x*y*z)/(x-y)

*/

#include<stdio.h>

int main() {
	float x, y, z; 
	float value1, value2, value3;
	
	printf("Enter three floating point values (number, number, number): ");
	scanf("%f, %f, %f", &x, &y, &z);
	
	// Evaluate and assign the value of expressions
	value1 = x + y + z;
	value2 = (x+y)/z;
	value3 = (x*y*z)/(x-y);
	
	
	// print values of expressions evaluated
	printf("\nExpression 1: \n\t(%f +  %f + %f) = %f\n", x, y, z, value1);
	printf("\nExpression 2: \n\t(%f + %f)/%f = %f\n", x, y, z, value2);
	printf("\nExpression 3: \n\t(%f x %f x %f)/(%f - %f)  = %f\n", x, y, z, x, y, value3);
	
	return 0;
}

