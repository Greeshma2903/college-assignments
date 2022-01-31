#include <stdio.h>
#define SIZE 100
// function declarations
void readValues(int mat[SIZE][SIZE], int row);
int mutiplyMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int row, int prod[SIZE][SIZE]);
void transposeMatrix(int mat[SIZE][SIZE], int transpose[SIZE][SIZE], int row);
void proveFormula(int LHS[SIZE][SIZE], int RHS[SIZE][SIZE], int row);
void printValues(int mat[SIZE][SIZE], int row);

int main()
{
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE], prod[SIZE][SIZE];
    int row;
    int i, j, k;

    int prodOfAB[SIZE][SIZE];
    int LHS[SIZE][SIZE];
    int finalLHS[SIZE][SIZE];

    int transA[SIZE][SIZE], transB[SIZE][SIZE], transC[SIZE][SIZE];
    int prodTransCB[SIZE][SIZE];
    int finalRHS[SIZE][SIZE];

    // read matrix values of A & B
    printf("\n*(we are considering square matrices)*\n");

    printf("\n\nEnter the size of matrices (row): ");
    scanf("%d, %d", &row);

    printf("\n---\nEnter the elements of matrix A:\n");
    readValues(A, row);
    printf("\nEnter the elements of matrix B:\n");
    readValues(B, row);

    // -------- LHS --------
    // (A * B)
    mutiplyMatrices(A, B, row, prod);
    // store (A * B) in new matrix
    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
            prodOfAB[i][j] = prod[i][j];

    // read matrix 3 values
    printf("\nEnter the elements of matrix C:\n");
    readValues(C, row);

    // (A * B * C )
    mutiplyMatrices(prodOfAB, C, row, prod);
    // store (A * B * C) in new matrix
    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
            LHS[i][j] = prod[i][j];

    // transpose LHS: (A * B * C )^T
    transposeMatrix(LHS, finalLHS, row);

    // ------- RHS -------
    // create the transpose matrices: C^T, B^T, A^T
    transposeMatrix(C, transC, row);
    transposeMatrix(B, transB, row);
    transposeMatrix(A, transA, row);

    // multiply: (C^T) * (B^T)
    mutiplyMatrices(transC, transB, row, prod);
    // store product C^T * B^T in new matrix
    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
            prodTransCB[i][j] = prod[i][j];

    // multiply : (C^T * B^T) * A^T
    mutiplyMatrices(prodTransCB, transA, row, prod);
    // store final (C^T * B^T * A^T) in new matrix
    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
            finalRHS[i][j] = prod[i][j];

    // ------- CHECK FORLMULA: LHS = RHS -------
    proveFormula(finalLHS, finalRHS, row);

    // print RHS and LHS
    printf("\n\nLHS:\n");
    printValues(finalLHS, row);

    printf("\nRHS:\n");
    printValues(finalRHS, row);

    return 0;
}

void readValues(int mat[SIZE][SIZE], int row)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
            scanf("%d", &mat[i][j]);
}

int mutiplyMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int row, int prod[SIZE][SIZE])
{
    int i, j, k;

    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
        {
            prod[i][j] = 0; // to initialize the all values of product matrix to 0
            for (k = 0; k < row; k++)
            {
                prod[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
}

void transposeMatrix(int mat[SIZE][SIZE], int transpose[SIZE][SIZE], int row)
{
    int i, j, k;

    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
            transpose[i][j] = mat[j][i];
}

void proveFormula(int LHS[SIZE][SIZE], int RHS[SIZE][SIZE], int row)
{
    int i, j;
    int flag = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < row; j++)
        {
            if (LHS[i][j] != RHS[i][j])
            {
                flag++;
            }
        }
    }
    if (flag == 0)
        printf("\nThe formula is hence proved, ie. (A * B * C )^T = (C^T * B^T * A^T).");
}

void printValues(int mat[SIZE][SIZE], int row)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < row; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}