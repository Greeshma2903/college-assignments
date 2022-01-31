// Write a C++ program to insert 5 elements in first file and 3 elements in second file. Merge the contents of both files into third file into ascending order.
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
// sorting function
void sort(int *a, int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int i, n, m, n1, n2, temp[8];
    fstream fin1, fin2, fin3;
    fin1.open("file1.txt", ios::trunc | ios::out | ios::in);
    fin2.open("file2.txt", ios::trunc | ios::out | ios::in);
    fin3.open("file3.txt", ios::trunc | ios::out | ios::in);
    // read elements to file
    cout << "\nElements of File 1 --> \n";
    for (i = 0; i < 5; i++)
    {
        cout << "Enter element:";
        cin >> n;
        fin1 << n << "\n";
    }
    cout << "\nElements of File 2 --> \n";
    for (i = 0; i < 3; i++)
    {
        cout << "Enter element:";
        cin >> n;
        fin2 << n << "\n";
    }
    // move to beginning of file
    fin1.seekg(0, ios::beg);
    fin2.seekg(0, ios::beg);
    i = 0;
    while (i < 5)
    {
        fin1 >> n;
        temp[i] = n;
        ++i;
    }
    cout << endl;
    while (i < 8)
    {
        fin2 >> n;
        temp[i] = n;
        ++i;
    }

    cout << "\nUnsorted Array: \n";
    for (i = 0; i < 8; ++i)
    {
        cout << temp[i] << " ";
    }
    // sort in ascending order
    sort(temp, 8);
    // copy to third file
    for(i = 0; i < 8; i++)
    {
        fin3 << temp[i] << "\n";
    }
    fin3.seekg(0);
    // display 3rd file
    cout << "\nValues in File 3: \n";
    do
    {
        fin3 >> i;
        cout << i << " ";
    } while (!fin3.eof());

    fin1.close();
    fin2.close();
    fin3.close();   
    return 0;
}
