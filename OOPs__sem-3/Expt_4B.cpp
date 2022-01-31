/*
Write a C++ program to understand overloading of binary operators to perform the
following operations on the objects of the class:
i. x = 5 + y
ii. x = x * y where x & y are objects of the class
iii. x = y - 5
*/

#include <iostream>
using namespace std;

// CLASS
class test
{
    int val;

public:
    test();
    friend test operator+(int, test &);
    test operator*(test &);
    test operator-(int); //convert to mf
    int returnVal();
};

test::test() // default constructor
{
    val = 1;
}

test operator+(int ob1, test &ob2) // overload +
{
    test a;
    a.val = ob1 + ob2.val;
    return a;
}

test test::operator*(test &ob1) // overload *
{
    test a;
    a.val = ob1.val * val;
    return (a);
}

test test::operator-(int ob2) // overload -
{
    test b;
    b.val = val - ob2;
    return b;
}

int test::returnVal()
{
    return val;
}

// MAIN FUNCTION
int main()
{
    test x, y;
    cout << "\nInitial value of x and y: " << x.returnVal() << " & " << y.returnVal() << endl;
    x = 5 + y;
    cout << "\nx = 5 + y\n\tValue of x: " << x.returnVal() << endl;
    x = x * y;
    cout << "\nx = x * y\n\tValue of x: " << x.returnVal() << endl;
    x = y - 5;
    cout << "\nx = y - 5\n\tValue of x: " << x.returnVal() << endl;

    return 0;
}