#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id, arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime, responseTime, priority;
};

int main()
{
    int complete, time, i, j, idx, n;
    cout << "Enter num process:";
    cin >> n;

    struct process p[n];

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        cout << "Enter burst time: ";
        cin >> p[i].burstTime;
        cout << "Enter arrival time: ";
        cin >> p[i].arrivalTime;
        cout << "Enter priority:";
        cin >> p[i].priority;
    }

    int remainingTime[n];
    for (i = 0; i < n; i++)
    {
        remainingTime[i] = p[i].burstTime;
    }
    vector<int> Time(100, -1);
    complete = 0;
    time = -1;

    while (complete != n)
    {
        time++;
        // ** set random high priority
        idx = n;
        p[idx].priority = 999;

        for (i = 0; i < n; i++)
        {
            if (remainingTime[i] > 0 && p[i].arrivalTime <= time && p[i].priority < p[idx].priority)
            {
                idx = i;
            }
            if (remainingTime[i] > 0 && p[i].arrivalTime <= time && p[i].priority == p[idx].priority)
            {
                if (p[i].arrivalTime < p[idx].arrivalTime)
                {
                    idx = i;
                }
            }
        }

        remainingTime[idx] = remainingTime[idx] - 1;
        Time[time] = p[idx].id;

        if (remainingTime[idx] == 0)
        {
            complete++;
            p[idx].completionTime = time + 1;
            p[idx].turnAroundTime = p[idx].completionTime - p[idx].arrivalTime;
            p[idx].waitingTime = p[idx].turnAroundTime - p[idx].burstTime;
        }
    }

    cout << "\nProcess\tArrival time\tBurst time\tTurn aroundtime\tWaiting time" << endl;
    for (int i = 0; i < n; i++)
        cout << p[i].id << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].burstTime << "\t\t" << p[i].turnAroundTime << "\t\t\t" << p[i].waitingTime << endl;

    return 0;
}