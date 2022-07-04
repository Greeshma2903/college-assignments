// Find the average of all the elements in a matrix

#include <stdio.h>

int i, j;
void readValues(int mat[][10], int row, int col);
void computeAvg(int mat[][10], int row, int col);

int main()
{
    int mat[10][10], row, col;
    printf("\t---Program to compute average of elements of matrix---");

    printf("\nEnter the size of matrix (row, column):");
    scanf("%d, %d", &row, &col);

    printf("\nEnter matrix values:\n");
    readValues(mat, row, col);

    // function call
    computeAvg(mat, row, col);

    return 0;
}

void readValues(int mat[][10], int row, int col)
{
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &mat[i][j]);
}

// function to calculate the average of all elements in matrix
void computeAvg(int mat[][10], int row, int col)
{
    int sum = 0;
    float avg;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            sum += mat[i][j];

    // row * col = number of elements in the matrix
    avg = sum / (row * col);

    printf("\nThe average of all elements in the matrix: %f", avg);
}
