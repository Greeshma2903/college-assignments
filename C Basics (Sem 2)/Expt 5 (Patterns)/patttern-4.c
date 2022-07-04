/*
n = 5
1 2 3 4 5 
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

rows: 1 to n
columns: 1 to n
values: 1 to n
*/
#include <stdio.h>

int main()
{
	int i, j, rows;

	printf("Enter the number of rows: ");
	scanf("%d", &rows);

	for (i = 1; i <= rows; i++)
	{
		for (j = 1; j <= rows; j++)
			printf("%d", j);

		printf("\n");
	}

	return 0;
}
