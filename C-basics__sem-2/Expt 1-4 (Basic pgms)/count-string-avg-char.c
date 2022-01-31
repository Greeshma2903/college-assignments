/*
Program to display 3 strings to the user and also the average of the characters printed so far
*/

#include<stdio.h>

int main(){
	int a, b, c;
	printf("Following are the 3 strings:\n");
	a = printf("\tHello");
	b = printf("\tHola");
	c = printf("\tNamaste");
	
	int avg = (a + b+ c)/3;
	printf("\n\nAverage of the characters present in above strings : %d", avg);
	
	return 0;
}

