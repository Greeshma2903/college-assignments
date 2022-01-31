/*
Write a C program to implement a Banking System application using array of structure variables. Program should provide following functionalities
    1. Dynamically reserve the memory for array of structure variables by
    inputting from user as number of customers.
    2. A/C number should get generated automatically
    3. Menu driven o/p for providing deposit, withdrawal and check balancek
    functionality
    4. All above operations should be performed only when A/C number is
    validated.
    5. For withdrawal operation minimum balance of 500/- needs to be checked.
    6. Number of transactions performed should be displayed for every
    customer.
*/
// * HEADER FILES *
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// * STRUCTURE DEF*	
typedef struct
{
    char name[50];
    int IDproof;
    int dd, mm, yyyy;
    float amount;
    int transactionCount;
    int accNo;
} BankAccount;


int n;

// * FUNCTIONS *

// function to generate random account number
int accGenerate()
{
    int num;
    srand(time(0));
    num = (rand() % (80000000 - 1000000 + 1)) + 1000000;
    return num;
}

// function to read details of new customers
void readDetails(BankAccount *c, int num, int i)
{
    while(i < num)
    {
        printf("\n--------------------------------------------------------");
        printf("\nAccount holder %d:-\n", i + 1);
        getchar();
        printf("\tYour name: ");
        fgets((c + i)->name, sizeof((c + i)->name), stdin);
        printf("\tID proof: ");
        scanf("%d", &(c + i)->IDproof);
        printf("\tDate of Birth (mm/dd/yyy) :");
        scanf("%d/%d/%d", &(c + i)->dd, &(c + i)->mm, &(c + i)->yyyy);
        getchar();
        (c + i)->transactionCount = 0;  // initialize trasaction count as 0

        // to generate account number
        int acc = accGenerate();
        printf("\nYour account has been created!");
        printf("\nRemember your account number: %d\n", acc);
        (c + i)->accNo = acc;
        i++;
    }
}

// function to read and validate account number against data entered by user
int validateAcc(BankAccount *c, int num)
{
    int acc, i;
    printf("\nEnter account number: ");
    scanf("%d", &acc);
    // check if account number entered is valid
    for (i = 0; i < num; i++)
    {
        if (acc == (c + i)->accNo)
        {
            return i; // return account postion
        }
    }
    return -1; // return -1 if account not present
}

// function to perform deposit of money
void deposit(BankAccount *c, int pos)
{
    float money;
    printf("\nHello %s", (c + pos)->name);
    printf("How much amount do you want to deposit?\nRs: ");
    scanf("%f", &money);
    (c + pos)->amount = (c + pos)->amount + money; // add money to amount
    ((c + pos)->transactionCount)++;               // increment transaction count

    printf("\nRs.%.2f credited to your account!", money);
    printf("\nTotal transactions made: %d", (c + pos)->transactionCount); // display transaction count to user
    printf("\nThank you for using this service :)");
    printf("\n=====================================================\n");
}

// function to perform withdrawl of money
void withdraw(BankAccount *c, int pos)
{
    float money;
    // check minimum balance for withdrawl
    if ((c + pos)->amount >= 500)
    {
        printf("\nHello %s", (c + pos)->name);

    askAmount:
        printf("\nHow much amount to be withdrawn? :");
        scanf("%f", &money);
        if (money <= ((c + pos)->amount)) // check if withdrawl amount is less than account balance
        {
            (c + pos)->amount = (c + pos)->amount - money; // subtract withdrawn amount
            ((c + pos)->transactionCount)++;               // increment transaction count

            printf("\nRs.%.2f debited from your account!", money);
            printf("\nTotal transactions made: %d", (c + pos)->transactionCount); // display transaction count to user
            printf("\nThank you for using this service :)");
            printf("\n=====================================================\n");
        }
        else
        {
            printf("\nYou cannot withdraw more than Rs.%f", (c + pos)->amount);
            goto askAmount;
        }
    }
    else
    {
        printf("\nInsufficient balance in account! Add minimum Rs.500 to withdraw money.");
        printf("\n=====================================================\n");
    }
}

