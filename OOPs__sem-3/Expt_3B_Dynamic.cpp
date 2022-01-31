#include <iostream>
#include <string.h>
using namespace std;
class test
{
    int len;
    char *name;

public:
    test()  // default constructor
    {
        len = 0;
        name = new char[len + 1]; // +1 for \0 (escape sequence)
    }
    test(const char *p)   // Dynamic constructor
    {
        len = strlen(p);
        name = new char[len + 1];
        strcpy(name, p);
    }
    void join(test &x, test &y)
    {
        len = x.len + y.len;
        delete name;
        name = new char[len + 1];
        strcpy(name, x.name);
        strcat(name, y.name);
    }
    void display()
    {
        cout << name << " \n";
    }
};

int main()
{
    test t1("Medam"), t2(" Greeshma"), t3;
    t1.display();
    t2.display();
    // concat the strings
    t3.join(t1, t2);
    cout << "After Conctenation => ";
    t3.display();
        return 0;
}
