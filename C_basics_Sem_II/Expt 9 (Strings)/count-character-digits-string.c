// Write a program in C to count total number of alphabets, digits and special characters in a string.
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
void countCharacterAndDigits(char str[]);
int main()
{
    char str[MAX_SIZE];

    printf("---Program to count the alphabets, digits and special characters--");
    // read a string
    printf("\nEnter a string:");
    fgets(str, sizeof(str), stdin);

    printf("\nThe string is: \n");
    puts(str);

    countCharacterAndDigits(str);

    return 0;
}

void countCharacterAndDigits(char str[])
{
    int countAlpha = 0;
    int countChar = 0;
    int countDigits = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        // count alphabets
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            ++countAlpha;
        }
        // count digits
        else if (str[i] >= '0' && str[i] <= '9')
        {
            ++countDigits;
        }
        // count special characters
        else
            ++countChar;
    }

    printf("\nIn the string,");
    printf("\nTotal alphabets are: %d", countAlpha);
    printf("\nTotal numbers are: %d", countDigits);
    printf("\nTotal special characters are: %d", countChar);
}