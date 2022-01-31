#include <stdio.h>

int main()
{
    int yr;
    printf("Enter a yr (to check for leap):");
    scanf("%d", &yr);

    if (yr % 4 == 0)
    {
        if (yr % 400 == 0 || yr % 100 != 0)
        {
            printf("\n yr is Leap year");
        }

        else
        {
            printf("\n Not leap");
        }
    }
    else
    {
        printf("\n Not leap year.");
    }

    return 0;
}