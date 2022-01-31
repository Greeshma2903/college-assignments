//  Write a C++ program to implement a multi catch exception handling mechanism
#include <iostream>
using namespace std;

void test(int x)
{
    try
    {
        if (x == 1)
            throw 1;    // throw int
        else if (x == 0)    
            throw 'x';  // throw char
        else
            throw 1.1;  // throw double
    }
    catch (int) // int
    {
        cout << "\nCaught Interger value";
    }
    catch (char) // char
    {
        cout << "\nCaught a Character";
    }
    catch (double) // float
    {
        cout << "\nCaught Double value";
    }
    cout << "\nEnd of try-catch block\n";
}

int main()
{
    int x;
    cout << "\nx = 1";
    test(1);
    cout << "\nx = 0";
    test(0);
    cout << "\nx = -1";
    test(-1);

    return 0;
}