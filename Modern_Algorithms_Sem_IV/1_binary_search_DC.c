#include <stdio.h>

int binarySearch(int arr[], int low, int high, int num)
{
    if(low > high)
        return -1;
    else
    {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            binarySearch(arr, mid + 1, high, num);
        else if (arr[mid] > num)
            binarySearch(arr, low, mid-1, num);
    }
}

int main()
{
    int size, num, i;
    printf("\nEnter the size of array:");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter array elements:");
    for (i = 0; i < size; i++)
    {
        printf("[%d] ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n\nEnter number to be searched:");
    scanf("%d", &num);

    // function call
    int searchSuccess = binarySearch(arr, 0, size, num);
    if (searchSuccess != -1)
        printf("\nElement %d found at postion %d", num, searchSuccess);
    else
        printf("\nElement not found.");
    return 0;
}
