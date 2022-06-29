// Write a C program to include the following functions. Copy strings, capitalize every alphabets of the string, toggle the case of the string.

#include <stdio.h>
#include <string.h>
#define SIZE 100

void copyStrings(char theString[]);
void capitalizeAlphabets(char theString[]);
void toggleCase(char str[]);

int main()
{
    char str[SIZE];

    // read a string
    printf("\nEnter a string:");
    fgets(str, sizeof(str), stdin);

    // function calls
    copyStrings(str);
    capitalizeAlphabets(str);
    toggleCase(str);
    return 0;
}

void copyStrings(char theString[])
{
    char copiedString[SIZE];
    strcpy(copiedString, theString); // use 'string' library functions to copy string
    printf("\nThe copied string is:\n\t");
    puts(copiedString);
}

void capitalizeAlphabets(char theString[])
{
    char capsString[SIZE];
    int i;

    for (i = 0; i < strlen(theString); i++)
    {
        if (theString[i] >= 'a' && theString[i] <= 'z') // convert valid values to uppercase
        {
            capsString[i] = theString[i] - 32;
        }
        else
        {
            capsString[i] = theString[i];
        }
    }

    capsString[i] = '\0';

    printf("\nThe capitalized string is:\n\t");
    puts(capsString);
}

void toggleCase(char str[])
{
    int i;
    char toggled[SIZE];
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z') // covert to uppercase only if lowercase
            toggled[i] = str[i] - 32;
        else if (str[i] >= 'A' && str[i] <= 'Z') // convert to lowercase if uppercase
            toggled[i] = str[i] + 32;
        else
            toggled[i] = str[i];
    }

    toggled[i] = '\0';

    printf("\nThe string with toggled case is: \n\t");
    puts(toggled);
}