// [B] Write a C++ program to study implementation of Hybrid form of Inheritance(Virtual Base Class)
#include <iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;

// STUDENT CLASS : BASE
class Student
{
protected:
    int roll;
    char name[50];

public:
    void get_roll_name();
    void print_roll_name();
};

void Student::get_roll_name()
{
    cout << "\nRoll No: ";
    cin >> roll;
    cin.ignore();
    cout << "Name: ";
    cin.getline(name, sizeof(name));
}

void Student::print_roll_name()
{
    cout << "\nRoll No: " << roll << "\nName: " << name;
}

// TEST 1 CLASS: DERIVED
class Test1 : virtual public Student
{
protected:
    float sub1, sub2, sub3;

public:
    Test1();
    void getTest1Data();
    void printTest1Data();
    float returnSum1();
};

Test1::Test1()
{
    sub1 = 0.0;
    sub2 = 0.0;
    sub3 = 0.0;
}

void Test1::getTest1Data()
{
    cout << "\nSubject 1, 2, 3: ";
    cin >> sub1 >> sub2 >> sub3;
}

void Test1::printTest1Data()
{
    cout << "\nTest 1 Marks (out of 100) --\n\tSub1\tSub2\tSub3\n\t" << sub1 << "\t" << sub2 << "\t" << sub3 << "\n";
}

float Test1::returnSum1()
{
    return (sub1 + sub2 + sub3);
}

// TEST 2 CLASS: DERIVED
class Test2 : virtual public Student
{
protected:
    float sub4, sub5, sub6;

public:
    Test2();
    void getTest2Data();
    void printTest2Data();
    float returnSum2();
};

Test2::Test2()
{
    sub4 = 0.0;
    sub5 = 0.0;
    sub6 = 0.0;
}

void Test2::getTest2Data()
{
    cout << "\nSubject 1, 2, 3: ";
    cin >> sub4 >> sub5 >> sub6;
}

void Test2::printTest2Data()
{
    cout << "\nTest 2 Marks (out of 100)--\nSub1\tSub2\tSUb3\n" << sub4 << "\t" << sub5 << "\t" << sub6 << "\n";
}

float Test2::returnSum2()
{
    return (sub4 + sub5 + sub6);
}

// RESULT CLASS: DERVIED CLASS
class Result : public Test1, public Test2
{
    float percentage;
    char classObtained[100];

public:
    Result();
    void printResult();
};

Result::Result()
{
    percentage = 0.0;
    strcpy(classObtained, "Fail");
}

void Result::printResult() 
{
    int avg;
    print_roll_name();
    printTest1Data();
    printTest2Data();
    percentage = (((returnSum1() + returnSum2())/ 2) / 300) * 100;
    if(percentage > 80 && percentage <= 100)
        strcpy(classObtained, "Distiction");
    else if(percentage > 60 && percentage <= 80)
        strcpy(classObtained, "First Class");
    else
        strcpy(classObtained, "Second Class");
    cout << "\nPercentage: "<< percentage;
    cout << "\nClass Obtained: " << classObtained << endl;
}
// MAIN FUCNTION ---------------------------------------------
int main()
{
    Result s;
    cout << "\nEnter Student Details: --->\n";
    s.get_roll_name();
    cout << "\nEnter Test 1 marks: \n";
    s.getTest1Data();
    cout << "\n------------\nEnter Test 2 marks: \n";
    s.getTest2Data();
    cout << "\nThe Student's Results ----------->\n";
    s.printResult();

    return 0;
}