#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id, arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime, responseTime;
};

int main()
{
    int complete, time, srtn, i, j, avwt, avtat;
    int n;

    // READ
    cout << "Enter no of processes : ";
    cin >> n;
    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        cout << "Enter burst time: ";
        cin >> p[i].burstTime;
        cout << "Enter arrival time: ";
        cin >> p[i].arrivalTime;
    }

    int remainingTime[n];
    // copy burst time into remaining arry
    for (i = 0; i < n; i++)
    {
        remainingTime[i] = p[i].burstTime;
    }

    vector<int> Time(100, -1); // for storing process order
    complete = 0;
    time = -1;
    while (complete != n)
    {
        time++; // for every time increment
        srtn = 0;
        for (i = 0; i < n; i++)
        {
            if (remainingTime[i] > 0 && p[i].arrivalTime <= time)
            {
                srtn = i;
                break;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (remainingTime[i] > 0 && remainingTime[i] < remainingTime[srtn] && p[i].arrivalTime <= time)
            {
                srtn = i;
            }
        }
        // decrement remaining time
        remainingTime[srtn] = remainingTime[srtn] - 1;
        // record
        Time[time] = p[srtn].id;

        // if remaining time of P is fullfilled, count CT, TAT, WT
        if (remainingTime[srtn] == 0)
        {
            complete++;
            p[srtn].completionTime = time + 1;
            p[srtn].turnAroundTime = p[srtn].completionTime - p[srtn].arrivalTime;
            p[srtn].waitingTime = p[srtn].turnAroundTime - p[srtn].burstTime;
        }
    }

    for (int i = 0; i < n; i++)
    {
        avwt += p[i].waitingTime;
        avtat += p[i].turnAroundTime;
    }
    avtat /= n;
    avwt /= n;

    cout << "\nProcess\tArrival time\tBurst time\tTurn aroundtime\tWaiting time" << endl;
    for (int i = 0; i < n; i++)
        cout << p[i].id << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].burstTime << "\t\t" << p[i].turnAroundTime << "\t\t\t" << p[i].waitingTime << endl;

    return 0;
}