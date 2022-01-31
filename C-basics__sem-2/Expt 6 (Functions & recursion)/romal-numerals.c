/*
Write a general-purpose function to convert any given year into its Roman equivalent.
Use these Roman equivalents for decimal numbers: 1 – I, 5 – V, 10 – X, 50 – L, 100 – C,
500 – D, 1000 – M. Example: Roman equivalent of 1988 is mdcccclxxxviii. Roman
equivalent of 1525 is mdxxv.
*/

#include<stdio.h>

int main()
{
	int number, val;
	int convertToRoman(int num);

//	Read a number from user
	printf("Enter a number (less than 9999):");
	scanf("%d", &number);
	
	if(number < 0)
		printf("Not valid number");
		
	else
	{
		convertToRoman(number);
	}
	
	return 0;
}

int convertToRoman(int num)
{
	//	conversion starts, run the loop till number reduces to 0
	while (num != 0){
		
		if(num > 1000)
		{
			num -= 1000;
			printf("M");		// print M till 3-digit number
		}
		else if(num >= 500)		
		{
			printf("D");		// print D for number >= 500
			num -= 500;
			while(num > 100)
			{
				printf("C");	//... for greater values, also print C till number becomes 2-digit
				num -= 100;
			}
		}
		else if(num >= 100)		
		{
			printf("C");		// if number < 500 & greater than 100, print C till reduces to 2-digit number
			num -= 100;
		}
		else if(num >= 50)		// print L for number >= 50
		{
			printf("L");
			num -= 50;
			while(num>10)
			{
				printf("X");	//... for greater values, also print L till number becomes 1-digit number
				num -= 10;
			}
		}
		else if(num >= 10)		
		{
			printf("X");		// if number < 50 & greater than 10, print X till number becomes 1-digit number
			num -= 10;
		}
		else if(num >= 5)
		{
			printf("V");		// print V for number >= 5
			num -= 5;
			while(num > 0)
			{
				printf("I");	//... for greater values, print I till number becomes 0
				num -= 1;
			}
		}
		else if(num >= 1)
		{
			printf("I");		// if number < 5 & greater than 1, print I till number becomes 0
			num -= 1;
		}
	}
}
