//  Write a function propercase(str) that changes the first character of the input string to uppercase and changes the remaining characters to lowercase.

#include <stdio.h>
#include <string.h>
#define SIZE 100

void propercase(char theString[]);     // func declaration

int main()
{
    char str[SIZE];

    printf("---Program to convert first character in string to uppercase and the rest to lowercase--");
    // read a string
    printf("\nEnter a string:");
    fgets(str, sizeof(str), stdin);
    // function call
    propercase(str);
    return 0;
}

void propercase(char theString[])
{
    int i;
    for (i = 0; i < strlen(theString); i++)
    {
        // covert to uppercase only if valid lowercase character
        if (i == 0 && (theString[i] >= 'a' && theString[i] <= 'z'))     
            theString[i] -= 32;
        // convert to lowercase only if valid uppercase chacteter
        else if (theString[i] >= 'A' && theString[i] <= 'Z')        
            theString[i] += 32;
    }

    printf("\nThe converted string: \n\t");
    puts(theString);
}