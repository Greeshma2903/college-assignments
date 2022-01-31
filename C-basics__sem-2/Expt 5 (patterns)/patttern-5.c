#include <stdio.h>

int main()
{
	int i, j, rows;
	int alpha = 1;
	int count = 1;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);

	for (i = 1; i <= rows; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i % 2 == 0)
			{
				printf("%d ", count); // print number at even rows
			}
			else
			{
				printf("%c ", 'A' + alpha - 1); // print alphabets at odd rows
			}
		}

		// for values to be printed
		if (i % 2 == 0)
			count++;
		else
			alpha++;

		printf("\n");
	}
	return 0;
}
