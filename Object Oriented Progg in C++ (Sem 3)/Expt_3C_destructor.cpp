// Destructor program

#include <iostream>
using namespace std;

int count = 0;

class test
{
    int value;
public:
    test()
    { // default constructor
        value = 0;
        ++count;
        cout << "\nObject " << count << " created -->" << endl;
    }
    test(int a)
    { // parameterized constructor
        value = a;
        ++count;
        cout << "\nObject " << count << " created -->" << endl;
    }
    ~test()
    { // destructor
        cout << "\n--> Object " << count << " destroyed" << endl;
        --count;
    }
};

int main()
{
    test t1, t2;
    {
        test t4;
        {
            test t5;
        }
        test t6, t7;
    }

    return 0;
}