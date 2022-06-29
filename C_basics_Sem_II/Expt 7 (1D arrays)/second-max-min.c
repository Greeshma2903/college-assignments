/*
Given a list of numbers (integers), find the sum of second maximum and second minimum
in this list.
*/
#include <stdio.h>
#define SIZE 100

// function declaration
int findSecondMax(int list[], int size); 

int main()
{
	int list[SIZE], i, secMax, secMin, sum;
	printf("\t---Program to find the sum of 2nd max. and 2nd min. numbers in a list---\n");
	printf("\nEnter the values of list(enter -1 to end of list):\n");

	// Input list values from users
	for (i = 0; i < SIZE; i++)
	{
		printf("%d: ", i + 1);
		scanf("%d", &list[i]);
		if (list[i] == -1)
			break;
	}

	secMax = findSecondMax(list, i); // function call
	secMin = findSecondMin(list, i);

	// calculate sum of second max & min values from the list
	sum = secMin + secMax;

	printf("\nSecond min num: %d", secMin);
	printf("\nSecond max num: %d", secMax);
	printf("\nThe sum of second max. and min. numbers is: %d", sum);

	return 0;
}

int findSecondMax(int list[], int size)
{
	int i;
	// initialize with first value in list
	int max = list[0];
	int secMax = list[0];

	// find the max number in the array to further find the second max number
	for (i = 0; i < size; i++)
		if (list[i] >= max)
			max = list[i];

	// find the 2nd max & min number
	for (i = 0; i < size; i++)
		if (list[i] >= secMax && list[i] != max)
			secMax = list[i];

	return secMax;
}

int findSecondMin(int list[], int size)
{
	int i;
	// initialize with first value in list
	int min = list[0];
	int secMin = list[0];

	// find the min numbers in the array to further find the second min number
	for (i = 0; i < size; i++)
		if (list[i] <= min)
			min = list[i];

	// find the 2nd min number
	for (i = 0; i < size; i++)
		if (list[i] <= secMin && list[i] != min)
			secMin = list[i];

	return secMin;
}

