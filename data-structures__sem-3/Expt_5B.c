//  2.  WAP to implement following traversals in binary tree.
//   a. Pre-order
//   b. In-order
//   c. Post-Order
//   d. Level- Order

#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct node
{
    struct node *lchild;
    char data;
    struct node *rchild;
} *root = NULL;

struct node *queue_arr[MAX];
int front = -1;
int rear = -1;

// check empty queue
int queue_empty()
{
    if (front == -1 || front == rear + 1) return 1;
    else return 0;
}

// insert into Queue
void insert_queue(struct node *item)
{
    if (rear == MAX - 1)
    {
        printf("=> Queue is full!");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue_arr[rear] = item;
}
// delete from Queue
struct node *delete_queue()
{
    struct node *item;
    if (front == -1 || front == rear + 1)
    {
        printf("=> Queue is Empty!");
        exit(1);
    }
    item = queue_arr[front];
    front = front + 1;
    return item;
}

void insertBin()
{
    int data;
    struct node *tmp, *par, *ptr;
    printf("\nEnter data to be inserted: ");
    scanf("%d", &data);
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        par = ptr;
        if (data < ptr->data)
        {
            ptr = ptr->lchild;
        }
        else if (data > ptr->data)
        {
            ptr = ptr->rchild;
        }
        else
        {
            printf("\nDulplicate Key");
            return;
        }
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if (par == NULL)
        root = tmp;
    else if (data < par->data)
    {
        par->lchild = tmp;
    }
    else
        par->rchild = tmp;
    return;
}

void preorder(struct node *p)
{
    if (p == NULL)
        return;
    printf("%d   ", p->data);
    preorder(p->lchild);
    preorder(p->rchild);
}

void inorder(struct node *p)
{
    if (p == NULL)
        return;
    inorder(p->lchild);
    printf("%d   ", p->data);
    inorder(p->rchild);
}

void postorder(struct node *p)
{
    if (p == NULL)
        return;
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d   ", p->data);
}

void levelorder(struct node *p)
{
    struct node *ptr = p;
    if (ptr == NULL)
    {
        printf("\nTree is empty!");
        return;
    }
    insert_queue(ptr);
    while (!queue_empty())
    {
        ptr = delete_queue();
        printf("%d  ", ptr->data);
        if (ptr->lchild != NULL) insert_queue(ptr->lchild);
        if (ptr->rchild != NULL) insert_queue(ptr->rchild);
    }
    printf("\n");
}

int main()
{
    int option, num, i;

    printf("\nHow many elements do you want to insert?");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
        insertBin();

    do
    {
        printf("\n**************************");
        printf("\nChoose from following:\n1. Pre-order\n2. In-order\n3. Post-order\n4. Level-order\n5. Exit\nEnter Choice:");
        scanf("%d", &option);
        printf("\n**************************\n");
        switch (option)
        {
        case 1:
            printf("\nPreorder Traversal: \n=> "); preorder(root); printf("\n");
            break;
        case 2:
            printf("\nInorder Traversal: \n=> "); inorder(root); printf("\n");
            break;
        case 3:
            printf("\nPostorder Traversal: \n=> "); postorder(root); printf("\n");
            break;
        case 4:
            printf("\nLevel Traversal: \n=> "); levelorder(root);
            break;
        case 5: option = 5; break;
        default: printf("\nINVALID OPTION");
        }
    } while (option != 5);
    return 0;
}