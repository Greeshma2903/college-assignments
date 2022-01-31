// Intro to classes and objects in C++

#include<iostream>
using namespace std;

class item {
//	if no label specified, members are private
	// Data Members
	int number;
	float cost;
	
	public:
		// Member Functions		
		void getData(int a, float b);
		void putData(void)
		{
			cout<<"number: "<<number<<endl;
			cout<<"cost: "<<cost<<endl;
		}
};

// Defining member functions outside of class		
void item::getData(int a, float b)
{
	number = a;
	cost = b;
}


int main()
{
	item x;
	cout<<"Object x: \n";
	
	// access object properties using dot opertor on Object
	x.getData(100, 300.99);
	x.putData();
	
	item y;
	cout<<"\nObject y:\n";
	y.getData(200, 433.22);
	y.putData();
	
	return 0;
}


// defining method outside the class 
   			// 	return_type class_name::function_name(parameters){...}
