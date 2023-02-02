#include <iostream>
#include <math.h>
using namespace std;

int noTrackMov = 0;

void fcfs(int headPos, int n, int requestQueue[])
{
    int i, j;
    for ( i = 0; i < n; i++)
    {
        noTrackMov += abs(requestQueue[i] - headPos);
        headPos = requestQueue[i];
    }

    // print no of track movements: noTrackMov
    // seek seq: requestQueue[]
}

int main()
{
    int headPos, n;

    cout << "Enter the initial head position:";
    cin >> headPos;

    cout << "Enter the number of elements in the request array:";
    cin >> n;

    int requestQueue[n];
    cout << "Enter the elements in the request array" << endl;
    for (int i = 0; i < n; i++)
        cin >> requestQueue[i];

    fcfs(headPos, n, requestQueue);

    return 0;
}