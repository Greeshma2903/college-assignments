// WAP to perform following ops in Threaded Binary tree:
// 1. Insert
// 2. Delete
// 3. Display Binary tree
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    bool rthread;
    struct node *rchild;
    int data;
    struct node *lchild;
    bool lthread;
};

// Find Inorder Successor
struct node *inorderSuccessor(struct node *ptr)
{
    if (ptr->rthread == true)
        return ptr->rchild;

    ptr = ptr->rchild;
    while (ptr->lthread == false)
        ptr = ptr->lchild;
    return ptr;
}

// Find Inorder Predessesor
struct node *inorderPredecessor(struct node *ptr)
{
    if (ptr->lthread == true)
    {
        return ptr->lchild;
    }
    else
    {
        while (ptr->rthread == false)
            ptr = ptr->rchild;
        return ptr;
    }
}
// Insertion to TBST
struct node *insert(struct node *root, int ikey)
{
    struct node *tmp, *par, *ptr;
    int found = 0;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (ikey == ptr->data)
        {
            found = 1; break;
        }
        par = ptr;
        if (ikey < ptr->data)
        {
            if (ptr->lthread == false) ptr = ptr->lchild;
            else break;
        }
        else
        {
            if (ptr->rthread == false) ptr = ptr->rchild;
            else break;
        }
    }
    if (found)
        printf("\n=> Duplicate Key");
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = ikey;
        tmp->lthread = true;
        tmp->rthread = true;
        if (par == NULL)
        {
            root = tmp;
            tmp->lchild = NULL;
            tmp->rchild = NULL;
        }
        else if (ikey < par->data)
        {
            tmp->lchild = par->lchild;
            tmp->rchild = par;
            par->lthread = false;
            par->lchild = tmp;
        }
        else
        {
            tmp->rchild = par->rchild;
            tmp->lchild = par;
            par->rthread = false;
            par->rchild = tmp;
        }
    }
    return root;
}
// Display TBST
void display(struct node *ptr,int level)
{
    int i;
    if(ptr == NULL )
        return;
    else
    {
        if(ptr->rthread==false)
        display(ptr->rchild, level+1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->data);
        if(ptr->lthread==false)
        display(ptr->lchild, level+1);
    }
}

struct node *case_a(struct node *root, struct node *par, struct node *ptr)
{
    if(par == NULL)
    {
        root == NULL;
    }
    else if(par->lchild == ptr)
    {
        par->lthread = true; par->lchild = ptr->lchild;
    }
    else
    {
        par->rthread = true; par->rchild = ptr->rchild;
    }
    printf("\n=> %d deleted. ", ptr->data);
    free(ptr);
    return root;
}

struct node *case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *child, *p, *s;

    if(ptr->lthread == false) child = ptr->lchild;
    else child = ptr->rchild;

    if(par == NULL) root = child;
    else if(par->lchild == ptr) par->lchild = child;
    else par->rchild = child;

    s = inorderSuccessor(ptr);
    p = inorderPredecessor(ptr);
    if(ptr->lthread == false)
        p->rchild = s;
    else if(ptr->rthread == false)
        s->lchild = p;
    printf("\n=> %d deleted. ", ptr->data);
    free(ptr);
    return root;
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr)
{
    struct node *succ, *parsucc;
    parsucc = ptr;
    succ = ptr->rchild;
    while(succ->lchild != NULL)
    {
        parsucc = succ;
        succ = succ->lchild;
    }
    ptr->data = succ->data;
    if(succ->lthread == true && succ->rthread == true)
        root = case_a(root, parsucc, succ);
    else
        root = case_b(root, parsucc, succ);
    return root;
}

// Delete from TBST
struct node * delete(struct node *root, int dkey)
{
    struct node *par, *ptr;
    int found = 0;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (dkey == ptr->data)
        {
            found = 1; break;
        }
        par = ptr;
        if (dkey < ptr->data)
        {
            if (ptr->lthread == false) ptr = ptr->lchild;
            else break;
        }
        else
        {
            if (ptr->rthread == false) ptr = ptr->rchild;
            else break;
        }
    }
    if(found == 0)
        printf("\n%d not present in the tree", dkey);
    else if(ptr->lthread == false && ptr->rthread == false)
    {
        root = case_c(root, par, ptr);
    }
    else if(ptr->lthread == false)
    {
        root = case_b(root, par, ptr);
    }
    else if(ptr->rthread == false)
    {
        root = case_b(root, par, ptr);
    }
    else 
    {
        root = case_a(root, par, ptr);
    }
    return root;
}

// Main Function
int main()
{
    int option, data;
    struct node *root = NULL;
    do
    {
        printf("\n**************************");
        printf("\nChoose from following:\n1. Insert a node\n2. Delete a node\n3. Display Tree\n4. Exit\nEnter Choice:");
        scanf("%d", &option);
        printf("\n**************************");

        switch (option)
        {
        case 1:
            printf("\nEnter the element to be inserted:"); scanf("%d", &data);
            root = insert(root, data); break;
        case 2:
            printf("\nEnter the element to be deleted:"); scanf("%d", &data);
            root = delete(root, data); break;
        case 3:
            printf("\nThe TBST:\n"); display(root, 0); break;
        case 4: option = 4; break;
        default: printf("\nINVALID OPTION");
        }

    } while (option != 4);

    return 0;
}