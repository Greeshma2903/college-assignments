/*
A machine is purchased which will produce earning of Rs. 1000 per year while it lasts.
The machine costs Rs. 6000 and will have a salvage value of Rs. 2000 when it is
condemned. If 9 percent per annum can be earned on alternate investments, write a
program to determine what will be the minimum life of the machine to make it a more
attractive investment compared to alternative investment?
*/
#include<stdio.h>

int main()
{
 	float machineIncome, alternateIncome, interest;
 	int year=0;
 	
 	// cost price - selling price = actual Investment
 	// 6000 - 2000 = 4000
 	int actualInvest = 6000 - 2000;
 	
	printf(" year\tInterest on alternate\tMachine income per year\n");
	
    while(alternateIncome > machineIncome)
    {
        year++;

        // Interest gained on alternate investment
        // 9 % of 4000 x year= 0.09 * 4000 * year
 		alternateIncome = 0.09 * actualInvest * year;
 		
   
        // yearly income from machine
        machineIncome = (1000 * year) - actualInvest;
        printf(" %d\t%f\t\t%f\n", year, alternateIncome, machineIncome);

    }
	
	printf("\nIf we consider the amount invested as Rs.4000 \nthen the income from Machine is attractive over alternate investments after %d years", year);
    printf("\n\nMinimum life of machine: %d years", year);
	return 0;
}

