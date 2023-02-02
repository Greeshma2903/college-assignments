#include <iostream>
using namespace std;

struct process
{
    int pid,
        arrival_time,
        burst_time,
        priority,
        completion_time,
        turnaround_time,
        waiting_time;
};

int main()
{
    int complete, time, idx, i, j, n, avtat, avwt, currPri;
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
        p[i].pid = i + 1;
        cout << "Enter burst time: ";
        cin >> p[i].burst_time;
        cout << "Enter arrival time: ";
        cin >> p[i].arrival_time;
        cout << "Enter priority:";
        cin >> p[i].priority;
    }
    
    complete = 0;
    time = 0;
    while (complete != n)
    {
        idx = -1;
        currPri = 999;
        for (i = 0; i < n; i++)
        {
            if (!done[i] && p[i].arrival_time <= time)
            {
                if (p[i].priority < currPri)
                {
                    idx = i;
                    currPri = p[i].priority;
                }
                // if priorities are same, check at
                if (p[i].priority == currPri)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        idx = i;
                    }
                }
            }
        }

        if (idx != 1)
        {
            done[i] = 1;
            complete++;
            time += p[idx].burst_time;

            p[idx].completion_time = time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
        }
        else {
            time++;
        }
    }

    return 0;
}