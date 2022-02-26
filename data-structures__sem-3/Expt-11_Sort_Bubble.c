// Bubble Sort

#include <stdio.h>
#define MAX 100

int main()
{
    int a[MAX], i, j, n, temp, exch;
    printf("Enter the number of elements:  ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d:  ", i + 1);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; ++i)
    {
        exch = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            ++exch;
        }
        if (exch == 0)
            break;
    }
    printf("Sorted Array is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
