/*
Write a C++ program to create a vector of ‘n’ elements (allocate the memory
dynamically) and then multiply a scalar value with each element of a vector. Also show
the result of addition of two vectors.
*/

#include <iostream>
using namespace std;

class vector
{
    int *v, len;

public:
    vector();
    vector(int);
    void read();
    vector operator+(vector &);
    vector operator*(int scalar);
    void print();
};

vector::vector()
{
    v = NULL;
    len = 0;
}

vector::vector(int num)
{
    len = num;
    v = new int[len];
}

void vector::read()
{
    for (int i = 0; i < len; i++)
    {
        cin >> *(v + i);
    }
}

void vector::print()
{
    for (int i = 0; i < len; i++)
    {
        cout << *(v + i) << " ";
    }
}
// Overload *
vector vector:: operator*(int scalar)
{
    vector temp;
    temp.len = len;
    temp.v = new int[temp.len];

    for (int i = 0; i < len; i++)
    {
        temp.v[i] = v[i] * scalar;
    }
    return temp;
}
// Overload +
vector vector:: operator+(vector &ob2)
{
    vector temp;
    temp.len = len;
    temp.v = new int[temp.len + 1];
    for (int i = 0; i < temp.len; i++)
    {
        temp.v[i] = v[i] + ob2.v[i];
    }
    return temp;
}
// MAIN FUNCTION
int main()
{
    int num, k;
    cout << "\nHow many Vectors want to create?";
    cin >> num;

    vector v1(num), v2;

    cout << "\nEnter Elements: ";
    v1.read();
    cout << "\n-----\nThe Original Vector array: \n";
    v1.print();

    cout << "\nEnter the scalar you want to multiply: ";
    cin >> k;

    v2 = v1 * k;

    cout << "\nThe new Vectors after multipling are:\n";
    v2.print();

    vector v3 = v1 + v2;
    cout << "\n\nThe sum of both vector arrays: \n";
    v3.print();

    return 0;
}

