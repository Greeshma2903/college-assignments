/*
1.WAP to implement double linked list and perform following operations. 
    a. Create a LL
    b. Display LL
    c. Add to empty list
    d. Add at the beginning
    e. Add at the end
    f. Add after node
    g. Add before node
    h. Delete a node
*/

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
        p = p->next;
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
    printf("\nHow many records?"); scanf("%d", &num);
    if (num == 0)
        return;

    printf("\nEnter the data:"); scanf("%d", &data);
    addEmpty(data);

    for (i = 2; i <= num; i++)
    {
        printf("\nEnter the data:"); scanf("%d", &data);
        addEnd(data);
    }
}
// display LL
void display()
{
    struct node *p;
    p = start;
    printf("LIST\n\t=> ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// add at beginning
void addBeg(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->prev = NULL;
    tmp->next = start;
    start = tmp;
    return;
}
// add after node
void addAfter()
{
    int data, ele;
    printf("\nEnter data to insert:"); scanf("%d", &data);
    printf("\nAfter which element to insert? "); scanf("%d", &ele);

    struct node *p, *tmp;
    p = start;
    while (p != NULL)
    {
        if (p->data == ele)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->data = data;
            tmp->next = p->next;
            tmp->prev = p;
            if (p->next != NULL)
                p->next->prev = tmp;
            p->next = tmp;
            return;
        }
        p = p->next;
    }
    printf("\n=> Element not found!");
}
// add before node
void addBefore()
{
    int data, ele;
    printf("\nEnter data to insert:"); scanf("%d", &data);
    printf("\nBefore which element to insert? "); scanf("%d", &ele);
    struct node *tmp;
    if (ele == start->data)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = data;
        tmp->next = start;
        tmp->prev = NULL;
        start->prev = tmp;
        start = tmp;
        return;
    }
    struct node *q = start;
    while (q != NULL)
    {
        if (q->data == ele)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->data = data;
            tmp->prev = q->prev;
            tmp->next = q;
            q->prev->next = tmp;
            q->prev = tmp;
            return;
        }
        q = q->next;
    }
    printf("\n=> Element not found!");
}
// delete a node
int deleteNode()
{
    int data, ele;
    printf("\nEnter data to be deleted:"); scanf("%d", &data);
    struct node *tmp, *p;
    // del only node
    if (start->next == NULL && start->data == data)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp = start;
        start = NULL;
        ele = tmp->data;
        free(tmp);
        return ele;
    }
    // del first node
    if (start->data == data)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp = start;
        start = start->next;
        start->prev = NULL;
        ele = tmp->data;
        free(tmp);
        return ele;
    }
    // del node in between
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp = start->next;
    while (tmp->next != NULL)
    {
        if (tmp->data == data)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            ele = tmp->data;
            free(tmp);
            return ele;
        }
        tmp = tmp->next;
    }
    // del end node
    if (tmp->data == data)
    {
        tmp->prev->next = NULL;
        ele = tmp->data;
        free(tmp);
        return ele;
    }
    printf("\n=> Element not found!");
}

// MAIN FUNCTION
int main()
{
    int i, option, data, value;
    while (option != 9)
    {
        printf("\n===================================\n");
        printf("Choose from following:\n1. Create Double Linked List\n2. Display LL\n3. Add to empty list\n4. Add at the beginning\n5. Add at the end\n6. Add after a node\n7. Add before a node\n8. Delete a node\n9. Exit");
        printf("\nEnter option:"); scanf("%d", &option);
        printf("\n===================================\n");

        switch (option)
        {
        case 1: createDLL(); break;
        case 2:  display(); break;
        case 3: 
            if (start == NULL)
            {
                printf("\nEnter data to insert:");
                scanf("%d", &data);
                addEmpty(data);
            }
            break;
        case 4: // add at beginning
            printf("\nEnter data to insert:"); scanf("%d", &data);
            addBeg(data); break;
        case 5: // add at end
            printf("\nEnter data to insert:"); scanf("%d", &data);
            addEnd(data); break;
        case 6: // add after node
            addAfter(); break;
        case 7: // add before node
            addBefore(); break;
        case 8: value = deleteNode(); break;
        case 9: option = 9; break;
        default: printf("\nINVALID OPTION");
        }
    }
    free(start);
    return 0;
}
