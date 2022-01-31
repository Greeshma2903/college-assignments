/*
Create two classes DM and DB which store the value of distances. DM stores distances in meters and centimeters and DB in feet and inches. WAP that can read values for the class objects and add one object of DM with another object of DB. 

Use a friend function to carry out the addition operation. The object that stores the results may ba a DM object or DB object, depending on the units in which the results are required. 

The display shd be in the format of feet and inches or meters and centimeters depending on the object on the display.
*/

#include <iostream>
#include <math.h>
using namespace std;

// forward declaration
class DB;

// Class DM
class DM
{
    float meters, centi_ms;

public:
    DM();
    void read();
    void display();
    friend class DB; // friend class declaration
    void addDistance(DM &, DB &);
};

DM::DM()
{
    meters = 0.0;
    centi_ms = 0.0;
}

void DM::read()
{
    cout << "Enter distance (in centimeters): ";
    cin >> centi_ms;
    meters = centi_ms / 100;
}

void DM::display()
{
    cout << "Meters\t\tOR\tCentimeters" << endl;
    cout << meters << "\t\t\t" << centi_ms;
}

// Class DB
class DB
{
    float feet, inches;

public:
    DB();
    void read();
    void display();
    void addDistance(DM &, DB &);

    friend class DM;
};

DB::DB()
{
    feet = 0.0;
    inches = 0.0;
}

void DB::read()
{
    cout << "Enter distance (in inches): ";
    cin >> inches;
    feet = inches / 12;
}

void DB ::display()
{
    cout << "Inches\t\tOR\tFeet" << endl;
    cout << inches << "\t\t\t" << feet;
}

// of class DB
void DB::addDistance(DM &dis_mt, DB &dis_imper)
{ // friendly function
    feet = dis_mt.meters * 3.2808 + dis_imper.feet;
    inches = dis_mt.centi_ms * 0.3937008 + dis_imper.inches;
}

// of class DM
void DM::addDistance(DM &dist_1, DB &dist_2)
{ // friendly function
    meters = dist_1.meters + dist_2.feet * 0.3048;
    centi_ms = dist_1.centi_ms + dist_2.inches * 2.54;
}

// --------------
// MAIN FUNCTION
int main()
{
    DB height_f, total_distance_imper;
    DM height_m, total_distance_metric;
    int option;

    cout << "\nMetric System --- \n";
    height_m.read();
    cout << "\nImperial System --- \n";
    height_f.read();
    cout << "\n----------------------------------\n";

    cout << "\nTHE SUM OF ABOVE DISTANCES IN :\n";
    cout << "\n1. Metric System\n---" << endl;
    total_distance_metric.addDistance(height_m, height_f);  // take sum
    total_distance_metric.display();

    cout << "\n\n\n2. Imperial System\n---" << endl;
    total_distance_imper.addDistance(height_m, height_f);   // take sum
    total_distance_imper.display();

    return 0;
}
