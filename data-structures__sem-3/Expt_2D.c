// WAP for reverse to string using stack (LL)

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for malloc
#define MAX 50
char inString[MAX];

struct node
{
    char str;
    struct node *link;
} * top;

void reverse();

// MAIN FUNCTION
int main()
{
    top = NULL;
    printf("\nEnter a string:");
    fgets(inString, sizeof(inString), stdin);

    printf("\nOriginal string:\n\t%s", inString);

    // function call to reverse the array
    reverse();

    return 0;
}

void reverse()
{
    int i, j = 0;
    struct node *tmp;
    char revArr[MAX];

    // push the string to stack
    for (i = 0; i < (strlen(inString) - 1); i++)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->str = inString[i];
        tmp->link = top;
        top = tmp;
    }

    // transfer the reversed string from stack to array
    while (top != NULL)
    {
        revArr[j] = top->str;
        ++j;
        top = top->link;
    }
    revArr[j] = '\0';

    printf("\nThe Reversed string is: \n\t");
    for (i = 0; i < strlen(revArr); ++i)
        printf("%c", revArr[i]);
    printf("\n--------------------------------");
}
