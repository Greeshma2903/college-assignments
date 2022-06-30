#include <stdio.h>

int interchange(int arr[], int i, int j)
{ // function to swap values
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)
{
    int p = arr[low]; // assume initial value of pivot as first element
    int i = low + 1;  // pointer from start of list
    int j = high - 1; // pointer from end of list

    while (i <= j)
    {
        // incement i to find element greater than pivot
        while (arr[i] < p && i < high)
            i++;
        // decrement j to find element smaller than pivot
        while (arr[j] > p)
            j--;

        // if no crossover, and i < j
        // swap i'th and j'th values
        if (i < j)
        {
            interchange(arr, i, j);
        }
        else
            i++;
    }

    // if i and j crossover
    // replace j'th value with pivot
    arr[low] = arr[j];
    arr[j] = p;
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Divide array into two parts
        int j = partition(arr, low, high);

        // solve the subproblems
        quicksort(arr, low, j);
        quicksort(arr, j + 1, high);
    }
}

// MAIN FUNCTION ------>
int main()
{
    int num, i;
    printf("\nEnter the side of array:");
    scanf("%d", &num);
    int arr[num];

    printf("\nEnter the array:");
    for (i = 0; i < num; i++)
    {
        printf("[%d] ", i);
        scanf("%d", &arr[i]);
    }
    // function call
    quicksort(arr, 0, num);

    printf("\nEnter the array:\n=> ");
    for (i = 0; i < num; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}