// function to display amount present in account
void checkBalance(BankAccount *c, int pos)
{
    printf("\nHello %s Here's your account details:\n", (c + pos)->name);
    printf("\nThe total amount present in your account: %f", (c + pos)->amount);
    printf("\nTotal transaction made till now: %d", (c + pos)->transactionCount);
    printf("\n\nThank you for using this service :)");
    printf("\n=====================================================\n");
}

void printDetails(BankAccount *c, int pos)
{
    printf("\n------------------------->\n");
    printf("\nAccount name: %s", (c + pos)->name);
    printf("ID proof: %d", (c + pos)->IDproof);
    printf("\nDoB: %d/%d/%d", (c + pos)->dd, (c + pos)->mm, (c + pos)->yyyy);
    printf("\nAccount Number: %d", (c + pos)->accNo);
    printf("\nThe total amount present in your account: %.2f", (c + pos)->amount);
    printf("\nTotal transaction made till now: %d", (c + pos)->transactionCount);
    printf("\n=====================================================\n");
    return;
}


// * MAIN FUNCTION *
int main()
{
    BankAccount *customer;
    int option, acc, i, pos, moreAcc, prevAcc;

    printf("====================== WELCOME ======================");
    printf("\nHow many customers want to open account? : ");
    scanf("%d", &n);
    // dynamically reserved memory
    customer = (BankAccount *)malloc(n * sizeof(BankAccount));

	if (customer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
    	// read customer details
	    printf("\nENTER DETAILS :");
        moreAcc = 0;
	    readDetails(customer, n, moreAcc);
    	do
	    {
	        printf("\n=====================================================\n");
	        // display options to user
	        printf("\n\nWHAT DO YOU WANT TO DO?\n");
	        printf("\n----------------------------------------------------\n");
	        printf("1. Deposit money in account");
	        printf("\n2. Withdraw money from account");
	        printf("\n3. Check balance amount in account");
	        printf("\n4. Display account details");
	        printf("\n5. Do you want to add more accounts?");
	        printf("\n6. Exit");
	        printf("\n----------------------\nEnter option:");
	        scanf("%d", &option);
	        printf("\n=====================================================\n");
	
	        switch (option)
	        {
	        case 1:
	            pos = validateAcc(customer, n); // validate and get position of account in array
	            if (pos != -1)
	                deposit(customer, pos);
	            // if account not present
	            else
	                printf("\nSorry! Either your account doesn't exist or entered wrong account number :(");
	            break;
	        case 2:
	            pos = validateAcc(customer, n);
	            if (pos != -1)
	                withdraw(customer, pos);
	            else
	                printf("\nSorry! Either your account doesn't exist or entered wrong account number :(");
	            break;
	        case 3:
	            pos = validateAcc(customer, n);
	            if (pos != -1)
	                checkBalance(customer, pos);
	            else
	                printf("\nSorry! Either your account doesn't exist or entered wrong account number :(");
	            break;
	        case 4:
	            pos = validateAcc(customer, n);
	            if (pos != -1)
	                printDetails(customer, pos);
	            else
	                printf("\nSorry! Either your account doesn't exist or entered wrong account number :(");
	            break;
       		case 5:
	         	printf("\nHow many more accounts do you want to add? ");
	         	scanf("%d", &moreAcc);
                prevAcc = n;
                n = n+moreAcc;
                customer = realloc(customer, n * sizeof(customer));
                readDetails(customer, n, prevAcc);
	         	break;
	        case 6:
	            option = 6; // exit condition
	            break;
	        default:
	            printf("INVALID OPTION!");
	            break;
	        }
	    } while (option != 6);
    
	}
	    

    // free memory at end of program
    free(customer);

    return 0;
}
