/*
Write a C++ program using class string to create two strings and perform the following
operations on the strings
i. To add two string type objects (s1 = s2 + s3) where s1,s2,s3 are objects
ii. To compare two string lengths to print which string is smaller & print accordingly.
*/

#include <iostream>
#include <string.h>
using namespace std;

class StringOp
{
    char *str;
    int len;

public:
    StringOp();
    StringOp(const char *s);
    StringOp operator+(StringOp &);
    int operator<=(StringOp &);
    void print();
};

StringOp::StringOp()
{
    len = 0;
    str = 0;
}

StringOp::StringOp(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
}

StringOp StringOp::operator+(StringOp &s2)
{
    StringOp s;
    s.len = len + s2.len;
    s.str = new char[s.len + 1];

    strcpy(s.str, str);
    strcat(s.str, s2.str);

    return s;
}

int StringOp::operator<=(StringOp &s2)
{
    if (len <= s2.len)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void StringOp::print()
{
    cout << str;
}

int main()
{
    StringOp s1("New"), s2(" Delhi"), s3;

    s3 = s1 + s2;

    cout << "\n String 1: ";
    s1.print();
    cout << "\n String 2: ";
    s2.print();
    cout << "\n String 3: ";
    s3.print();
    cout << endl
         << "---------\n";

    if (s1 <= s2)
    {
        s1.print();
        cout << " is smaller than ";
        s2.print();
    }
    else
    {
        s2.print();
        cout << " is smaller than ";
        s1.print();
    }

    return 0;
}