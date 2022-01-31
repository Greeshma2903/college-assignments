/*
2.WAP to implement circular linked list and perform following operations. 
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

struct node
{
    int data;
    struct node *next;
} * last;

// add to Empty list
void addEmpty(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = last;
    last = tmp;
    last->next = last;
    return;
}
// add to end of list
void addEnd(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = last->next;
    last->next = tmp;
    last = tmp;
    return;
}
// create LL
void createLL()
{
    last = NULL;
    int num, data, i;
    printf("\nHow many values you want to insert?"); scanf("%d", &num);

    if (num == 0)
    {
        return;
    }
    printf("\nEnter data to insert:"); scanf("%d", &data);
    addEmpty(data);
    for (i = 1; i < num; ++i)
    {
        printf("\nEnter data to insert:"); scanf("%d", &data);
        addEnd(data);
    }
}
// display list
void display()
{
    struct node *p;
    p = last->next;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
}
// add to beginning of list
void addBeg(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = last->next;
    last->next = tmp;
    return;
}
// add after a node
void addAfter()
{
    int data, ele;
    printf("\nEnter data to insert:"); scanf("%d", &data);
    printf("\nAfter which element to insert data? "); scanf("%d", &ele);
    struct node *tmp, *p;
    p = last->next;
    do
    {
        if (p->data == ele)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->data = data;
            tmp->next = p->next;
            p->next = tmp;
            if (p == last)
                last = tmp;
            return;
        }
        p = p->next;
    } while (p != last->next);
    printf("\n=> Element not found");
}
// add before a node
void addBefore()
{
    struct node *tmp, *p;
    int data, ele;
    printf("\nEnter data to insert:"); scanf("%d", &data);
    printf("\nBefore which element to insert data? "); scanf("%d", &ele);
    if (last->next->data == ele)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = data;
        tmp->next = last->next;
        last->next = tmp;
        return;
    }
    p = last->next;
    do
    {
        if (p->next->data == ele)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->data = data;
            tmp->next = p->next;
            p->next = tmp;
            return;
        }
        p = p->next;
    } while (p->next != last->next);
    printf("\n=> Element not found!");
}
// delete node
int deleteNode()
{
    int data, ele;
    struct node *p, *tmp;
    printf("\nEnter data to be deleted:");
    scanf("%d", &data);
    if (last->next == last && last->data == data)
    { // only node
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp = last;
        last = NULL;
        ele = tmp->data;
        free(tmp);
        return ele;
    }
    if (last->next->data == data)
    { // first node
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp = last->next;
        last->next = tmp->next;
        ele = tmp->data;
        free(tmp);
        return ele;
    }
    p = last->next;
    while (p->next != last)
    {
        if (p->next->data == data)
        { // in between
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp = p->next;
            p->next = tmp->next;
            ele = tmp->data;
            free(tmp);
            return ele;
        }
        p = p->next;
    }
    if (last->data == data)
    {   // last node
        tmp = last;
        p->next = last->next;
        last = p;
        ele = tmp->data;
        free(tmp);
        return ele;
    }
    printf("\nElement not found!");
}
// MAIN FUNCTION
int main()
{
    int option, data, value;
    do
    {
        printf("\n===================================\n");
        printf("\nChoose from options:\n1. Create LL\n2. Display LL\n3. Add to empty list\n4. Add at the beginning\n5. Add at the end\n6. Add after node\n7. Add before node\n8. Delete a node\n9. Exit\nEnter option:");
        scanf("%d", &option);
        printf("\n===================================\n");

        switch (option)
        {
        case 1: createLL(); break;
        case 2:  display(); break;
        case 3:
            if (last == NULL)
            {
                printf("\nEnter data to insert:");
                scanf("%d", &data);
                addEmpty(data);
            }
            else
            {
                printf("\nList not empty!");
            }
            break;
        case 4: // add at beginning
            printf("\nEnter data to insert:"); scanf("%d", &data);
            addBeg(data); break;
        case 5: // add at end
            printf("\nEnter data to insert:"); scanf("%d", &data);
            addEnd(data); break;
        case 6: addAfter(); break;
        case 7: addBefore(); break;
        case 8: // delete node
            if (last == NULL)
                printf("\n=> List is empty!");
            else
            {
                value = deleteNode();
            }
            break;
        case 9: option = 9; break;
        default: printf("\nINVALID OPTION");
        }
    } while (option != 9);
    return 0;
}