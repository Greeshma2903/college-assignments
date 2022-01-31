#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
    float arr[4];
    int n = 4, i = 0;
    fstream fio;
    // Write to file
    cout << "Enter the elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> arr[i];
    fio.open("File.txt", ios::out);
    fio.write((char *)&arr, sizeof(arr));

    // read from file
    fio.open("File.txt", ios::in);
    fio.read((char *)&arr, sizeof(arr)); 
    cout << "The elements in the array arr are: \n=>";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    fio.close();
    return 0;
}