// Write a program in C to count the total number of words in a string.
#include <stdio.h>
#include <string.h>
#define SIZE 1000

void countWords(char myString[]);
int main()
{
    printf("---Program to count the number of words in string---");
    char str[SIZE];
    // read a string
    printf("\nEnter a string:");
    fgets(str, sizeof(str), stdin); // since gets() is depreciated in latest C version

    printf("\nThe string is: \t");
    puts(str);

    // count words
    countWords(str);
    return 0;
}

void countWords(char myString[])
{
    int wordCount = 0;
    int i;
    // increment wordCount if loop finds ' ' (space)
    for (i = 0; i < strlen(myString); i++)
    {
        if (myString[i] == ' ')
            ++wordCount;
    }

    wordCount++; // add 1 to count last word

    printf("\nThe total words in your string are: %d", wordCount);
}