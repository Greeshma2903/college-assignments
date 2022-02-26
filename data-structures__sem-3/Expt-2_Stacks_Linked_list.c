// Linked list Stack implementation

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * top;

void push(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) // when DMA doesn't happen
    {
        printf("Stack overflow");
        return;
    }
    tmp->data = data;
    tmp->link = top;
    top = tmp;
}

void pop()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (top == NULL)
    {
        printf("\nStack Underflow!\n");
        return;
    }
    tmp = top;
    int data = tmp->data;
    top = top->link;
    free(tmp);
    printf("\n%d is deleted.", data);
}

int peek()
{
    if(top == NULL)
    {
        printf("\nEmpty Stack :(");
        exit(1);
    }
    return top->data;
}

void display(struct node *start)
{
    struct node *p = start;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->link;
    }
    printf("\n----------------------------------------\n");
}

void reverse()
{
    struct node *revTop, *p, *tmp;
    p = top;
    revTop = NULL;
    while (p != NULL)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = p->data;
        tmp->link = revTop;
        revTop = tmp;
        p = p->link;
    }

    display(revTop);
    top = revTop;
}

// MAIN FUCNTION
int main()
{
    int option, data;
    top = NULL;
    printf("\n ============= WELCOME =============");
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
            printf("The top element: %d\n", peek());
            break;
        case 4:
            printf("\nThe Stack :-\n");
            display(top);
            break;
        case 5:
            if (top == NULL)
                printf("\nThe Stack is empty :(");
            else if (top->link == NULL)
                printf("\nOnly one element of Stack :(");
            else
            {
                printf("\nThe Reversed Stack:-\n");
                reverse();
            }
            break;
        case 6:
            option = 6;
            break;
        default:
            printf("\nINVALID OPTION!!");
        }

    } while (option != 6);

    return 0;
}
