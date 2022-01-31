#include <iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main()
{
    fstream f1;
    f1.open("test", ios::out);
    f1<<"helloworld";
    f1.close();
    f1.open("test", ios::app);
    cout << f1.tellp();
	f1.close();
    return 0;
}
