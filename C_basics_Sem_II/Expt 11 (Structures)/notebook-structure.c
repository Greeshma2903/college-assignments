/*
Implement a menu driven application for the following:
    a. A stationery store: store contains a collection of notebooks and pens. Each store
    additionally contains the store location and owner name.
    b. Each notebook in the store can be of two type: soft bound and hard bound.
    Additionally notebook contains brand,price and number of pages.
    c. Each pen can of two types: ink pens and ball point pens. Additionally a pen can be
    defined by its colour and price.
    d. Create appropriate structures to simulate the above scenario.
    e. Write appropriate functions to do the following:
        i. Add a notebook in the store
        ii. Delete a notebook from the store
        iii. Update price of certain brand of books.
        iv. Filter the search in the store based on brand of notebooks.
        v. Find the total books and pens available at a particular store.(take the
        location from the user)

stationery
{
    struct notebook {
        type[5]
        char brand[]
        float price
        int pages
    };
    struct pens {
        penType[2];
        char color
        float price
    }
    int location;
    char ownerName[];
}

functions;
    addNotebook
    Delete Notebook
    Update notebook price
    brandNotebook
    countBooksPensStore
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 20

typedef struct
{
    char boundType[6];
    float price;
    char brand[30];
    int pages;
} Notebook;

typedef struct
{
    char penType[6];
    char color[10];
    float price;
} Pen;

typedef struct
{
    Notebook n[MAX_SIZE];
    Pen p[MAX_SIZE];
    int location;
    char ownerName[30];
} StationeryStore;

int addNotebook(StationeryStore *ptrStore, int location);
int deleteNotebook(StationeryStore *ptrStore, int numNotebooks);
void updateNotebookPrice(StationeryStore *ptrStr, char brand[], int numNotebooks);
void searchBrand(StationeryStore *ptrStr, int numNotebooks);
int addPens(StationeryStore *ptrStr);

int main()
{
    StationeryStore store[MAX_SIZE];

    int option, location, count_added_notebooks[MAX_SIZE], count_added_pens[MAX_SIZE];
    char ans = 'y', noteBrand[30];

    // loop starts
    do
    {
        // show users options
        printf("\n============================================\n");
        printf("WHAT WOULD YOU LIKE TO DO?");
        printf("\n1. Add a notebook in the store");
        printf("\n2. Delete a notebook from the store");
        printf("\n3. Update price of certain brand of books");
        printf("\n4. Filter the search in the store based on brand of notebooks");
        printf("\n5. Find the total books and pens available at a store");
        printf("\n6. Add pens in store");
        printf("\n\nEnter your option:");
        scanf("%d", &option);

        printf("\n-------------------------------------------\n");

        switch (option)
        {
            // add notebook (based on store location)
        case 1:
            printf("\nEnter the store location (<20):");
            scanf("%d", &location);
            count_added_notebooks[location] = addNotebook(&store[location], location);  // keep count on no. of notebooks in store
            break;

            // delete notebooks in a store
        case 2:
            printf("\nEnter the store location(<20):");
            scanf("%d", &location);
            if (count_added_notebooks[location] == 0)
                printf("\nSorry, There are no notebooks at the store!");
            else
                count_added_notebooks[location] = deleteNotebook(&store[location], count_added_notebooks[location]);
            break;

            // Update prices of certain brand of notebooks
        case 3:
            printf("\nEnter the store location(<20):");
            scanf("%d", &location);
            fflush(stdin);
            printf("\nEnter the brand of notebooks (whose price to be updated):");
            // fgets(noteBrand, sizeof(noteBrand), stdin);
            scanf("%s", noteBrand);
            updateNotebookPrice(&store[location], noteBrand, count_added_notebooks[location]);
            break;

            // filter notebooks in store of a brand
        case 4:
            printf("\nEnter the store location(<20):");
            scanf("%d", &location);
            searchBrand(&store[location], count_added_notebooks[location]);
            break;

            // count total notebooks and pens in store
        case 5:
            printf("\nEnter the store location(<20):");
            scanf("%d", &location);
            printf("\nTotal Notebooks at store: %d", count_added_notebooks[location]);
            printf("\nTotal Pens at store: %d", count_added_pens[location]);
            break;

            // add pens to the store
        case 6:
            printf("\nEnter the store location(<20):");
            scanf("%d", &location);
            count_added_pens[location] = addPens(&store[location]);
            break;

        default:
            printf("\nInvalid option.");
            break;
        }
        fflush(stdin);
        printf("\n----------------------------------------");
        printf("\nDo you want to continue? (y/n)");     // ask user if they want to continue loop
        scanf("%c", &ans);

    } while (ans == 'Y' || ans == 'y');

    return 0;
}

// function to add notebooks to store
int addNotebook(StationeryStore *ptrStore, int location)
{
    int numberNotebooks, i;
    fflush(stdin);

    // read store location and owner name
    ptrStore->location = location;  
    printf("\nEnter the Store's Owner's name:");
    fgets(ptrStore->ownerName, sizeof(ptrStore->ownerName), stdin);

    printf("\nHow many notebooks do you want to add? :");
    scanf("%d", &numberNotebooks);
    for (i = 0; i < numberNotebooks; i++)
    {
        fflush(stdin);
        printf("\nDetails Notebook %d ---", i + 1);
        printf("\nEnter bound of notebook (hard/soft)");
        fgets(ptrStore->n->boundType, sizeof(ptrStore->n->boundType), stdin);
        printf("Enter notebook brand:");
        fgets(ptrStore->n->brand, sizeof(ptrStore->n->brand), stdin);
        printf("Enter notebook price:");
        scanf("%f", &(ptrStore->n->price));
        printf("Enter number of pages:");
        scanf("%d", &(ptrStore->n->pages));
    }
    return numberNotebooks;     // return count of notebooks in store
}

// function to delete notebook in store
int deleteNotebook(StationeryStore *ptrStore, int numNotebooks)
{
    int delNotebookNum, i, count = 0;
    
    printf("\nEnter number of the notebook to be deleted(1-%d):", numNotebooks);
    scanf("%d", &delNotebookNum);
    delNotebookNum--;

    for (i = 0; i < numNotebooks; i++)
    {
        if (i == delNotebookNum)    // shift array elements to delete an element
        {
            ptrStore->n[i] = ptrStore->n[i + 1];
            count++;
        }
    }
    
    if ( count != 0)
        printf("\nNotebook deleted!");

    numNotebooks--;
    return numNotebooks;
}

// function to update prices of certain brand of notebooks
void updateNotebookPrice(StationeryStore *ptrStr, char brand[], int numNotebooks)
{
    int i, count = 0;
    float newPrice;

    printf("\nWhat is the new price of the %s notebooks? : ", brand);
    scanf("%f", &newPrice);
    for (i = 0; i < numNotebooks; i++)
    {
        if (strcmp(ptrStr->n->brand, brand) == 0)
        {
            ptrStr->n->price = newPrice;
            count++;
        }
    }

    if (count != 0)
        printf("\nPrices updated!");
    else
        printf("\nNo notebooks of the brand exist!");
}

// function to search and list a brand of notebooks in a store
void searchBrand(StationeryStore *ptrStr, int numNotebooks)
{
    char brand[30];
    int i, count= 0;
    fflush(stdin);
    printf("\nEnter the brand of notebooks you wish to search:");
    scanf("%s", brand);

    printf("\nThe following are the list of books of brand %s", brand);
    for (i = 0; i < numNotebooks; i++)
    {
        if (strcmp(ptrStr->n->brand, brand) == 0)
        {
            printf("\n------/");
            printf("\nType of book: %s", ptrStr->n->boundType);
            printf("\nPrice: %f", ptrStr->n->price);
            printf("\nNo of pages: %d", ptrStr->n->pages);
            count++;
        }
    }
    if (count == 0)
        printf("\nNo notebooks of the brand exist!");
        
}

// function to add pens to store
int addPens(StationeryStore *ptrStr)
{
    int numPens, i;
    printf("\nHow many pens do you want to add?");
    scanf("%d", &numPens);
    for (i = 0; i < numPens; i++)
    {
        fflush(stdin);
        printf("\nDetails pen %d ---", i + 1);
        printf("\nType (ink/ball):");
        fgets(ptrStr->p->penType, sizeof(ptrStr->p->penType), stdin);
        printf("Color:");
        fgets(ptrStr->p->color, sizeof(ptrStr->p->color), stdin);
        printf("Price:");
        scanf("%f", &(ptrStr->p->price));
    }
    return numPens;
}
