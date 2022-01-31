#include <iostream>
#include <cstring>
using namespace std;
class String
{
    int len;
    char *arr;

public:
    String()
    {
        len = 0;
        arr = new char[len];
        strcpy(arr, "\0");
    }
    String(char *a)
    {
        len = strlen(a);
        arr = new char[len];
        strcpy(arr, a);
    }
    friend void operator<<(ostream &x, String &y)
    {
        x << y.arr;
    }
    friend void operator>>(istream &x, String &y)
    {
        x >> y.arr;
    }
    String operator+(String &x)
    {
        String s;
        s.len = len + x.len;
        strcpy(s.arr, arr);
        strcat(s.arr, " ");
        strcat(s.arr, x.arr);
        return s;
    }
};

int main()
{
    // a. Create uninitialized string objects
    String s1, s2, s3;

    // b. Create objects with string constants
    String s4("Good Morning");

    cout << "String 4 is initialized to ";
    cout << s4;
    cout << "\n\nEnter two strings:";
    cin >> s1;
    cin >> s2;

    // c. Concatenates two strings properly
    cout << "The concatenated string s3 is \n=> ";
    s3 = s1 + s2;

    // d. Display a desired string object
    cout << s3;
    cout << endl;
    return 0;
}