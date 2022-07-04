/*
Write a program to find the sum of each row and column
of a m*n matrix and store it in the following way:
[]          []          []      [sum row0]
[]          []          []      [sum row1]
[]          []          []      [sum row2]
[sumcol0] [sumcol1] [sumcol2]
*/
#include <stdio.h>
#define SIZE 10
// function declarations
void readValues(int mat[SIZE][SIZE], int row, int col);
void calcRowColmSum(int mat[SIZE][SIZE], int row, int col);
void printValues(int mat[SIZE][SIZE], int row, int col);

int main()
{
    int mat[SIZE][SIZE], row, col;

    printf("Enter the size of matrix(row, column): ");
    scanf("%d, %d", &row, &col);
    // read matrix values
    printf("\nEnter the matrix elements:\n");
    readValues(mat, row, col);

    // function call
    calcRowColmSum(mat, row, col);

    // display matrix with sum of each row & column at end
    printf("\nThe new matrix is:\n");
    printValues(mat, row , col );
    return 0;
}

void readValues(int mat[SIZE][SIZE], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &mat[i][j]);
}

// function to calculate sum of each row and column and store it
void calcRowColmSum(int mat[SIZE][SIZE], int row, int col)
{
    int i, j;
    int sumRow = 0;
    int sumCol = 0;

    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
        {
            sumRow += mat[i][j]; // calculate sum of row i
            sumCol += mat[j][i]; // calculate sum of column i
        }
        mat[i][j] = sumRow; // store the value of sum at end of row i
        mat[j][i] = sumCol; // store the value of sum at end of column i

        sumCol = 0;
        sumRow = 0;
    }
    mat[i][j] = 0;
}

void printValues(int mat[SIZE][SIZE], int row, int col)
{
    int i, j;
    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= col; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}