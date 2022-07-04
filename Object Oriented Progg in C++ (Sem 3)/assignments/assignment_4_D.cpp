#include <iostream>
using namespace std;
class meters;

class centimeter
{
    float num;

public:
    centimeter()
    {
        num = 0;
    }
    void getdata()
    {
        cin >> num;
    }
    float returnValue()
    {
        return num;
    }
};

class meters
{
    float mVal;

public:
    meters()
    {
        mVal = 0.0;
    }
    meters(centimeter c)
    {   // class-to-class conversion
        mVal = c.returnValue() / 100;
    }
    void display()
    {
        cout << "\nAfter conversion the number is: " << mVal << " m";
    }
};
// MAIN FUNCTION
int main()
{
    centimeter c;
    meters m;
    cout << "\nEnter a number in centimeter: ";
    c.getdata();
    // convert cm to m
    m = c;
    m.display();
    return 0;
}