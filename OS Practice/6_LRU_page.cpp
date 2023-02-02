// use a time instacne to keep track of which frame was hit least recently
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int LRU(int time[], int f)
{
    int i, min, pos;
    min = time[0];
    pos = 0;
    // return minimum hit frame postition

    for (i = 1; i < f; i++)
    {
        if (min > time[i])
        {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int n, f, i, j, k;
    int counter = 0, faults = 0;

    // Accept no of frames and pages
    cout << "Enter number of Frames: ";
    cin >> f;
    cout << "Enter number of pages: ";
    cin >> n;

    int alloc[f], pages[n], time[f];
    for (i = 0; i < f; i++)
        alloc[i] = -1;

    int flag1 = 0, flag2 = 0;

    // for each page
    for (i = 0; i < n; i++)
    {
        // check if already present
        flag1 = flag2 = 0;
        for (j = 0; j < f; j++)
        {
            if (alloc[j] == pages[i])
            {
                flag1 = flag2 = 1;
                counter++;
                time[j] = counter;
                break;
            }
        }

        // check if any empty space, if so add page
        if (flag1 == 0)
        {
            for (j = 0; j < f; j++)
            {
                if (alloc[j] == -1)
                {
                    counter++;
                    faults++;
                    time[j] = counter;
                    alloc[j] = pages[i];
                    flag2 = 1; // to mark an empty space was filled
                    break;
                }
            }
        }

        // check LRU and replace
        if (flag2 == 0)
        {
            // replace using LRU;
            // get the LRU frame position
            int pos = LRU(time, f);
            counter++;
            faults++;
            time[pos] = counter;
            alloc[pos] = pages[i];
        }

        // print alloc
    }

    return 0;
}
