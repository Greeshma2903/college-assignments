// Write a C++ program to implement standard library queue adapter class template
#include <iostream>
#include <conio.h>
#include <queue>
using namespace std;
int main()
{
    queue<char> q; // initial empty queue

    // push elements onto queue
    q.push('a'); 
    q.push('b');
    q.push('c');

    cout << "\n\nPopping elements from queue : ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    getch();
    return 0;
}