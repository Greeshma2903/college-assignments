/*
Write a program which performs the following tasks:
.    Initialize an integer array of 10 elements in main( )
.    Pass the entire array to a function modify( )
.    In modify( ) multiply each element of array by 3
.    Return the control to main( ) and print the new array elements in main( )
*/

#include <stdio.h>
#define SIZE 10

int modify(int array[]); // function declaration

int main()
{
    int arr[SIZE], i;

    // Initialize an integer array of 10 elements
    printf("Enter %d elements of array: \n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("%d. ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Pass the entire array to a function
    modify(arr);

    // Return the control to main( ) and print the new array elements in main( )
    printf("\nThe array elements after multiplying with 3 are:\n");
    for (i = 0; i < SIZE; i++)
        printf("%d. %d\n", i + 1, arr[i]);

    return 0;
}

int modify(int array[])
{
    int i;

    // multiply each element of array by 3
    for (i = 0; i < SIZE; i++)
        array[i] *= 3;
}
