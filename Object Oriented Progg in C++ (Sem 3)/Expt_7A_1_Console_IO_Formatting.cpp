// Write a C++ program to print the following output using ios class member functions(figexpt4A)
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
    int i;
    cout.fill('*');
    cout.width(15);
    cout.setf(ios::left, ios::adjustfield);
    cout << "VALUE";

    cout.width(15);
    cout.setf(ios::right, ios::adjustfield);
    cout << "DIVISION 1/SQRT";

    cout << endl;
    cout.setf(ios::showpoint);

    for (i = 1; i <= 5; ++i)
    {
        cout.width(5);
        cout.setf(ios::showpos);
        cout.setf(ios::internal, ios::adjustfield);
        cout.fill('.');
        if (i == 4)
            cout.fill('<');
        else if(i == 5)
            cout.fill('>');
        cout << i;

        cout.unsetf(ios::showpos);
        cout.width(16);
        cout.setf(ios::right, ios::adjustfield);
        cout.precision(5);
        cout.fill('*');
        if (i == 4)
            cout.fill('>');
        else if(i == 5)
            cout.fill('<');
        cout << sqrt(i) << endl;
    }

    return 0;
}