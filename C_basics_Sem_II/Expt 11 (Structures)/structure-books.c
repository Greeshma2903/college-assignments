/*
1. Add two more fields/variables to the structure: year of publication and publisher
2. Create array of 10 Books.
3. Accept the details from the User
4. Filter Arrays based on year of publication. Accept the year from user and display only those books published in the said year.
5. Compute the total price of all the books.
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct
{
    char title[50];
    char author[30];
    char isbn[20];
    float price;
    int publicationYear;
} Books; // structure names start with capitals (naming convention)

// Read books
void readBook(Books *b)
{
	fflush(stdin);	// to use fget and scanf together
	printf (" Title: ");
	fgets (b->title, sizeof(b->title), stdin);
	printf (" Author: ");
	fgets (b->author, sizeof(b->author), stdin);
	printf (" ISBN: ");
	fgets (b->isbn, sizeof(b->isbn), stdin);
	printf (" Price: ");
	scanf ("%f", &(b->price));
	printf (" Publication Year: ");
	scanf ("%d", &(b->publicationYear));
	printf ("\n------------------------------------------");
    return;
}

// Print book details
void printBook(Books *b)
{
    printf("\n Title: ");
    puts(b->title);
    printf(" Author: ");
    puts(b->author);
    printf(" ISBN: ");
    puts(b->isbn);
    printf(" Price: %f", b->price);
    printf("\n\n Publication Year: %d", b->publicationYear);
}

// Function to print the books of particular year
void filterBooks(Books arrBooks[], int pubYear)
{
    int i;
    printf("\n\n=> The following the the details of books published in %d year:--\n", pubYear);
    for (i = 0; i < 10; i++)
        if (arrBooks[i].publicationYear == pubYear)
        {
            printf("\n\nBook %d -------------", i+1);
            printBook(&arrBooks[i]);
        }
}

// Funtion to compute the total price of all books
float computeBooksPrice(Books arrBooks[])
{
    int i;
    float totalPrice = 0;
    for (i = 0; i < 10; i++)
        totalPrice += arrBooks[i].price;
    return totalPrice;
}

// Main function
int main()
{
    Books arrBooks[10];
    int i;
    int userYear;
    float totalPrice = 0;
    printf("YOU HAVE TO ENTER THE DETAILS OF 10 BOOKS.\n");
    for (i = 0; i < 10; i++)
    {
        printf("\n\nEnter details of book %d:----\n", i+1);
        readBook(&arrBooks[i]);
    }
    printf("\n------------------------------------------");

    printf("\n\nENTER A PUBLISHING YEAR:");
    scanf("%d", &userYear);
    filterBooks(arrBooks, userYear);

    printf("\n------------------------------------------");
    float total = computeBooksPrice(arrBooks);
    printf("\n\nTOTAL PRICE OF ALL THE BOOKS: ");
    printf("%f", total);

    return 0;
}
