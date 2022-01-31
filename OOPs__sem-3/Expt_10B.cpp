/*
Write a C++ program to create a class template to represent a generic vector. Include the
member functions to perform the following tasks
1. Create the vector
2. To modify the value of a given element
3. To display the vector elements
*/

#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class vector
{
    T *v;
    int size;
public:
    void create();
    void modify()
    {
        int index, value;
        cout << "\n\nEnter the Index to be modified ( 0 -" << size - 1 << "):" ;
        cin >> index; 
        cout << "\nEnter Value: ";
        cin >> value;
        v[index] = value;
    }
    void display()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << v[i] << " ";
        }
    }
};

template<class T>
void vector<T>:: create()
{
        cout << "\nHow many vectors? ";
        cin >> size;
        v = new T[size];
            cout << "\nEnter Values: \n";
        for ( int i = 0; i < size; i++ )
        {
            cout << i + 1 <<  ": ";
            cin >> v[i];
        }
    }
// MAIN FUNCTION 
int main()
{
    vector<int> v1;
    v1.create();
    cout << "\n=> Vector: ";
    v1.display();
    v1.modify();
    cout << "\n=> Vector: ";
    v1.display();
    return 0;
}

// NOTE Declare member functions outside using template prefix