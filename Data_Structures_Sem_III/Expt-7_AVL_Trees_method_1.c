// Wap to implement the foll AVL:
// 1. insertion in left subtree
// 2. insertion in right subtree
// 3. deletion from left subtree
// 4.  deletin from right subtree
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	struct node *lchild, *rchild;
	int data;
	int balance;
};

// -------------------------------------- rotation
struct node *RotateRight(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->lchild;
	pptr->lchild = aptr->rchild;
	aptr->rchild = pptr;
	return aptr;
}

struct node *RotateLeft(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->rchild;
	pptr->rchild = aptr->lchild;
	aptr->lchild = pptr;
	return aptr;
}

// ------------------------------------------ insertion
struct node *insert_LeftBalance(struct node *pptr)
{
	struct node *aptr, *bptr;
	aptr = pptr->lchild;
	if (aptr->balance == 1)
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else
	{
		bptr = aptr->rchild;
		switch (bptr->balance)
		{
		case -1:
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		case 1:
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case 0:
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}

struct node *insert_left_check(struct node *pptr, int *ptaller)
{
	switch (pptr->balance)
	{
	case 0:		// if P was balanced, it becomes left-heavy
		pptr->balance = 1;
		break;
	case -1:	// if P was right-heavy, it becomes balanced
		pptr->balance = 0;
		*ptaller = false;
		break;
	case 1:		// if P was left-heavy, hence becomes further imbalanced
		pptr = insert_LeftBalance(pptr);
		*ptaller = false;
		break;
	}
	return pptr;
}

struct node *insert_RightBalance(struct node *pptr)
{
	struct node *aptr, *bptr;
	aptr = pptr->rchild;
	if (aptr->balance == -1)	// case R_C1
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else						// case R_C2
	{
		bptr = aptr->lchild;
		switch (bptr->balance)
		{
		case -1:	// R_C2a
			pptr->balance = 1;
			aptr->balance = 0;
			break;
		case 1:		// R_C2b
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case 0:		// R_C2c
			pptr->balance = 0;
			aptr->balance = 0;
			break;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}

struct node *insert_right_check(struct node *pptr, int *ptaller)
{
	switch (pptr->balance)
	{
	case 0:		// if P was balanced, P becomes right-heavy
		pptr->balance = -1;
		break;
	case 1:		// if P was left-heavy, P becomes balanced
		pptr->balance = 0;
		*ptaller = false;
		break;
	case -1:	// if P was right-heavy, P is unbalanced
		pptr = insert_RightBalance(pptr);
		*ptaller = false;
	}
	return pptr;
}

struct node *insert(struct node *pptr, int ikey)
{
	static int taller;
	if (pptr == NULL)
	{
		pptr = (struct node *)malloc(sizeof(struct node));
		pptr->data = ikey;
		pptr->rchild = NULL;
		pptr->lchild = NULL;
		pptr->balance = 0;
		taller = true;
	}
	else if (ikey < pptr->data)
	{
		pptr->lchild = insert(pptr->lchild, ikey);
		if (taller == true)
		{
			pptr = insert_left_check(pptr, &taller);
		}
	}
	else if (ikey > pptr->data)
	{
		pptr->rchild = insert(pptr->rchild, ikey);
		if (taller == true)
			pptr = insert_right_check(pptr, &taller);
	}
	else
	{
		printf("\n=> Duplicate Key\n");
		taller = false;
	}
	return pptr;
}
// --------------------------------------------------- deletion
struct node *del_RightBalance(struct node *pptr, int *pshorter)
{
	struct node *aptr, *bptr;
	aptr = pptr->rchild;
	if (aptr->balance == 0)
	{
		pptr->balance = -1;
		aptr->balance = 1;
		*pshorter = false;
		pptr = RotateLeft(pptr);
	}
	else if (aptr->balance == -1)
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else
	{
		bptr = aptr->lchild;
		switch (bptr->balance)
		{
		case 0:
			pptr->balance = 0;
			aptr->balance = 0;
			break;
		case 1:
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case -1:
			pptr->balance = 1;
			aptr->balance = 0;
			break;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}

struct node *del_LeftBalance(struct node *pptr, int *pshorter)
{
	struct node *aptr, *bptr;
	aptr = pptr->lchild;
	if (aptr->balance == 0)
	{
		pptr->balance = 1;
		aptr->balance = -1;
		*pshorter = false;
		pptr = RotateLeft(pptr);
	}
	else if (aptr->balance == 1)
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else
	{
		bptr = aptr->rchild;
		switch (bptr->balance)
		{
		case 0:
			pptr->balance = 0;
			aptr->balance = 0;
			break;
		case 1:
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case -1:
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}


struct node *del_left_check(struct node *pptr, int *pshorter)
{
	switch (pptr->balance)
	{
	case 0:
		pptr->balance = 1;
		*pshorter = false;
		break;
	case 1:
		pptr->balance = 0;
		break;
	case -1:
		pptr = del_RightBalance(pptr, pshorter);
		break;
	}
	return pptr;
}

struct node *del_right_check(struct node *pptr, int *pshorter)
{
	switch (pptr->balance)
	{
	case 0:
		pptr->balance = 1;
		*pshorter = false;
		break;
	case -1:
		pptr->balance = 0;
		break;
	case 1:
		pptr = del_LeftBalance(pptr, pshorter);
		break;
	}
	return pptr;
}

// DELETION
struct node *delete(struct node *pptr, int dkey)
{
	static int shorter;
	struct node *tmp, *succ;
	if (pptr == NULL)
	{
		printf("\n=> Key not found\n");
		shorter = false;
		return pptr;
	}
	else if (dkey < pptr->data)
	{
		pptr->lchild = delete(pptr->lchild, dkey);
		if (shorter == true)
			pptr = del_left_check(pptr, &shorter);
	}
	else if (dkey > pptr->data)
	{
		pptr->rchild = delete(pptr->rchild, dkey);
		if (shorter == true)
			pptr = del_right_check(pptr, &shorter);
	}
	else
	{
		if (pptr->lchild != NULL && pptr->rchild != NULL)
		{
			succ = pptr->rchild;
			while (succ->lchild != NULL)
				succ = succ->lchild;
			pptr->data = succ->data;
			pptr->rchild = delete(pptr->rchild, succ->data);
			if (shorter == true)
				pptr = del_right_check(pptr, &shorter);
		}
		else
		{
			tmp = pptr;
			if (pptr->lchild != NULL)
				pptr = pptr->lchild;
			else if (pptr->rchild != NULL)
				pptr = pptr->rchild;
			else
				pptr = NULL;
			free(tmp);
			shorter = true;
		}
	}
	return pptr;
}
// ----------------------------------- Display function
void display(struct node *p, int level)
{
	int i;
	if(p == NULL)
		return;
	display(p->rchild, level+1);
	printf("\n");

	for(i = 0; i<level; i++)
  {
		printf("   ");
  }
  if(p->rchild != NULL && p->lchild != NULL)
	  printf("%d <", p->data);
  else if(p->rchild != NULL && p->lchild == NULL)
  {
    printf("%d /", p->data);
  }
  else if(p->rchild == NULL && p->lchild != NULL)
  {
    printf("%d \\", p->data);
  }
  else
  {
    printf("%d  ", p->data);
  }
  
	display(p->lchild, level+1);

}

// -------------------------------------------- Main Function
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
            printf("\nEnter the element to be inserted:");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("\nEnter the element to be deleted:");
            scanf("%d", &data);
            root = delete(root, data);
            break;
        case 3:
            printf("\nThe AVL Tree:\n");
            display(root, 0);
            break;
        case 4:
            option = 4;
            break;
        default:
            printf("\nINVALID OPTION");
        }

    } while (option != 4);
}