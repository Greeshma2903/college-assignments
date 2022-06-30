#include <stdio.h>

void copy(int temp[], int arr[], int low, int size)
{   
    // copy sorted temp array to main array
    int i;
    for (i = low; i <= size; i++)
        arr[i] = temp[i];
}

void Merge(int arr[], int temp[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    // compare the two subarrays using two-pointer method
    // and store sorted array into temp array
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
}

void Merge_sort(int arr[], int low, int high)
{   
    int temp[high + 1];     // temporary array
    if (low < high)
    {   // divide the array into subarrays, and sort each subarray
        int mid = (low + high) / 2;
        Merge_sort(arr, low, mid);
        Merge_sort(arr, mid + 1, high);
        Merge(arr, temp, low, mid, high);
        copy(temp, arr, low, high);
    }
}

// MAIN FUNCTION ---->
int main()
{
    int i, size;
    printf("\nEnter the number of elements for array:");
    scanf("%d", &size);
    // read the array
    int arr[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    // function call
    Merge_sort(arr, 0, size - 1);
    // print the sorted list
    printf("Sorted list is :\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
