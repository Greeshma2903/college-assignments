// Write a C++ program to implement standard library deque sequence container
#include<iostream>
#include<conio.h>
#include<deque>
using namespace std;

void display(deque <char> & d1)
{
	for(int i=0;i<d1.size();i++)
	{
		cout<<" "<<d1[i];
	}
}

int main()
{
	deque <char> d;

	//insert elements in d
	d.push_front('c');
	d.push_front('a'); 
	d.push_back('e');

	cout<<"\n\nDeque elements after insertion are as follows :";
	display(d);

	// remove front element
	d.pop_front();

	cout<<"\n\nDeque elements after pop_front() are as follows :";
	display(d);

	// modify elements
	d[1]='d';	// 'e' gets overwritten by 'd'

	cout<<"\n\nDeque elements after subscript insertion using [] are as follows :";
	display(d);

	getch();
	return 0;
}
