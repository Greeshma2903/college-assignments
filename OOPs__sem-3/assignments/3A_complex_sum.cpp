/*
Write a C++ program to declare a complex number class with its real and imaginary data
members. Provide a friend function sum() to add the two complex type objects and store the
result in the third complex type object. Accordingly display the result. Pass the arguments as
reference variables and also collect the result as object. Declare and define the appropriate
member functions required.
*/

#include <iostream>
using namespace std;

class complex
{
    int real, img;
public:
    void read(int r, int i)
    {
        real = r;
        img = i;
    }
    // friend function
    friend complex sum(complex &x, complex &y);

    void display()
    {
        cout << real << " + i" << img << endl;
    }
};

// friend function definition
complex sum(complex &x, complex &y)
{
    complex z;
    z.real = x.real + y.real;
    z.img = x.img + y.img;
    return z;
}

int main()
{
    complex c1, c2, c3;
    int real, imag;
    cout << "\nEnter real and imaginary part of 1st complex number:";
    cout << "\nReal:";
    cin >> real;
    cout << "Imag:";
    cin >> imag;
    c1.read(real, imag);

    cout << "\nEnter real and imaginary part of 2nd complex number:";
    cout << "\nReal:";
    cin >> real;
    cout << "Imag:";
    cin >> imag;
    c2.read(real, imag);

    cout << "\nComplex number 1:\t";
    c1.display();
    cout << "\nComplex number 2:\t";
    c2.display();
    cout << "\n------------------------------";
    c3 = sum(c1, c2);  
    cout << "\nThe SUM of complex numbers:\t ";
    c3.display();
    return 0;
}