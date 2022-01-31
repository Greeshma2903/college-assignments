// Write a program using pointers to find the frequency of a given character in a string.
#include<stdio.h>
#define SIZE 100
// function declaration
void findCharFrequency(char *ptr, char letter);

int main()
{
    char str[100], letter;
    int i;
    // read string
    printf("\nEnter a string:");
    fgets(str, sizeof(str), stdin);
    // read character
    printf("\nEnter a character (to find its frequency in string):");
    scanf("%c", &letter);

    // function call to calculate frequency
    findCharFrequency(str, letter);

    return 0;
}

void findCharFrequency(char *ptr, char letter)
{
    int i, count = 0;

    // count the number of times character occuers in string
    for (i = 0; *(ptr + i) != '\0'; i++)
        if (*(ptr + i) == letter)
            ++count;

    printf("\nThe character '%c' has a frequency of %d in your string.", letter, count);
}