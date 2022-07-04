/*
Write a C++ program to create a student’s database application using “files”. Create a
unique file for each student depending upon the student name entered. Store the student
data like name, roll no, address, and branch into the file. Allow the user to search and
update all the student details depending upon the entered name and display the details
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

fstream fio;
/* ----------------------------------------- CLASS DEFINITION */
class Student
{
    int roll;
    char name[MAX_NAME_LENGTH], branch[MAX_NAME_LENGTH], address[MAX_ADDRESS_LENGTH];

public:
    void read();
    void display();
    void update();
    char *returnName() { return name; }
};

void Student::read()
{
    cin.ignore();
    cout << "\nName :";
    cin.getline(name, MAX_NAME_LENGTH);
    cout << "Roll No: ";
    cin >> roll;
    cin.ignore();
    cout << "Branch: ";
    cin.getline(branch, MAX_NAME_LENGTH);
    cout << "Address: ";
    cin.getline(address, MAX_ADDRESS_LENGTH);
}

void Student::display()
{
    cout << "\nName: " << name;
    cout << "\nRoll No: " << roll;
    cout << "\nBranch :" << branch;
    cout << "\nAddress :" << address;
    cout << "\n--------------------------------\n";
}

void Student::update()
{
    cout << "Update information:-\n";
    cout << "\nRoll No: ";
    cin >> roll;
    cin.ignore();
    cout << "\nBranch: ";
    cin.getline(branch, MAX_NAME_LENGTH);
    cout << "\nAddress: ";
    cin.getline(address, MAX_ADDRESS_LENGTH);
}
/* ------------------------------------------ CLASS DEF-END */

/* ------------------------------------------ FUNCTIONS */
void searchStudentRecord(Student *s, int num)
{
    int i;
    char studentName[MAX_NAME_LENGTH];
    cin.ignore();
    cout << "\nStudent Name to be searched: ";
    cin.getline(studentName, MAX_NAME_LENGTH);
    for (i = 0; i < num; ++i)
    {
        if (strcmp(studentName, s[i].returnName()) == 0)
        {
            fio.open(studentName, ios::binary | ios::in);
            fio.read((char *)&s[i], sizeof(Student));
            s[i].display();
            fio.close();
            return;
        }
    }
    cout << "\nStudent record doesn't exist.";
    fio.close();
}

void updateStudentRecord(Student s[], int count)
{
    int i;
    char studentName[MAX_NAME_LENGTH];
    cin.ignore();
    cout << "\nStudent Name to be updated: ";
    cin.getline(studentName, MAX_NAME_LENGTH);
    for (i = 0; i < count; ++i)
    {
        if (strcmp(studentName, s[i].returnName()) == 0)
        {
            fio.open(studentName, ios::in | ios::out | ios::binary);
            fio.read((char *)&s[i], sizeof(Student));
            s[i].update();
            fio.seekp(0);
            fio.write((char *)&s[i], sizeof(Student));
            fio.close();
            cout << "\nRecord updated!";
            return;
        }
    }
    cout << "\nStudent record doesn't exist.";
}

void displayRecords(Student s[], int count)
{
    Student record;
    int i = 0;
    do
    {
        fio.open(s[i].returnName(), ios::binary | ios::in);
        fio.read((char *)&s[i], sizeof(Student));
        s[i].display();
        fio.close();
        ++i;
    } while (i < count);
}

/* -------------------------------------------- MAIN FUNCTION */
int main()
{
    int numRecords, choice, i;
    char studentName[MAX_NAME_LENGTH];

    cout << "\n=============== STUDENT DATABASE SYSTEM ============";
    cout << "\nHow many records to be created?";
    cin >> numRecords;
    Student record[numRecords];
    for (i = 0; i < numRecords; ++i)
    {
        record[i].read();
        strcpy(studentName, record[i].returnName());
        fio.open(studentName, ios::binary | ios::out | ios::trunc);
        fio.write((char *)&record[i], sizeof(record[i]));
        cout << "\n -------------------";
        fio.close();
    }

    system("cls");

    do
    {
        cout << "\n=====================";
        cout << "\nChoose from the following: \n1. Search Student\n2. Update Student Record\n3. Display all records\n4. Exit\nEnter Choice:";
        cin >> choice;
        cout << "\n=====================";
        switch (choice)
        {
        case 1:
            searchStudentRecord(record, numRecords);
            break;
        case 2:
            updateStudentRecord(record, numRecords);
            break;
        case 3:
            displayRecords(record, numRecords);
            break;
        case 4:
            choice = 4;
            break;
        default:
            cout << "\nINVALID OPTION!";
        }
    } while (choice != 4);

    return 0;
}