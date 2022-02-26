/*
WAP to omplement stack using array
1. Push
2. Pop
3. Display the top element
4. Display all stack elements
5. Reverse a stack using 2 stacks
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int top = -1;
int stack_arr[MAX];

// Display stack
void display(int top, int stack[])
{
	int i;
    for (i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
    printf("\n");
}

// Check if full
int isFull()
{
    if (top == MAX - 1)
        return 1;
    return 0;
}

// Check if stack empty
int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

// Push to stack
void push(int data)
{
    if (isFull() == 1)
    {
        printf("\nStack Overflow!!!\n");
        return;
    }
    top += 1;
    stack_arr[top] = data;
    printf("\nPushed %d", data);
}

// Pop element
void pop()
{
    int data;
    if (isEmpty() == 1)
    {
        printf("\nStack Underflow!!! :(");
        return;
    }
    else
    {
        data = stack_arr[top];
        top -= 1;
    }
    printf("\nPopped %d\n", data);
}

// Display top element
int peek()
{
    if (isEmpty() == 1)
    {
        printf("\nStack Underflow!!! :(");
        exit(1);
    }
    return stack_arr[top];
}

// Copy reversed stack to another
void reverse(int revTop, int rev[])
{
    int i;
    revTop = -1;
    if (isEmpty() == 1)
    {
        printf("\nEmpty Stack :(");
        return;
    }
    while (top != -1)
    {
        ++revTop;
        rev[revTop] = stack_arr[top];
        --top;
    }
    for (i = 0; i <= revTop; ++i)
    {
        ++top;
        stack_arr[top] = rev[i];
    }
    display(top, stack_arr);
}


// MAIN FUNCION
int main()
{
    int option, data, i;
    int reverse_stack[MAX];
    int revTop;

    printf("\n ============= STACKS =================");
    do
    {
        printf("\n--------------------------------");
        printf("\n1. Push\n2. Pop\n3. Display top element\n4. Display all stack elements\n5. Reverse a stack\n6. Exit");
        printf("\nEnter option:");
        scanf("%d", &option);
        printf("\n------------------------------\n");
        switch (option)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Top element: %d", peek());
            break;
        case 4:
            printf("\nThe Stack elements are: \n");
            if (top == -1)
            {
                printf("Empty Stack :(");
            }
            else
            {
                display(top, stack_arr);
            }
            break;
        case 5:
            printf("\nThe Reversed stack:\n");
            reverse(revTop, reverse_stack);
            break;
        case 6:
            option = 6;
            break;
        default:
            printf("\nInvalid option!");
            break;
        }
    } while (option != 6);

    return 0;
}
