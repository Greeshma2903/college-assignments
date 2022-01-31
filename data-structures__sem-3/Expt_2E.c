// 	WAP to check nesting of parenthesis using stack (LL)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

char str[MAX];
// structure
struct node
{
    char ch;
    struct node *link;
} * top;

int match(char popped_par, char exp);
int isEmpty();
void push(char ch);
int pop();
int isParenthesisMatch();

// MAIN FUNCTION
int main()
{
    top = NULL;
    printf("\nEnter expression:");
    fgets(str, sizeof(str), stdin);
    if (isParenthesisMatch() == 1)
        printf("\n=> Parenthesis of expression are balanced :)\n");
    else
        printf("\n=> Parenthesis of expression NOT balanced!");

    return 0;
}

// FUNCTION: check if parenthesis pair up
int match(char popped_par, char exp)
{
    if (popped_par == '(' && exp == ')')
        return 1;
    else if(popped_par == '[' && exp == ']')
        return 1;
    else if(popped_par == '{' && exp == '}')
        return 1;
    return 0;
}
// FUNCTION: check empty stack
int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}
// FUNCTION: push to stack
void push(char ch)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->ch = ch;
    tmp->link = top;
    top = tmp;
}
// FUNCTION: pop element from stack
int pop()
{
    char tmp;
    if (top == NULL)
    {
        printf("Stack Underflow!");
        return -1;
    }
    tmp = top->ch;
    top = top->link;
    return tmp;
}


// FUNCTION: to check if parenethesis match
int isParenthesisMatch()
{
    int i;
    char next;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            // push '(' in expression to stack
            push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (isEmpty())
                return 0;
            
            // check if top brace pairs with current expression
            next = pop();
            if (!match(next, str[i]))
                return 0;
        }
    }
    // if Empty stack, then the parenthesis are balanced
    if (isEmpty())
        return 1;
    return 0;
}

