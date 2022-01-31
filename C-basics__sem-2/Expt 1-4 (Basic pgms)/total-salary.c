/*
	q2. ABC Pvt Ltd. has decided upon the following salary structure for their employees:
	Write a program to read the basic pay of an employee and compute his total salary.
	Perform necessary validations. Total salary = BP + HRA + TA
	
	Basic Pay < 10000
		HRA: 10% of Basic
		TA: 5% of Basic
	Basic Pay: [10000,30000)
		HRA: 15% of Basic
		TA: 5% of Basic
	Basic Pay: [30000,50000]
		HRA: 20%of Basic
		TA: 7% of Basic	
*/

#include<stdio.h>
int main()
{
	int totalSalary, BP, HRA, TA;
	
	// Read basic pay of employee
	printf("\nEnter employee's Basic pay:");
	scanf("%d", &BP);
	
	// Calculate HRA and TA based on Basic Pay
	if(BP < 10000){
		HRA = 0.1 * BP;
		TA = 0.05 * BP;
	}
	else if(BP>=10000 && BP < 30000){
		HRA = 0.15 * BP;
		TA = 0.05 * BP;
	}
	else if(BP>= 30000 && BP < 50000){
		HRA = 0.2 * BP;
		TA = 0.07 * BP;
	}
	
	// calculate total salary
	totalSalary = BP + HRA + TA;
	
	printf("\nThe total salary of the employee is %d.", totalSalary);
	
	return 0;
}
