/*
WAP to implement a queue using circular Linked List and perform 
	1. Insert
	2. Delete
    3. Display
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *rear = NULL;

void insert()
{
    int element;
    printf("\nEnter element to be inserted:");
    scanf("%d", &element);
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = element;
    if (rear == NULL)
    {
        rear = tmp;
        tmp->link = tmp;
    }
    tmp->link = rear->link;
    rear->link = tmp;
    rear = tmp;
}

void delete_ele()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (rear == NULL)
    {
        printf("\nQueue Underflow!!");
        return;
    }

    if (rear->link == rear)
    {
        tmp = rear;
        rear = NULL;
    }
    else
    {
        tmp = rear->link;
        rear->link = tmp->link;
    }
    int data = tmp->data;
    free(tmp);
    printf("=> Deleted %d.\n", data);
}

void display()
{
    struct node *p;
    if(rear == NULL)
    {
        printf("\nEmpty list!!");
        return;
    }
    printf("The List is: \n");
    p = rear->link;
    do
    {
        printf("%d  ", p->data);
        p = p->link;
    } while (p != rear->link);
}

int main()
{
    int option;

    do
    {
        printf("\n=======================\n");
        printf("\nChoose from following:\n");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter option: ");
        scanf("%d", &option);
        printf("\n=======================\n");

        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            delete_ele();
            break;
        case 3:
            display();
            break;
        case 4:
            option = 4;
            break;
        default:
            printf("Invalid option!");
        }
    } while (option != 4);
}
