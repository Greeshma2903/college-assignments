// [B] Write a C++ program to understand pure virtual functions in C++
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
// Base class
class Media
{
protected:
    char title[50];
    float price;
    int SrNo;

public:
    virtual void display() = 0;
};
// Derived class 1
class Book : public Media
{
    int yr_pub;
    char pub_name[50];

public:
    void getBookData(int i);
    void display();
};

void Book::getBookData(int i)
{
    SrNo = i;
    cin.ignore();
    cout << "\nBook Title: ";
    cin.getline(title, sizeof(title));
    cout << "\nPublication name: ";
    cin.getline(pub_name, sizeof(pub_name));
    cout << "\nYear of Publication: ";
    cin >> yr_pub;
    cout << "\nBook price: ";
    cin >> price;
}

void Book::display()
{
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(6) << SrNo << setw(18) << title << setw(18) << pub_name << setw(6) << yr_pub << setw(6) << price << endl;
}
// Derived class 2
class Tape : public Media
{
    int tape_capacity;
    char manufac_name[50];

public:
    void getTapeData(int i);
    void display();
};

void Tape::getTapeData(int i)
{
    SrNo = i;
    cin.ignore();
    cout << "\nTape Title: ";
    cin.getline(title, sizeof(title));
    cout << "\nTape Capacity: ";
    cin >> tape_capacity;
    cin.ignore();
    cout << "\nManufacturer Name: ";
    cin.getline(manufac_name, sizeof(manufac_name));
    cout << "\nPrice: ";
    cin >> price;
}

void Tape::display()
{
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(6) << SrNo << setw(18) << title << setw(18) << tape_capacity << setw(18) << manufac_name << setw(6) << price << endl;
}
// MAIN FUNCTION ----------------------------------
int main()
{
    int book_num, i, tape_num;

    // read details
    cout << "\nHow many book details do you want to record?";
    cin >> book_num;
    Book b[book_num];
    cout << "\nENTER BOOK RECORDS:- \n";
    for (i = 0; i < book_num; ++i)
    {
        cout << "\nBook " << i + 1 << ":\n ";
        b[i].getBookData(i + 1);
        cout << "\n----------------";
    }

    cout << "\nHow many Tape details do you want to record?";
    cin >> tape_num;
    Tape t[tape_num];
    cout << "\nENTER TAPE RECORDS:-";
    for (i = 0; i < tape_num; ++i)
    {
        cout << "\nTape " << i + 1 << ":\n ";
        t[i].getTapeData(i + 1);
        cout << "\n----------------";
    }
    Media *m; // base pointer
    // display details
    cout.setf(ios::left, ios::adjustfield);
    cout << "\nBOOK RECORDS: -------------------->\n";
    cout << setw(6) << "SrNo" << setw(18) << "Book Title" << setw(18) << "Publication Name" << setw(6) << "YoP" << setw(6) << "Price" << endl;
    cout << "---------------------------------------------------------------------\n";
    for (i = 0; i < book_num; ++i)
    {
        m = &b[i];
        m->display();
    }
    cout << "\n\nTAPE RECORDS: ------------------->\n";
    cout << setw(6) << "SrNo" << setw(18) << "Tape Title" << setw(18) << "Tape Capacity" << setw(18) << "Manufacturer Name" << setw(6) << "Price" << endl;
    cout << "--------------------------------------------------------------------\n";
    for (i = 0; i < tape_num; ++i)
    {
        m = &t[i];
        m->display();
    }
    return 0;
}
