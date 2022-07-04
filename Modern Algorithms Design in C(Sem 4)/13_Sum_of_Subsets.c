#include <stdio.h>

/* m = target sum,
n = number of elements */
int m, n;

/* Print Solution Subset and respective values */
void printSoln(int x[], int w[], int k)
{
    printf("(");
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", x[i]);
    }
    printf(") => Sum of (");
    for (int i = 1; i <= k; i++)
    {
        if (x[i] == 1)
            printf("%d ", w[i]);
    }
    printf(")\n");
}

/* Function to find the Subsets that satify target sum */
void SumOfSub(int w[], int x[], int S, int k, int r)
{
    if (k > n)
        return;
    x[k] = 1;
    if (S + w[k] == m) // If Subset gives solution, print Subset
    {
        printSoln(x, w, k);
    }
    else if (S + w[k] + w[k + 1] <= m) // Left subtree
    {
        SumOfSub(w, x, S + w[k], k + 1, r);
    }
    if ((S + r - w[k] >= m) && (S + w[k + 1] <= m)) // Right subtree
    {
        x[k] = 0;
        SumOfSub(w, x, S, k + 1, r);
    }
}

int main()
{
    int r = 0;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    /* Initialize w[] and x[],
    where x is solution array, and w[] is the array of elements */
    int w[n + 1];
    int x[n + 1];

    printf("\nEnter the elements of set: \n");
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
        scanf("%d", &w[i]);

        // Intialize r as sum of all elements
        r += w[i];
    }

    printf("\nEnter the target sum: ");
    scanf("%d", &m);

    printf("\nThe solutions Subsets are >>> \n");
    SumOfSub(w, x, 0, 1, r);
    return 0;
}