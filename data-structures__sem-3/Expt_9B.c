// BINARY SEARCH
#include <stdio.h>
#define MAX 50
// Binary Search Function
int binarySearch(int arr[], int low, int up, int ele)
{
    int mid;
    while (low <= up)
    {
        mid = low + (up - low) / 2;
        if (arr[mid] == ele) return mid;
        if (arr[mid] < ele) low = mid + 1;
        else up = mid - 1;
    }
    return -1;
}

int main(void)
{
    int arr[MAX], n, i, ele;
    printf("\nEnter the limit of array: ");
    scanf("%d", &n);
    // Read Sorted Array
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n-------------------------\nEnter Element to be searched:");
    scanf("%d", &ele);
    // Function Call
    int index = binarySearch(arr, 0, n - 1, ele);
    if (index == -1) 
        printf("=> Element is not present in array");
    else printf("=> Element is present at index %d", index);
    return 0;
}