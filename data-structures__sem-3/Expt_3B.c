/*
WAP to implement a queue using linked list and perform the following operations
	1. Insert
	2. Delete
	3. Display element at the front 
	4. Display all elements in the queue
*/

#include<stdio.h>
#include<stdlib.h>

// structure 
struct node {
    int data;
    struct node *link;
} *front = NULL, *rear = NULL;


// insert into Queue
void insert()
{
    int element;
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL) {
        printf("=> Queue Overflow!");
        return;
    }
    printf("Enter element to be inserted:");
    scanf("%d", &element);
    tmp->data = element;
    tmp->link = NULL;

    if(front == NULL) {
        front = tmp;
    }
    else
        rear->link = tmp;
    rear = tmp;
}

void delete_ele()
{
    int element;
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));

    if(front == NULL) {
        printf("\nQueue is Empty");
        return;
    }
    tmp = front;
    element = tmp->data;
    front = front->link;
    free(tmp);
    printf("=> Deleted %d", element);
}

void display()
{
    struct node *p;
    if(front == NULL) {
        printf("\nQueue is Empty!");
        return;
    }
    printf("QUEUE: \n=> ");
    for ( p = front; p != NULL; p = p->link)
    {
        printf("%d  ", p->data);
    }
    printf("\n");
}

int main(){
    int option;

    do {
        printf("\n========================\n");
        printf("Choose an operation: \n");
        printf("1. Insert \n2. Delete\n3. Display element at front\n4. Display all elements in queue\n5. Exit");
        printf("\n\nEnter a option: ");
        scanf("%d", &option);
        printf("\n========================\n");

        switch(option)
        {
            case 1:
                insert();
                break;
            case 2:
                delete_ele();
                break;
            case 3:
                printf("\nThe element in front is : %d", front->data);
                break;
            case 4:
                display();
                break;
            case 5:
                option = 5;
                break;
            default:
            printf("\nINVALID OPTION!!");
        }
    } while (option != 5);

    return 0;
}

