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
	void getDetails()
	{ // function to read student details
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
		cout << "--------------------------";
		calcPercentage();
	}

	// function to calculate percentage
	void calcPercentage();

	void putData(void)
	{ // function to display student details
		cout << "\n Roll: " << roll << endl;
		cout << " Name: " << name << endl;
		cout << " Marks --- \n";
		for (int i = 0; i < 5; i++)
		{
			cout << "\n\tSubject " << i + 1 << " : " << marks[i] << endl;
		}
		cout << "Percentage: " << percent << "%";
		cout << "--------------------------------\n";
	}
};

void student::calcPercentage()
{ // class method defined outside
	int i;
	float sum = 0;
	for (i = 0; i < 5; i++)
		sum += marks[i];
	percent = (sum / 150) * 100;
}

// MAIN FUNCTION ---
int main()
{
	student *s; // DMA pointer
	s = new student[2];

	int i;
	// Read student details
	cout << "\nENTER STUDENT DETAILS:--------\n";
	for (i = 0; i < 2; i++)
		s[i].getDetails();

	cout << "-----------------------------";
	// Display student details
	cout << "\nSTUDENT DETAILS ----------\n";
	for (i = 0; i < 2; i++)
		s[i].putData();

	delete[] s;
	return 0;
}
