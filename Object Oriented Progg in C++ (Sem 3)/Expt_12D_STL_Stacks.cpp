// Write a C++ program to implement standard library stack adapter class
#include<iostream>
#include<conio.h>
#include<vector>
#include<list>
#include<deque>
#include<stack>
using namespace std;

//Function for pushing elements 
template<class T>
void push(T & s)
{
	for(int i=0;i<10;i++)
	{
		s.push(i);
		cout<<s.top()<<" ";
	}
}
//Function for popping 
template<class T>
void pop(T & s)
{
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
// MAIN FUNCTION
int main()
{
	stack <int> dequestack;	
	stack <int,vector<int> > vectorstack;
	stack <int,list<int> > liststack;  

	cout<<"\n\npushing elements onto dequestack : ";
	push(dequestack);
	cout<<"\n\npushing elements onto vectorstack : ";
	push(vectorstack);
	cout<<"\n\npushing elements onto liststack : ";
	push(liststack);

	cout<<"\n\n------------------------------------------------";

	cout<<"\n\npopping element from dequestack : ";
	pop(dequestack);
	cout<<"\n\npopping element from vectorstack : ";
	pop(vectorstack);
	cout<<"\n\npopping element from liststack : ";
	pop(liststack);

	getch();
	return 0;
}

