// Write a C++ program to implement exceptional handling concept (Divide by zero) using exception rethrow mechanism
#include <iostream>
using namespace std;

int divide(int a, int b)
{
    int x;
    try
    {
        if (b == 0)
            throw(b);   // first throw err
        else
        {
            cout << "=> Quotient (a/b) = " << a / b << "\n\n";
        }
    }
    catch (int value)   
    {
        cout << "=> Exception caught inside function, b = " << b << " (divide by zero)" << endl;
        throw;  // rethrow err
    }
    cout << "END of function" << endl;
}

int main()
{
    int a, b, x;
    cout << "DIVIDE TWO NUMBERS >>" << endl;
    cout << "Enter two numbers:";
    cin >> a >> b;
    try
    {   // function call
        divide(a, b);
    }
    catch (int value)
    {   // catch error again from function
        cout << "\n=> Exception caught inside main (divide by zero error)" << endl;
    }
    cout << "END of main" << endl;
    return 0;
}