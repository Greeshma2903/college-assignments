#include <iostream>
#include <iomanip>
using namespace std;

// assume p arrives at 0
struct process
{
    int pid, bt, wt, tat;
};

int main()
{
    struct process p[5];
    cout << "Enter burst times:" << endl;
    int i, avwt = 0, avtat = 0, j;
    for (i = 0; i < 5; i++)
    {
        p[i].pid = i + 1;
        cout << i << ": ";
        cin >> p[i].bt;
    }

    // calculate wait time
    // wt[i] = sum of bt till i
    p[0].wt = 0;
    for (i = 1; i < 5; i++)
    {
        p[i].wt = 0;
        for (j = 0; j < 5; j++)
        {
            p[i].wt += p[j].bt;
        }
    }

    // calculate tat, av tat, av wait time
    for (i = 0; i < 5; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
        avwt += p[i].wt;
        avtat += p[i].tat;
    }

    avtat /= 5;
    avwt /= 5;

    cout << "\nav wt:" << avwt;
    cout << "\nav tat:" << avtat;

    cout << "\n\ngantt\n";
    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    for (i = 0; i < 5; i++)
    {
        cout << "\n"
             << p[i].pid << "\t\t" << p[i].bt << "\t\t\t" << p[i].wt << "\t" << p[i].tat;
    }

    return 0;
}