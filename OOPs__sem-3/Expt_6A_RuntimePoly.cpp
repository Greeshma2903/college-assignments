// [A] Write a C++ program to understand virtual functions in C++
#include <iostream>
using namespace std;

class Base
{
public:
    void show()
    {
        cout << "\nShow Base class";
    }
    virtual void display()
    {
        cout << "\nDisplay Base class";
    }
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "\nShow Derived Class";
    }
    void display()
    {
        cout << "\nDisplay Derived Class";
    }
};

int main()
{
    Base b;
    Derived d;
    Base *bptr;
    cout << "\nbptr points to Base Class";
    bptr = &b;
    bptr->display();    // calls base class version
    bptr->show();       // calls base class version

    cout << "\n\nbtpr points to Derived Class";
    bptr = &d;
    bptr->display();    // calls derived class version
    bptr->show();       // calls base class version
    return 0;
}
