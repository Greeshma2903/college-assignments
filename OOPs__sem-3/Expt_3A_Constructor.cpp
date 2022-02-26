// Write a C++ program to understand concept of parameterized constructors
// Write a C++ program to understand concept of copy constructors

#include <iostream>
using namespace std;

int count = 0;

class work
{
	int employeeTime;
public:
	work()	// default constructor
	{
		employeeTime = 9;
	}
	work(int t)	// parameterized constructor
	{
		employeeTime = t;
	}
	work(work &obj)	// copy constructor
	{
		employeeTime = obj.employeeTime;
	}
	void display()
	{
		++count;
		cout << "Employee " << count << " time: " << employeeTime << ":00" << endl;
	}
};

int main()
{
	work e1, e2(10);
	work e3(e2); // call copy constructor
	cout << "\nDefault work timings: \n";
	e1.display();
	cout << "\nEmployee 1 and 2 have the same work timings: \n";
	e2.display();
	e3.display();
	cout << endl << " -----------  \n";
	return 0;
}
