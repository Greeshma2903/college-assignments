// WAP to add and subtract two matrices

#include <stdio.h>

int i, j;

// function declarations
void readValues(int mat[][10], int rows, int clm);
void addMatrices(int mat1[][10], int mat2[][10], int sum[][10], int rows, int clms);
void subtractMatrices(int mat1[][10], int mat2[][10], int diff[][10], int rows, int clms);
void printValues(int mat[][10], int rows, int cols);

int main()
{
    int mat1[10][10], mat2[10][10], sum[10][10], diff[10][10];
    int row, col;

    printf("---Program to add and subtract two matrices---");

    printf("\nEnter the value of matrices (maximum 10*10 values):-\n");

    printf("\nEnter the size of matrix (row, column):");
    scanf("%d, %d", &row, &col);

    // read values for matrix 1
    printf("\nMatrix 1:\n");
    readValues(mat1, row, col);

    // read values for matrix 2
    printf("\nMatrix 2:\n");
    readValues(mat2, row, col);

    // to add matrices
    addMatrices(mat1, mat2, sum, row, col);

    // to subtract matrices
    subtractMatrices(mat1, mat2, diff, row, col);

    // PRINT VALUES
    printf("\nThe Sum of the matrices is:\n");
    printValues(sum, row, col);

    printf("\nThe Difference of the matrices is:\n");
    printValues(diff, row, col);

    return 0;
}

void readValues(int mat[][10], int rows, int clm)
{
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < clm; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void addMatrices(int mat1[][10], int mat2[][10], int sum[][10], int rows, int clms)
{
    for (i = 0; i < rows; i++)
        for (j = 0; j < clms; j++)
            sum[i][j] = mat1[i][j] + mat2[i][j];
}

void subtractMatrices(int mat1[][10], int mat2[][10], int diff[][10], int rows, int clms)
{
    for (i = 0; i < rows; i++)
        for (j = 0; j < clms; j++)
            diff[i][j] = mat1[i][j] - mat2[i][j];
}

void printValues(int mat[][10], int rows, int cols)
{
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%d\t", mat[i][j]);

        printf("\n");
    }
}