// Write a program to demonstrate the use of array of pointers.
#include <stdio.h>

int main()
{
    int arr[100], n, i;
    int *ptr[100];
    int sum = 0;
    printf("\nEnter array size:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // initializing the pointer variable
    for (i = 0; i < n; i++)
        ptr[i] = &arr[i];

    // calculate sum of elements of pointer array
    for (i = 0; i < n; i++)
        sum += *ptr[i];

    printf("\nThe sum of values in array: %d", sum);
}