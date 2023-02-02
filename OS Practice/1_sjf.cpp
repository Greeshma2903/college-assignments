#include <iostream>
using namespace std;
struct process
{
    int id, arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime, responseTime;
};

int main()
{
    int n, completed, i, j, time, sjf, tat, wt;

    cout << "Enter num process:";
    cin >> n;

    struct process p[n];
    int done[n];
    for (i = 0; i < n; i++)
    { // no P done
        done[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        cout << "Enter burst time: ";
        cin >> p[i].burstTime;
        cout << "Enter arrival time: ";
        cin >> p[i].arrivalTime;
    }
    time = 0;
    completed = 0;

    while (completed != n)
    {   	// while processes still left

        sjf = -1;
        for (i = 0; i < n; i++)
        {
            if (p[i].arrivalTime <= time && done[i] != 0)
            {
                sjf = i;
                break;
            }
        }
        if (sjf != -1)
        {
            for (i = 0; i < n; i++)
            {   // select shortest burst time, which arrived in time
                if (!done[i] && p[i].burstTime < p[sjf].burstTime && p[i].arrivalTime <= time)
                {
                    sjf = i;
                }
            }
            done[sjf] = 1;
            completed++;
            time = time + p[sjf].burstTime;

            p[sjf].completionTime = time;
            p[sjf].turnAroundTime = p[sjf].completionTime - p[sjf].arrivalTime;
            p[sjf].waitingTime = p[sjf].turnAroundTime - p[sjf].burstTime;
        }
        else
        {
            time++;
        }
    }

    tat = 0;
    wt = 0;
    for (i = 0; i < n; i++)
    {
        tat += p[i].turnAroundTime;
        wt += p[i].waitingTime;
    }
    tat /= n;
    wt /= n;

    cout << "\nProcess\tArrival time\tBurst time\tTurn around time\tWaiting time\t" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].burstTime << "\t\t" << p[i].turnAroundTime << "\t\t\t" << p[i].waitingTime << endl;
    }

    return 0;
}