// multiply two matrices ⭐⭐⭐
#include <stdio.h>

int main()
{
	int i, j, k;
	int mat1[10][10], mat2[10][10], prod[10][10];
	int r1, c1, r2, c2;

label:
	printf("\nSize of matrix 1(row, column):");
	scanf("%d, %d", &r1, &c1);

	printf("\nEnter matrix 1 values:\n");
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c1; j++)
		{
			scanf("%d", &mat1[i][j]);
		}
	}

	printf("\nSize of matrix 2(row, column):");
	scanf("%d, %d", &r2, &c2);

	if (c1 == r2)	// column of 1st = row of 2nd
	{
		printf("Enter matrix 2 values:\n");
		for (i = 0; i < r2; i++)
		{
			for (j = 0; j < c2; j++)
			{
				scanf("%d", &mat2[i][j]);
			}
		}

		printf("\nThe multiplication of matrices is possible.\n");

		for (i = 0; i < r1; i++)
		{
			for (j = 0; j < c2; j++)
			{
				prod[i][j] = 0;			// to initialize the all values of product matrix to 0
				for (k = 0; k < c1; k++)
				{
					prod[i][j] += mat1[i][k] * mat2[k][j];		// ⭕
				}
			}
		}

		printf("\n\nThe product of matrices is:\n");
		for (i = 0; i < r1; i++)
		{
			for (j = 0; j < c2; j++)
			{
				printf("%d\t", prod[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		printf("\nCannot multiply if row of matrix 1 is not equal to column of matrix 2.");
		printf("\nEnter the sizes of matrices again.");
		goto label;
	}

	return 0;
}
