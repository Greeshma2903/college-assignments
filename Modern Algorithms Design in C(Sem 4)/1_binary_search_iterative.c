// Binary Search: Iterative methods
/*
Prereq:
Requires the input array to be sorted

Time Complexity: log(n)
*/

#include <stdio.h>

int binarySearch(int arr[], int low, int high, int num)
{
    int mid;
    // binary search
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == num)
        {
            printf("\nElement %d present at position %d.", num, arr[mid]);
            return 1;
        }
        else if (num > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int main()
{
    int i, low, mid, high, size, num;
    printf("\nEnter the size of array:");
    scanf("%d", &size);

    // read array elements
    int arr[size];
    printf("\nEnter array elements:");
    for (i = 0; i < size; i++)
    {
        printf("[%d] ", i);
        scanf("%d", &arr[i]);
    }
    // read the element to be searched
    printf("\n\nEnter number to be searched:");
    scanf("%d", &num);

    // function call
    low = 0;
    high = size;
    int searchSuccess = binarySearch(arr, low, high, num);
    if (searchSuccess)
        printf("\nElement not present.");
    return 0;
}
