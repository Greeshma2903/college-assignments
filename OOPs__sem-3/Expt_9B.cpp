/*
Write a C++ program to simulate a telephone directory application. Program should
prompt user to enter name and telephone number of users. Also the program should allow
the user to search and update the telephone number of a specific user depending upon the
name
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#define MAX 50
using namespace std;
fstream fio;
/* -------------------------------------- class definition */
class Record
{
    int telNo;
    char name[MAX];

public:
    void readDetails();
    int compare(char *);
    int search(char *);
    void update();
    void display();
};

void Record::readDetails()
{
    cout << "Name:";
    cin.getline(name, sizeof(name));
    cout << "Telephone No: ";
    cin >> telNo;
}

int Record::compare(char *userName)
{
    return strcmp(name, userName);
}

int Record::search(char *userName)
{
    if (compare(userName) == 0)
    {
        cout << "\n=> Telephone No of " << name << ": " << telNo << endl;
        return 1;
    }
    return 0;
}

void Record::update()
{
    cout << "\nEnter new Telephone No:";
    cin >> telNo;
}

void Record::display()
{
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(20) << name << setw(13) << telNo << endl;
}
/* ------------------------------- class definition ends */

/* ------------------------------------------ FUNCTIONS */
// Add user records to file
void readRecords(int count)
{
    int i;
    Record user;
    fio.open("recordDirectory", ios::out | ios::trunc | ios::binary);
    if (!fio)
    {
        cout << "\nCannot open file!"; return;
    }
    cout << "\nEnter User Details: \n";
    for (i = 0; i < count; i++)
    {
        cout << i + 1 << endl;
        cin.ignore();
        user.readDetails(); 
        fio.write((char *)&user, sizeof(user));
        cout << "------------\n";
    }
    fio.close();
}

// Search user record
void searchUser(int count)
{
    char userName[MAX];
    Record user;
    int i = 0;
    fio.open("recordDirectory", ios::in | ios::binary);
    if (!fio)
    {
        cout << "\nCannot open file!"; return;
    }

    cin.ignore();
    cout << "\nEnter the name of user to be searched?";
    cin.getline(userName, sizeof(userName));

    while (i < count)
    {
        fio.read((char *)&user, sizeof(user));
        if (user.search(userName))
        {
            fio.close();
            return;
        }
        ++i;
    }
    cout << "\nUser record doesn't exist.";
    fio.close();
}

// Update user record
void updateUser(int count)
{
    char userName[MAX];
    Record user;
    int pos, i = 0, flag = 0;
    // Open files in Read/Write
    fio.open("recordDirectory", ios::in | ios::out | ios::binary);
    if (!fio)
    {  
        cout << "\nCannot open file!"; return;
    }

    cin.ignore();
    cout << "\nEnter the name of user: ";
    cin.getline(userName, sizeof(userName));

    while (!fio.eof())
    {
        pos = fio.tellg();  // read position of record
        fio.read((char *)&user, sizeof(user));

        if (fio)
        {   // compare and update record
            if (user.compare(userName) == 0)
            {
                flag = 1;
                user.update();
                fio.seekp(pos); // seek put pointer
                fio.write((char *)&user, sizeof(user));
                break;
            }
        }
    }
    fio.close();
    if (flag == 1) cout << "\nRecord modified successfully!";
    else cout << "\nUser record doesn't exist.";
}

// Display all records
void displayDetails(int count)
{
    int i = 0;
    Record user;
    fio.open("recordDirectory", ios::in | ios::binary);
    if (!fio)
    {
        cout << "\nCannot open file!"; return;
    }
    cout << endl;
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(6) << "SrNo" << setw(20) << "Name" << setw(13) << "Telephone" << endl;
    while (i < count)
    {
        fio.read((char *)&user, sizeof(user));
        cout << setw(6) << i + 1;
        user.display();
        ++i;
    }
    fio.close();
}

/* ------------------------------------------- MAIN FUNCTION */
int main()
{
    int choice, count, i;
    Record user;
    char userName[MAX];
    cout << "\n===================TELEPHONE DIRECTORY PROGRAM===================\n";
    // Read User records
    cout << "\nHow many records do you want to enter?\n";
    cin >> count;
    readRecords(count);

    // Search, Update, Display records
    system("cls");
    do
    {
        cout << "\n=====================";
        cout << "\nChoose from the following:- \n1. Search User data\n2. Update User data\n3. Display Users\n4. Exit\nEnter choice:";
        cin >> choice;
        switch (choice)
        {
            case 1: searchUser(count); break;
            case 2: updateUser(count); break;
            case 3: displayDetails(count); break;
            case 4: choice = 4; break;
            default: cout << "\nINVALID OPTION!";
        }
    } while (choice != 4);
    return 0;
}