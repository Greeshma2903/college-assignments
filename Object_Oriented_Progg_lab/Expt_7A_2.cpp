#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[] = "object";
    int i, j;
    int len = strlen(str);

    cout.fill('*');
    // upper-half
    for (i = 0; i < strlen(str); i++)
    {
        cout.setf(ios::left, ios::adjustfield);
        cout.write(str, len - i);

        cout.width(i * 2 + 1);
        cout.setf(ios::right, ios::adjustfield);
        for (j = len - i - 1; j >= 0; --j)
        {
            cout << str[j];
        }
        cout << endl;
    }
    // lower-half
    for (i = len - 2; i >= 0; i--)
    {
        cout.setf(ios::left, ios::adjustfield);
        cout.write(str, len - i);

        cout.width(i * 2 + 1);
        cout.setf(ios::right, ios::adjustfield);
        for (j = len - i - 1; j >= 0; --j)
        {
            cout << str[j];
        }
        cout << endl;
    }
    return 0;
}
