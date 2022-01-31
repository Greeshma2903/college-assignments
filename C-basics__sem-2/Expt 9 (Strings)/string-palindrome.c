// 2. check if a string is a palindrome.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    int i, length;
    int flag = 0;

    printf("Enter a word:");
    scanf("%s", str);

    length = strlen(str);   // calculate length of string

    for (i = 0; i < length; i++)
    {
        // check if first letter is = last, till i = length-i-1
        if (str[i] != str[length - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        printf("\n%s - is not a palindrome", str);
    }
    else
    {
        printf("\n%s - is a palindrome", str);
    }
    return 0;
}