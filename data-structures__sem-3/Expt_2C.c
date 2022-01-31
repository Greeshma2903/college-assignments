// 	3. WAP for conversion of infix to postfix and evaluation of the postfix expression (LL)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

char infix[MAX], postfix[MAX];

struct stack
{
    char symbol;
    struct stack *link;
} * top;

// FUNCTION PROTOTYPES
void infix_to_postfix();
int white_space(char symbol);
void push(char symbol);
char pop();
int instack_priority(char sym);
int incoming_priority(char sym);
int checkNumber(char sym);
int eval_postfix();

// MAIN FUNCTION
int main()
{
    // read exp
    top = NULL;
    printf("======= INFIX TO POSTFIX =======");
    printf("\nEnter expression:");
    fgets(infix, sizeof infix, stdin);
    infix_to_postfix();
    printf("\nThe Postfix expression: \n");
    puts(postfix);
    int result = eval_postfix();
    printf("\nThe Value of the evaluated postfix expression: %d", result);
    return 0;
}

// FUNCTIONS
// Convert to Postfix
void infix_to_postfix()
{
    int i, p = 0;
    char symbol, next;
    for (i = 0; i < (strlen(infix) - 1); ++i)   
    {
        symbol = infix[i];
        if (!white_space(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                    postfix[p++] = next;
                break;  
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
                while ((top != NULL) && (instack_priority(top->symbol) >= incoming_priority(symbol)))
                    postfix[p++] = pop();
                push(symbol);
                break;
            default:
                if (symbol >= '0' && symbol <= '9')
                    postfix[p++] = symbol;
            }
        }
    }
    while (top != NULL)
        postfix[p++] = pop();
    postfix[p] = '\0';

    return;
}

int white_space(char symbol)
{
    if (symbol == '\t' || symbol == ' ')
        return 1;
    return 0;
}

void push(char symbol)
{
    struct stack *tmp = (struct stack *)malloc(sizeof(struct stack));
    tmp->symbol = symbol;
    tmp->link = top;
    top = tmp;
}

char pop()
{
    char sym;
    struct stack *tmp = (struct stack *)malloc(sizeof(struct stack));
    // sym = top->symbol;
    tmp->symbol = top->symbol;
    top = top->link;
    free(tmp);
    // return sym;
}

int instack_priority(char sym)
{
    switch (sym)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    }
}

int incoming_priority(char sym)
{
    switch (sym)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 4;
    }
}
// Evaluate Postfix
int eval_postfix()
{
    int i, a, b, temp, result;
    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] <= '9' && postfix[i] >= '0')
        {
            push(postfix[i] - '0');
        }
        else
        {
            a = pop();
            b = pop();
            switch (postfix[i])
            {
            case '+':
                temp = b + a;
                break;
            case '_':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '%':
                temp = b % a;
                break;
            case '^':
                temp = pow(b, a);
                break;
            }
            push(temp);
        }
    }
    result = pop();
    return result;
}