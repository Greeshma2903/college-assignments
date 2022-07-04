/*
Write a C++ program to implement a Banking System application using array of structure variables. Program should provide following functionalities
    1. Create an array of objects
    2. A/C number should get generated automatically
    3. Menu driven o/p for providing deposit, withdrawal and check balance
    functionality
    4. All above operations should be performed only when A/C number is
    validated.
    5. For withdrawal operation minimum balance of 500/- needs to be checked.
    6. Number of transactions performed should be displayed for every
    customer.
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include<iomanip>


using namespace std;

class bankAccount
{
    char name[39];
    int IDproof;
    float amount;

public:
    int transactionCount, accNo;

    void accNumGeneration()
    {
        srand(time(0));
        accNo = (rand() % (80000000 - 1000000 + 1)) + 1000000;
    }

    void readDetails();
    void withDraw();
    void deposit();
    void checkBalance();
};

void bankAccount ::readDetails()
{
    cout << "\t Name: ";
    getchar();
    cin.getline(name, sizeof(name));
    cout << "\t ID Proof: ";
    cin >> IDproof;
    accNumGeneration();
    transactionCount = 0;
    amount = 0;
    cout<<"\n\tRemember your account number is: "<<accNo<<endl;
}

void bankAccount ::deposit()
{
    float depAmount;
    cout << "\nHow much amount do you want to deposit? \nRs: ";
    cin >> depAmount;
    amount = amount + depAmount;
    transactionCount++;
    cout << "\n"
         << depAmount << " amount credited to account.";
    cout << "\nTotal transactions made: " << transactionCount;
}

void bankAccount::withDraw()
{
    float drawAmount;
    if (amount <= 500)
    {
        cout << "\nSorry cannot withdraw amount, need minimum balance of Rs 500";
        return;
    }
readAmount:
    cout << "\nEnter the amount you want to withdraw: ";
    cin >> drawAmount;
    if (drawAmount >= amount)
    {
        cout << "\nInvalid amount; amount more than balance!";
        goto readAmount;
    }
    else
    {
        amount = amount - drawAmount;
        cout << "\n"
             << drawAmount << " amount debited from account";
        transactionCount++;
    }
}

void bankAccount::checkBalance()
{
    cout << "\nHello " << name;
    cout << "Here's your account balance: ---\n";
    cout << "\tTotal amount present: " << amount << endl;
    cout << "\tTotal transactions made: " << transactionCount << endl;
}

///////////
int validateAcc(bankAccount *b, int num, int accNo)
{
    cout << "\nEnter account number:";
    cin >> accNo;
    for (int i = 0; i < num; i++)
    {
        if (accNo == (b + i)->accNo)
        {
            return i; // account position
        }
    }
    return -1; // if account not present
}

int main()
{
    int i, accNo, pos;
    bankAccount acc[10];
    int option, customerCount;
    cout << "\n====================WELCOME==================\n";
    cout << "How many customers want to open account? (max 10)";
    cin >> customerCount;

    for (i = 0; i < customerCount; i++)
    {
        cout << "\nAccount " << i + 1 << ":--\n";
        acc[i].readDetails();
        cout << "\n----------------------------------";
    }
    do
    {
        cout << "\nSelect from below:\n";
        cout << "\n1. Deposit amount into account";
        cout << "\n2. Withdraw amount from account";
        cout << "\n3. Display account balance";
        cout << "\n4. Exit";
        cout << "\nEnter option:";
        cin >> option;

        switch (option)
        {
        case 1:
            pos = validateAcc(acc, customerCount, accNo);
            if (pos != -1)
                acc[pos].deposit();
            // if account not present
            else
                cout << "\nSorry! Either your account doesn't exist or entered wrong account number :(\n";
            cout << "\n----------------------------------";
            break;
        case 2:
            pos = validateAcc(acc, customerCount, accNo);
            if (pos != -1)
                acc[pos].withDraw();
            else
                cout << "\nSorry! Either your account doesn't exist or entered wrong account number :(\n";
            cout << "\n----------------------------------";
            break;
        case 3:
            pos = validateAcc(acc, customerCount, accNo);
            if (pos != -1)
                acc[pos].checkBalance();
            else
                cout << "\nSorry! Either your account doesn't exist or entered wrong account number :(\n";
            cout << "\n----------------------------------";
            break;
        case 4:
            option = 4;
            break;
        default:
            cout << "\nINVALID OPTION!";
            break;
        }
    } while (option != 4);

    return 0;
}
