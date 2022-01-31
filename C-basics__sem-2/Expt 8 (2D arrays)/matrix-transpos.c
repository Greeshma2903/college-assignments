// WAP to compute traspose a matrix

#include<stdio.h>

int i, j;

void readValues(int mat[][10], int row, int col);
void transposePrint(int mat[][10], int row, int col);
void beforeTranspose(int mat[][10], int row, int col);

int main()
{
    int mat[10][10], row, col;
    printf("\t---Program to compute transpose of matrix---");

    printf("\nEnter the size of matrix (row, column):");
    scanf("%d, %d", &row, &col);

    printf("\nEnter matrix values:\n");
    readValues(mat, row, col);

    // print the matrix before transpose
    printf("\nThe matrix before transpose:\n");
    beforeTranspose(mat, row, col);

    // print transpose of the matrix
    printf("\nThe transpose of the matrix is:\n");
    transposePrint(mat, row, col);

    return 0;
}

void readValues(int mat[][10], int row, int col)
{
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &mat[i][j]);
}

void beforeTranspose(int mat[][10], int row, int col)
{
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%d\t", mat[i][j]);

        printf("\n");
    }
}

void transposePrint(int mat[][10], int row, int col)
{
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%d\t", mat[j][i]);

        printf("\n");
    }
}
