// WAP to implement following traversal in Threaded Binary Search tree:
// 1. Inorder
// 2. Preorder
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Node
{
    struct Node *left, *right;
    int info;
    bool lthread;
    bool rthread;
};

// INSERTION TO TBST
struct Node *insert(struct Node *root, int ikey)
{
    struct Node *tmp, *par, *ptr;
    int found = 0;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (ikey == ptr->info)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (ikey < ptr->info)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (found)
        printf("\n=> Duplicate Key");
    else
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->info = ikey;
        tmp->lthread = true;
        tmp->rthread = true;
        if (par == NULL)
        {
            printf("blockpar");
            root = tmp;
            tmp->left = NULL;
            tmp->right = NULL;
        }
        else if (ikey < par->info)
        {
            tmp->left = par->left;
            tmp->right = par;
            par->lthread = false;
            par->left = tmp;
        }
        else
        {
            tmp->right = par->right;
            tmp->left = par;
            par->rthread = false;
            par->right = tmp;
        }
    }
    return root;
}

// Returns inorder successor using rthread
struct Node *inorderSuccessor(struct Node *ptr)
{
    if (ptr->rthread == true)
        return ptr->right;

    ptr = ptr->right;
    while (ptr->lthread == false)
        ptr = ptr->left;
    return ptr;
}

// INORDER TRAVERSAL
void inorder(struct Node *root)
{
    if (root == NULL)
        printf("Tree is empty");

    struct Node *ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;

    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = inorderSuccessor(ptr);
    }
}
// PREORDER TRAVERSAL
void preorder(struct Node *root)
{
    struct Node *ptr;
    if (root == NULL)
    {
        printf("\nTree is empty");
        return;
    }
    ptr = root;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        if (ptr->lthread == false)
        {
            ptr = ptr->left;
        }
        else if (ptr->rthread == false)
        {
            ptr = ptr->right;
        }
        else
        {
            while (ptr != NULL && ptr->rthread == true)
            {
                ptr = ptr->right;
            }
            if (ptr != NULL)
            {
                ptr = ptr->right;
            }
        }
    }
}
// MAIN FUNCTION
int main()
{
    struct Node *root = NULL;
    int option, data;
    do
    {
        printf("\n**************************");
        printf("\nChoose from following:\n1. Insert a node\n2. Inorder Traversal\n3. Preorder Traversal\n4. Exit\nEnter Choice:");
        scanf("%d", &option);
        printf("\n**************************");

        switch (option)
        {
        case 1:
            printf("\nEnter the element to be inserted:");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("\nInorder Traversal:\n=> ");
            inorder(root);
            break;
        case 3:
            printf("\nPreorder Traversal:\n=> ");
            preorder(root);
            break;
        case 4:
            option = 4;
            break;
        default:
            printf("\nINVALID OPTION");
        }

    } while (option != 4);

    return 0;
}