/*
Create a CLL in which info part of each node contains a digit of a given number. The digit should be stored in reverse order, ie. The LSB should be stored in the first node and MSB in the last. Write a func to add two consectuive numbers and store it in a double linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct circular {
    int digit;
    struct circular *next;
} *last = NULL;

struct DLL {
    int value;
    struct DLL *prev, *next;
} *start = NULL;

// CLL: Insert to Empty
void addBeg(int data)
{
    struct circular *tmp;
    tmp = (struct circular *)malloc(sizeof(struct circular));
    tmp->digit = data;
    last = tmp;
    last->next = last;
    return;
}
// CLL: Insert at End
void addEnd(int data){
    struct circular *tmp;
    tmp = (struct circular *)malloc(sizeof(struct circular));
    tmp->digit = data;
    tmp->next = last->next;
    last->next = tmp;
    last = tmp;
    return;
}
// CLL: Insert
void insert(int value)
{
    if(last == NULL)
    {
        addBeg(value);
        return;
    }
    addEnd(value);
}
// DLL: Add to Empty
void addDoubleEmpty(int sum)
{
    struct DLL *tmp;
    tmp = (struct DLL *)malloc(sizeof(struct DLL));
    tmp->value = sum;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
}

// DLL: Add at End
void addDoubleEnd(int sum)
{
    struct DLL *tmp, *p;
    tmp = (struct DLL *)malloc(sizeof(struct DLL));
    tmp->value = sum;
    p = start;
    while(p->next != NULL)
        p = p->next;
    tmp->next = NULL;
    p->next = tmp;
    tmp->prev = p;
}

// Insert to DLL
void insertDouble(int sum)
{
    if(start == NULL)
    {
        addDoubleEmpty(sum);
        return;
    }
    addDoubleEnd(sum);
}

// calculate Adjacent sum, add to Double Linked List
void sumConsecutive()
{
    struct circular *tmp, *p;
    struct DLL *q;
    int sum;
    if(last == last->next) // if Single Node
    {
        insertDouble(sum);
        return;
    }
    p = last->next; // beginning node
    do {
        sum = p->digit + p->next->digit;
        insertDouble(sum);
        p = p->next->next;
    } while(p != last->next && p != last);
    if(p == last)
    {
        insertDouble(p->digit);
    }
}

// Display Linked List
void display()
{
    struct DLL *p;
    p = start;
    printf("LIST\n\t=> ");
    while (p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

// MAIN FUNCTION
int main()
{
    int num, ld;
    printf("\nEnter a number:");
    scanf("%d", &num);
    // store digits in reverse order
    while(num > 0)
    {
        insert(num %10);
        num /= 10;
    }
    sumConsecutive();
    display();
    return 0;
}