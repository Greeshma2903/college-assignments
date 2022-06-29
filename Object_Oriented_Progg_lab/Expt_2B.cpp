//  Write a C++ program to understand concept of Inline and Friend functions
#include <iostream>
using namespace std;

// Demonstrating FRIEND functions
class var_2;

class var_1
{
    int first;

public:
    void input(int a)
    {
        first = a;
    }
    void printValue()
    {
        cout << "\n Value 1: " << first;
    }

    friend void exchangeValues(var_1 &, var_2 &); // declate friend function

    int returnValue()
    {
        return first;
    }
};

class var_2
{
    int second;

public:
    void input(int b)
    {
        second = b;
    }
    void printValue()
    {
        cout << "\n Value 2: " << second;
    }
    friend void exchangeValues(var_1 &, var_2 &); // declare friend function

    int returnValue()
    {
        return second;
    }
};

void exchangeValues(var_1 &x, var_2 &y)
{
    // exchange the values of data member of the classes
    int tmp = x.first;
    x.first = y.second;
    y.second = tmp;
}

// Demonstrating INLINE functions
inline void operations(int a, int b)
{
    cout << "\nProduct of " << a << " & " << b << ": " << a * b << endl;
    cout << "\nSum  " << a << " & " << b << ": " << a + b << endl;
}


// MAIN FUNCTION ---------------
int main()
{
    var_1 ob1;
    var_2 ob2;
    ob1.input(10);
    ob2.input(30);

    cout << "\n Values before exchanging: ";
    ob1.printValue();
    ob2.printValue();

    cout << "\n\n Values after exchanging: ";
    exchangeValues(ob1, ob2);
    ob1.printValue();
    ob2.printValue();

    cout << "\n-------------";
    int value_1 = ob1.returnValue();
    int value_2 = ob2.returnValue();

    // function call will be replaced by inline function definition
    operations(value_1, value_2);


    return 0;
}
