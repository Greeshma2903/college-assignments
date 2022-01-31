/*
Number pyramid:(pattern 3)
    1
   121
  12321
 1234321
123454321
*/

#include <stdio.h>

int main()
{
	int i, j, row;

	printf("Enter the number of rows: ");
	scanf("%d", &row);

	for (i = 1; i <= row; i++)
	{
		// spaces
		for (j = 1; j < (row - i + 1); j++)
			printf("  ");

		// first half numbers
		for (j = 1; j <= i; j++)
			printf("%d ", j);

		// second half numbers
		for (j = (i - 1); j >= 1; j--)
			printf("%d ", j);

		printf("\n");
	}

	return 0;
}
