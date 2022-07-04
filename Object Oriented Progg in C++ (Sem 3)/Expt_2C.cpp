// Write a C++ program to understand concept of function overloading

#include <iostream>
using namespace std;
void volume(int len)
{
	cout<<"\n=> The volume of cube is:" << len * len * len << endl;
}
void volume(int rad, int ht)
{
	cout<< "\n=> The volume of cylinder is:" << 3.14 * rad * rad * ht << endl;
}
void volume(int l, int b, int h)
{
	cout<< "\n=> The volume of cuboid is: " << l * b * h << endl;
}
int main()
{
    int option;
    int len, bdth, ht, rad;
    do
    {
    	cout<< "\nCalculate the volume of:\n";
    	cout << "1.Cube \n2. Cuboid \n3. Cylinder \n4. Exit";
    	cout << "\nEnter option:";
        cin >> option;
        switch (option)
        {
        case 1:
			 cout<< "\nEnter the side length of cube:";
            cin >> len;
            volume(len);
            break;
        case 2:
 	  		 cout << "\nEnter length, breadth, height of cuboid:";
            cin >> len >> bdth >> ht;
            volume(len, bdth, ht);
            break;
        case 3:
            cout << "\nEnter radius and height of cylinder:";
            cin >> rad >> ht;
            volume(rad, ht);
            break;
        case 4:
            option = 4; 
            break;
        default:
            cout << "INVALID OPTION!!\n";
            break;
        }

    } while (option != 4);
    return 0;
}
