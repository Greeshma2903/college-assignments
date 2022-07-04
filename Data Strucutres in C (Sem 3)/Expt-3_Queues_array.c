/*
WAP to implement a queue using array & perform the following operationsi
	1. Insert
	2. Delete
	3. Display element at the front 
    4. Display all elements in the queue
*/

#include <stdio.h>
#define MAX 5
int queue_arr[MAX];
int front = -1;
int rear = -1;

// insert into Queue
void insert()
{
    int item;
    printf("\nEnter element to be inserted: ");
    scanf("%d", &item);
    if (rear == MAX - 1)
    {
        printf("=> Queue is full!");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue_arr[rear] = item;
    printf("=> Inserted %d to queue", item);
}
// delete from Queue
void delete_ele()
{
    int item;
    if (front == -1 || front == rear + 1)
    {
        printf("=> Queue is Empty!");
        return;
    }
    item = queue_arr[front];
    front = front + 1;
    printf("=> Deleted %d", item);
}
// Display Queue
void display_queue()
{
    int i;
    printf("\nQueue:: \n");
    for (i = front; i <= rear; i++)
    {
        printf("%d  ", queue_arr[i]);
    }
    printf("\n");
}
// MAIN FUNCTION
int main()
{
    int option;

    do
    {
        printf("\n========================\n");
        printf("Choose an operation: \n");
        printf("1. Insert \n2. Delete\n3. Display element at front\n4. Display all elements in queue\n5. Exit");
        printf("\n\nEnter a option: ");
        scanf("%d", &option);
        printf("\n========================\n");

        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            delete_ele();
            break;
        case 3:
            printf("\nElement at the front is : %d", queue_arr[front]);
            break;
        case 4:
            display_queue();
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
