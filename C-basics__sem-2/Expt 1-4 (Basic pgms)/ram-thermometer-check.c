/*
	q1. Ram and Shyam possess a thermometer each. However Ram’s thermometer reads
	temperature in degree Celsius while Shyam’s in degree Fahrenheit. Ram wasn’t
	feeling well so he checked his temperature. It showed 39degC. Scared, Ram asked
	for Shyam’s temperature to recheck, but alas his was in degF. Write a program to
	prompt Ram and Shyam to enter the readings of their respective thermometers and
	display whether the readings are accurate. Also display the difference in the
	readings if any.
*/

#include <stdio.h>

int main() 
{
	float ramTemp, shyamTemp;
	
	// Read thermometer readings of Ram and Shyam 
	printf("\nEnter Ram's thermometer reading:");
	scanf("%f", &ramTemp);
	
	printf("\nEnter Shyam's thermometer reading:");
	scanf("%f", &shyamTemp);
	
	float C = ramTemp;
	// convert Ram's reading to fahrenheit
	ramTemp = (1.8*C) + 32;
	
	if(ramTemp == shyamTemp){
		printf("\nThe readings of both Ram and Shyam are accurate.");
	}
	else {
		if(ramTemp > shyamTemp){
			printf("\nRam's thermometer shows higher temperature than Shyam's thermometer. The difference is (%f degF).", ramTemp - shyamTemp);
		} else {
			printf("\nShyam's thermometer shows higher temperature than Ram's thermometer. The difference is (%f degF).", shyamTemp - ramTemp);
		}
	}
	
	
	
	return 0;
}
