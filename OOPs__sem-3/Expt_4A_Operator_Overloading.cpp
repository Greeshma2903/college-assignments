/*
Write a C++ program to understand overloading of unary prefix & postfix operators to
perform increment and decrement operations on objects.
*/

#include <iostream>
using namespace std;

class test
{
    int value;
public:
    test();
    test(int);
    void operator++();
    void operator++(int);
    void operator --();
    void operator --(int);
    int returnVal() { return value; }
};
test::test()
{
    value = 0;
}
test::test(int x)
{
    value = x;
}
// increment operators
void test::operator++()
{
    ++value;
}
void test::operator++(int)
{
    value++;
}
// decrement operators
void test::operator--()
{
    --value;
}
void test::operator--(int)
{
    value--;
}

// MAIN ---------------------------------------
int main()
{
    test t1(10);
    cout << "\nIncrementing:\n";
    cout << "Let T1: " << t1.returnVal() << endl;
    ++t1;
    cout << "++T1 " << t1.returnVal() << endl;
    t1++;
    cout << "T1++: " << t1.returnVal() << endl;
    test t2(20);
    cout << "\nDecrementing:";
    cout << "\nLet T2: " << t2.returnVal() << endl;
    --t2;
    cout << "--T2: " << t2.returnVal() << endl;
    t2--;
    cout << "T2--: "<< t2.returnVal() << endl;
    return 0;
}
