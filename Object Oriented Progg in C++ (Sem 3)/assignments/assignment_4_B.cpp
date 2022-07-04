#include<iostream>
using namespace std;

template<class T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

void swapFunction(float m, float n, char o, char p)
{
    cout << "\nFloat Values";
    cout << "\nBefore swap: " << m << " & " << n;
    swap(m, n);
    cout << "\nAfter swap: " << m << " & " << n;

    cout << "\n\nCharacter Values:";
    cout << "\nBefore swap: " << o << " & " << p;
    swap(o, p);
    cout << "\nAfter swap: " << o << " & " << p;
}

int main()
{
    swapFunction(1.1, 5.1, 'a', 'b');

    return 0;
}