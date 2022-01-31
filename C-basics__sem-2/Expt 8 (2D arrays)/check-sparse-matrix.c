// Write a program to check if the given matrix is Sparse
#include <stdio.h>
#define SIZE 10

// function declaration
void readValues(int mat[SIZE][SIZE], int row, int col);
void checkSparse(int mat[][SIZE], int row, int col);

int main()
{
    int mat[SIZE][SIZE], row, col;

    printf("Enter size and column of matrix(row, column): ");
    scanf("%d, %d", &row, &col);

    printf("\nEnter the matrix elements:\n");
    readValues(mat, row, col);

    // function call to check Sparsity of matrix
    checkSparse(mat, row, col);

    return 0;
}

void readValues(int mat[SIZE][SIZE], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &mat[i][j]);
}

// function to check if matrix is Sparse
void checkSparse(int mat[][SIZE], int row, int col)
{
    int countZero = 0;
    int i, j;

    // if the number of zeroes in the matrix is more than half of elements in matrix, then it is Sparse.

    // loop to count number of zeroes in matrix
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (mat[i][j] == 0)
                ++countZero;

    if (countZero >= (row * col) / 2)
        printf("\nThe matrix is Sparse, since more than half of the elements are '0'.");
    else
        printf("\nThe matrix is not Sparse.");
}
