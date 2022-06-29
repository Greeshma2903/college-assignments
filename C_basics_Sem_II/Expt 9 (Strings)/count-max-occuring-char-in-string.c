// Write a program in C to find maximum occurring character in a string. ⭐⭐

#include <stdio.h>
#include <string.h>
#define SIZE 100

void findMaxChar(char str[], int arr[]);

int main()
{
    printf("---Program to find maximum occurring character in a string---");
    char str[SIZE];
    int arr[255];

    // read a string
    printf("\nEnter a string:");
    fgets(str, sizeof(str), stdin);

    // function call
    findMaxChar(str, arr);
    return 0;
}

void findMaxChar(char str[], int arr[])
{
    int length = strlen(str), i;
    int max = 0;
    char maxChar;

    // initialize all values in arr at str[i]'th places to 0
    for (i = 0; i < length; i++)
        arr[str[i]] = 0;

    for (i = 0; i < length; i++)
        if (str[i] != ' ')
            arr[str[i]]++; // increment str[i]'th position value, this will count repetitive values

    // now check for max of occurances in array 'arr' and print corresponding character from arr[str[i]]'s index
    for (i = 0; i < length; i++)
        if (arr[str[i]] > max)
        {
            max = arr[str[i]];
            maxChar = str[i];
        }

    printf("\nThe most occuring character is '%c'.", maxChar);
}
