/*
Write a C++ program to overload binary stream insertion (<<) & extraction (>>)
operators when used with objects.
*/

#include <iostream>
using namespace std;

// CLASS
class vector
{
    float mark;

public:
    vector()
    {
        mark = 0.0;
    }
    friend istream &operator>>(istream &, vector &);
    friend ostream &operator<<(ostream &, vector &);
    void calcAverage(vector &, vector &);
};

// Overload >>
istream &operator>>(istream &din, vector &ob)
{
    din >> ob.mark;
    return din;
}

// Oveload <<
ostream &operator<<(ostream &out, vector &ob)
{
    out << ob.mark;
}

void vector::calcAverage(vector &ob1, vector &ob2)
{
    mark = (ob1.mark + ob2.mark) / 2;
}

//  MAIN FUNCTION
int main()
{
    vector m, n, total;
    cout << "\nEnter IT 1 marks: ";
    cin >> m;
    cout << "\nEnter IT 2 marks: ";
    cin >> n;

    total.calcAverage(m, n);

    cout << "\n=> Average marks of both IT's: " << total;
}