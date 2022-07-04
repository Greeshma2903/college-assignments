// Program to read and display student details using classes
#include <iostream>
#include <string.h>

using namespace std;

class student
{
	int roll;
	char name[30];
	float percent, marks[5];

public:
	void calcPercentage();
	void getDetails()
	{
		int i;
			cout << "\nRoll:";
			cin >> roll;
			cout << "Name:";
			cin >> name;
			cout << "Marks (max 30): --------\n";
			for (i = 0; i < 5; i++)
			{
				cout << "\tSubject " << i + 1 << ":";
				cin >> marks[i];
			}
			cout << "\n--------------------------";
			calcPercentage();
	}


	void putData(void)
	{
		cout << "\n Roll: " << roll << endl;
		cout << " Name: " << name << endl;
		cout << " Marks --- \n";
		for (int i = 0; i < 5; i++)
		{
			cout << "\n\tSubject " << i + 1 << " : "<<marks[i]<<endl;
		}
		cout << "Percentage: " << percent << "%";
		cout<<"\n--------------------------------\n";
	}
};

void student::calcPercentage() {	// class method defined outside
	int i;
	float sum = 0;
		for (i = 0; i < 5; i++)
			sum += marks[i];
		percent = (sum * 100)/150;
}

// MAIN FUNCTION ---
int main()
{
	student s[10];
	int i, n;

	cout<< "\nEnter the number of students (max 10):";
	cin>> n;

	cout << "\nENTER STUDENT DETAILS:--------\n";
	for (i = 0; i < n; i++)
	{
		s[i].getDetails();
	}
	
	cout << "-----------------------------";

	cout << "\nSTUDENT DETAILS ----------\n";
	for ( i = 0; i < n; i++)
	{
		s[i].putData();
	}
	

	return 0;
}
