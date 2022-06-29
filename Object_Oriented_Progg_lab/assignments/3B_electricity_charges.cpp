/*
    An electricity board charges the following rates to domestic user to discourage large consumption of energy
    first 100 units: 60P per unit
    next 200 units: 80P per unit
    Beyond 300 units: 90P per unit

    All users are charged a min of RS.50. If the total amount is more than 300 then an additional surcharge of 15% is addded.
    Write a program to read the names of the users and num of units consumed and print out the charges with names.
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include<iomanip>
#define MAX 50

using namespace std;

class ElectricityBill
{
    float units, amount;
    char name[MAX];
public:
    void read();
    void calcBill();
    void displayBill();
};

void ElectricityBill::read()
{
    cout << "\nName: ";
    getchar();
    cin.getline(name, sizeof(name));
    cout << "Units consumed: ";
    cin >> units;
}

void ElectricityBill::calcBill()
{
    float unitsConsumed = units;
    // set minimum amount
    amount = 50;

    if (unitsConsumed >= 100 && unitsConsumed < 200)
    {
        amount += (0.6 * 100);
    }
    else if (unitsConsumed >= 200 && unitsConsumed < 300)
    {
        unitsConsumed -= 100;
        amount += 0.6 * (100);
        amount += 0.8 * (unitsConsumed);
    }
    else if (unitsConsumed >= 300)
    {
        unitsConsumed -= 300;
        amount += (0.6 * 100);
        amount += 0.8 * 200;
        amount += 0.9 * unitsConsumed;
    }
    // if amount greater than 300, apply surcharge
    if (amount >= 300)
    {
        amount += 0.15 * amount;
    }
}

void ElectricityBill::displayBill()
{
    cout << "\nName: " << name;
    cout << "\nUnits Consumed: " << units;
    cout << "\nTotal amount : Rs." << setprecision(4) << amount;
    cout << "\n--------------------------\n";
}

// MAIN FUNCTION
int main()
{
    ElectricityBill users[MAX];
    int num, i;
    float units;
    char name[MAX];

    cout << "\nEnter number of users: ";
    cin >> num;

    for (i = 0; i < num; i++)
    {
        cout << "\nUSER " << (i + 1) << ":----";
        users[i].read();
    }

    cout << "\nTHE BILL FOR RESPECTIVE USERS: -------";
    for (i = 0; i < num; ++i)
    {
        users[i].calcBill();
        users[i].displayBill();
    }
    return 0;
}