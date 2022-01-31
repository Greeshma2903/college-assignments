// Program to duplicate a matrix
#include <stdio.h>
#define SIZE 10

// function declarations
void readValues(int mat[SIZE][SIZE], int row, int col);
void printValues(int mat[SIZE][SIZE], int row, int col);
void duplicateMatrix(int mat[SIZE][SIZE], int row, int col, int dup[SIZE][SIZE]);

int main()
{
    int mat[SIZE][SIZE], row, col, dup[SIZE][SIZE];
    printf("\n---Program to duplicate a matrix---\n");

    printf("Enter the size of matrix(row, column): ");
    scanf("%d, %d", &row, &col);
    // read matrix values
    printf("\nEnter the matrix elements:\n");
    readValues(mat, row, col);

    // function call to duplicate the matrix
    duplicateMatrix(mat, row, col, dup);

    printf("\nThe original matrix:\n");
    printValues(mat, row, col);

    printf("\n\nThe duplicate matrix:\n");
    printValues(dup, row, col);

    return 0;
}

void readValues(int mat[SIZE][SIZE], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &mat[i][j]);
}

void printValues(int mat[SIZE][SIZE], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void duplicateMatrix(int mat[SIZE][SIZE], int row, int col, int dup[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            dup[i][j] = mat[i][j]; // copy elements of matrix to another matrix
}