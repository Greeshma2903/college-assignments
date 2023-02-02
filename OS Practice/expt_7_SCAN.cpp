#include <iostream>
#include <iomanip>
using namespace std;
int total_head_movement = 0, nl, current_head;
int location[30];

void sort()
{
    int temp;
    for (int i = 1; i < nl; i++)
    {
        temp = location[i];
        int j;
        for (j = i - 1; j >= 0 && temp < location[j]; j--)
            location[j + 1] = location[j];
        location[j + 1] = temp;
    }
}
void display(int block, int ch, int dir)
{
    int n = nl + 3;
    int dummy[n], k = 0, i = 0, start;
    dummy[0] = 0, dummy[n - 1] = block - 1;
    for (i = 1; i < n; i++)
    {
        if (location[k] < current_head)
            dummy[i] = location[k++];
        else
        {
            dummy[i] = current_head;
            start = i;
            i++;
            break;
        }
    }
    for (; i < n - 1; i++)
        dummy[i] = location[k++];
    cout << endl
         << "SCAN Schedule:" << endl;
    for (int i = 0; i < n; i++)
        cout << setw(4) << dummy[i];
    cout << endl;
    if (dir == 1)
    {
        for (int j = start; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == j)
                    cout << setw(4) << "-";
                else
                    cout << setw(4) << " ";
            }
            cout << endl;
        }
        for (int j = start - 1; j > 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == j)
                    cout << setw(4) << "-";
                else
                    cout << setw(4) << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int j = start; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == j)
                    cout << setw(4) << "-";
                else
                    cout << setw(4) << " ";
            }
            cout << endl;
        }
        for (int j = start + 1; j < n - 1; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == j)
                    cout << setw(4) << "-";
                else
                    cout << setw(4) << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
    int block, direction;
    cout << "Enter the Block Size of the Disk: ";
    cin >> block;
    cout << "Enter the number of Disk Locations To be Searched: ";
    cin >> nl;
    cout << "Enter the Disk Locations to be Searched : ";
    for (int i = 0; i < nl; i++)
        scanf("%d", &location[i]);
    sort();
    cout << "Enter the Current Disk Head Position: ";
    cin >> current_head;
    cout << "Enter Direction [Left - 0; Right - 1]: ";
    cin >> direction;
    if (direction == 0)
    {
        total_head_movement += current_head;
        total_head_movement += location[nl - 1];
    }
    else
    {
        total_head_movement += block - current_head - 1;
        total_head_movement += block - location[0] - 1;
    }
    display(block, current_head, direction);
    cout << endl
         << "The Total Disk Head Movement is: " << total_head_movement;
}
