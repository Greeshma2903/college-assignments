// 1. count the number of vowels in a string
#include<stdio.h>

int main()
{
    char str[100];
    int i;
    printf("Enter a string:");
    fgets(str, sizeof(str), stdin);
    
    int vowels =  0;

    for(i=0; str[i] != '\0'; i++)
    {
        switch(str[i])
        {   // check if string contains vowels, and count
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowels++;
        }
    }

    printf("\nThe number of vowels in your string are %d", vowels);
    return 0;
}