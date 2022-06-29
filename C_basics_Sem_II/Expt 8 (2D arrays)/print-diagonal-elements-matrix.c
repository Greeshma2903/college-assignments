// WAP TO PRINT ALL DIAGONAL ELEMENTS OF MATRIX

#include <stdio.h>
int i, j;
void readValues(int mat[][10], int row);
void printDiagonal(int mat[10][10], int row);
void printMatrix(int mat[][10], int row);

int main()
{
    int mat[10][10], row, col;

    printf("\nEnter the size of matrix (row):");
    scanf("%d, %d", &row);

    printf("\nEnter matrix values:\n");
    readValues(mat, row);

    printf("\nThe matrix is:\n");
    printMatrix(mat, row);

    printf("\nThe diagonal of the matrix is:");
    printDiagonal(mat, row);

    return 0;
}

void readValues(int mat[][10], int row)
{
    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
            scanf("%d", &mat[i][j]);
}

// function to print matrix
void printMatrix(int mat[][10], int row)
{
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < row; j++)
            printf("%d\t", mat[i][j]);

        printf("\n");
    }
}

// function to print diagonal elements
void printDiagonal(int mat[10][10], int row)
{
    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
            if (i == j)
                printf("%d ", mat[i][j]);
}