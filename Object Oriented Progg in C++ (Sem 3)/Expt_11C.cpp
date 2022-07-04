// Write a C++ program to understand string stream processing concept
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
using std::istringstream;

int main(){
    string str;
    cout << "Enter Employee ID and Salary: ";
    getline(cin, str);
    istringstream stream(str);
    int id;
    double salary;
    while(stream)
    {
        stream >> id;
        stream >> salary;
        if(stream)
            cout << "Stream successful" << endl;
        else
            cout << "Stream unsuccessful\nEnd of string" << endl;
    }
    cout << "\nEmployee ID: " << id << "\t Salary: " << salary << "\n";

    return 0;
}
