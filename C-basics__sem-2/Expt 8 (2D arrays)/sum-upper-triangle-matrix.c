/*
WAP to  find the average of the upper triangular elements of a square matrix
*/

#include <stdio.h>
#define SIZE 10

// function declarations
void readValues(int mat[SIZE][SIZE], int row, int col);
void avgUpperTriangle(int mat[SIZE][SIZE], int row, int col);
void printValues(int mat[SIZE][SIZE], int row, int col);

int main()
{
    int mat[SIZE][SIZE], row, col;
    printf("\n---Program to find the sum of upper triangulare elment of square matrix---\n");
read:
    printf("\nEnter the size of matrix(row, column): ");
    scanf("%d, %d", &row, &col);

    if (row == col)
    {
        printf("\nEnter the elements of matrix:\n");
        readValues(mat, row, col);

        printf("\nThe matrix is:\n");
        printValues(mat, row, col);        
        // function call to calculate avg
        avgUpperTriangle(mat, row, col);
    }
    else
    {   // should be square matrix
        printf("\nInvalid! Row should be equal to Column (square matrix)");
        goto read;
    }

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

void avgUpperTriangle(int mat[SIZE][SIZE], int row, int col)
{
    int i, j;
    int count = 0;
    float sum = 0, avg;
    // calculate sum of all elements
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (j >= i)
            {
                sum += mat[i][j];
                ++count;
            }
    // calculate average
    avg =  sum / (double) count;

    printf("\nThe average of the elements of upper triangular elements of matrix is: %f\n", avg);
}