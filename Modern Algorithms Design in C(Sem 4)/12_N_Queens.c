#include <stdio.h>
#include <math.h>

int board[20], solnCount;

void print(int n)
{
    int i, j;
    printf("\n\nSolution %d ==>\n\n", ++solnCount);

    for (i = 1; i <= n; ++i)
    {
        printf("\t%d", i);
    }

    for (i = 1; i <= n; ++i)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j)
        {
            if (board[i] == j)
                printf("\tQ"); // Queen place
            else
                printf("\t_"); // empty places
        }
    }
}

/* funtion to check conditions
if no conflict for desired postion returns 1 otherwise returns 0 */
int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        // Check if columns or diagonals conflict
        if (board[i] == column)
            return 0;
        else if (abs(board[i] - column) == abs(i - row))
            return 0;
    }

    // If no conflicts
    return 1;
}

void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            // No conflicts so place queen
            board[row] = column;

            if (row == n) /* Problem ends, print board view */
                print(n);
            else
                queen(row + 1, n); /* Try another position for queen */
        }
    }
}

// MAIN FUNCTION ===>
int main()
{
    int n, i, j;

    printf("\n\nEnter number of Queens:");
    scanf("%d", &n);

    // Function Call
    queen(1, n);
    return 0;
}
