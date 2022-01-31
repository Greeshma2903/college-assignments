// Write a C++ program to implement standard library list sequence container
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << " " << v.at(i); 
    }
}
// MAIN FUNCTION
int main()
{
    vector<int> v; // integer vector created

    cout << "\n\nInitial size() = " << v.size();         // gives no of elements
    cout << "\n\nInitial capacity() = " << v.capacity(); 

    v.push_back(10); // pushing the element at back of vector
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "\n\nAfter push_back() size() = " << v.size();
    cout << "\n\nAfter push_back() capacity() = " << v.capacity();

    cout << "\n\nDisplay vector elements after push_back() :";
    display(v);

    cout << "\n\nFrist element of vector = " << v.front();
    cout << "\n\nLast element of vector = " << v.back();

    // Insert using iterator
    vector<int>::iterator itr = v.begin(); // here itr points to 0th element
    itr = itr + 3;                         // itr made to point 4th element;
    v.insert(itr, 35);
    cout << "\n\nDisplay vector elements after insertion :";
    display(v);

    // delete last element
    v.pop_back();
    cout << "\n\nDisplay vector elements after pop_back() :";
    display(v);

    // erase(delete) vector elements
    v.erase(v.begin() + 2, v.begin() + 4);
    cout << "\n\nDisplay vector elements after erase() :";
    display(v);

    // resizing vector
    v.resize(10);
    cout << "\n\nAfter resize() vector size = " << v.size();
    cout << "\n\nCapacity = " << v.capacity();

    // using clear function
    v.clear();
    cout << "\n\nAfter clear() function :";
    display(v);

    cout << "\n\nIs vector empty = " << v.empty();

    getch();
    return 0;
}
