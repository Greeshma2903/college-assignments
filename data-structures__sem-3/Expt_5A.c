/*
1.  WAP to perform following operations in binary search tree. 
  a. Insert a node
  b. Delete a node
  c. Search for a node
  d. Display Tree
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *lchild;
  int data;
  struct node *rchild;
} *root = NULL;

// Insert function
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

// Display Binary tree
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

// Deletion in Binary Trees
void deleteBin()
{
  int dkey;
  struct node *par, *ptr, *parsucc, *succ, *child;
  ptr = root;
  par = NULL;
  printf("\nEnter node to be deleted:");
  scanf("%d", &dkey);
  // Search for the Node
  while (ptr != NULL)
  {
    if(dkey == ptr->data)
      break;
    par = ptr;
    if(dkey < ptr->data)
      ptr = ptr->lchild;
    else
      ptr = ptr->rchild;
  }
  if(par == NULL)
  {
    printf("\n => Element not found");
    return;
  }
  // case 3: Node has 2 children
  if(ptr->lchild != NULL && ptr->rchild != NULL)
  {
    parsucc = ptr;
    succ = ptr->rchild;
    while(ptr->lchild != NULL)
    {
      parsucc = succ;
      succ = succ->lchild;
    }
    ptr->data = succ->data;
    ptr = succ;
    par = parsucc;
  } 
  // case 2: Node has single child
  if(ptr->lchild != NULL)
    child = ptr->lchild;
  else
    child = ptr->rchild;
  if(par == NULL)
  root = child;
  if(par->lchild == ptr)
    par->lchild = child;
  else
    par->rchild = child;
  // Case 1: Node has no children
  free(ptr);  // Delete element
  return;
}

// Search for Node
void searchBin(){
  int value;
  printf("\nEnter element to search: ");
  scanf("%d", &value);
  struct node *ptr, *par;
  ptr = root; 
  par = NULL;
  while (ptr != NULL) {
    if(value == ptr->data)
    {
      printf("\n%d found", ptr->data);
      return;
    }
    if(value < ptr->data)
    {
      ptr = ptr->lchild;
    }
    else
    {
      ptr = ptr->rchild;
    }
  }
  if(ptr == NULL)
    printf("\nElement not found");
}

// MAIN FUNCTION
int main()
{
  int option;

  do
  {
    printf("\n**************************");
    printf("\nChoose from following:\n1. Insert a node\n2. Delete a node\n3. Search for a node\n4. Display Tree\n5. Exit\nEnter Choice:");
    scanf("%d", &option);
    printf("\n**************************");

    switch (option)
    {
    case 1:
      insertBin();
      break;
    case 2:
      deleteBin();
      break;
    case 3:
      searchBin();
      break;
    case 4:
      display(root, 0);
      break;
    case 5:
      option = 5;
      break;
    default:
      printf("\nINVALID OPTION");
    }

  } while (option != 5);

  return 0;
}