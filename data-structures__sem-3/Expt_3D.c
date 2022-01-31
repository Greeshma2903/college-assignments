// Implement circular queue using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

void insert()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
    {
        printf("\nQueue Overflow");
        return;
    }
    int data;
    printf("\nEnter the data to insert:");
    scanf("%d", &data);
    if (front == -1)
        front = 0;
    if(rear == MAX - 1)
        rear = 0;
    else
        rear = rear + 1;
    cqueue_arr[rear] = data;
    printf("\n=>%d inserted to queue", data);
}

void delete ()
{
    if (front == -1)
    {
        printf("\nQueue Underflow");
        return;
    }
    int data = cqueue_arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = front + 1;
    printf("\n=> %d deleted.", data);
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue Underflow");
        return;
    }
    printf("\nQueue:- \n");
    for (i = front; i <= rear; i++)
    {
        printf("%d  ", cqueue_arr[i]);
    }
    printf("\n");
}

int main()
{
    int option;

    while (option != 4)
    {
        printf("\n================================");
        printf("\nChoose from the following:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter option:");
        scanf("%d", &option);
        printf("\n================================");

        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
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
    }

    return 0;
}