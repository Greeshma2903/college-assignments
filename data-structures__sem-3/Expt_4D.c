// Write a function to find whether a DLL is palindrome or not.

#include <stdio.h>
#include <stdlib.h>

// STRUCTURE
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *start = NULL;
// add to empty
void addEmpty(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
    return;
}
// add at end
void addEnd(int data)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;

    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    tmp->next = NULL;
    p->next = tmp;
    tmp->prev = p;
    return;
}
// create new LL
void createDLL()
{
    int data, num, i;
    start = NULL;
    printf("\nHow many values?");
    scanf("%d", &num);
    if (num == 0)
        return;

    printf("\nEnter the data:");
    scanf("%d", &data);
    addEmpty(data);

    for (i = 2; i <= num; i++)
    {
        printf("\nEnter the data:");
        scanf("%d", &data);
        addEnd(data);
    }
}
// CHECK double linked list is palindrome
int checkPalindrome()
{
    struct node *p, *q;
    for (p = start; p->next != NULL; p = p->next)
        ;
    q = p;
    p = start;
    while (p != NULL)
    {
        if (p->data != q->data)
            return 0;
        p = p->next;
        q = q->prev;
    }
    return 1;
}
// Display linked list
void display()
{
    struct node *p;
    p = start;
    printf("\nLIST\t=> ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// MAIN FUNCTION
int main()
{
    printf("\nCheck palindrome ------>\n");
    createDLL();
    if (checkPalindrome())
        printf("\n=> Double linked list is Palindrome");
    else
        printf("\n=> Double Linked list is not palindrome");
    display();
    return 0;
}