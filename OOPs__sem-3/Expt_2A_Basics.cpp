// Write a C++ program to understand concept of reference variables in functions.

#include<iostream>
using namespace std;
void swap(int &a, int &b);
int main()
{
    int a, b;
    a = 10;
    b = 30;

    cout<<"Before swapping: --- \n\t";
    cout<<a<<" "<<b;
    swap(a, b);
    cout<<"\nAfter swapping: --- \n\t";
    cout<<a<<" "<<b;

    return 0;
}

void swap(int &t, int &w)
{
    int temp = t;
    t = w;
    w = temp;
}
