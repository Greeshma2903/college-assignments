#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;
int n;
float average_waiting_time,average_turnaround_time;

class Process
{
    
    int remaining_time;
    int wait_time;
    int completion_time;
    int turn_around_time;
    bool isInQueue;
    
    public:
    	int processNo;
        int burst_time;
        int arrival_time;
        
        void setInput(int i,int BT,int AT)
		{
            processNo = i+1;
            burst_time = BT;
            arrival_time = AT;
            remaining_time = BT;
            turn_around_time = 0;
            completion_time = 0;
            wait_time = 0;
            isInQueue = false;
        }
        
		void display()
		{
            cout << processNo << setw(30) << burst_time << setw(30);
            cout << turn_around_time << setw(30) << wait_time << endl;
            
        }
        
		friend void roundRobin(Process p[],Process q[],int tQ,int &j)
		{
            j = 0;
            queue <Process*> readyQueue;
            int minArrivalTime = p[0].arrival_time;
        
			for(int i = 0; i < n; i++)
			{
                if(p[i].arrival_time == minArrivalTime)
				{
                    p[i].isInQueue = true;
                    readyQueue.push(&p[i]);
                    cout<<p[i].processNo;
                }
            }
            
			           
			int timeElapsed = minArrivalTime;
            
			while(readyQueue.size() != 0)
			{
                Process *p = (readyQueue.front());
                readyQueue.pop();
                p->isInQueue = false;
                
                if(p->remaining_time <= tQ)
				{
                    timeElapsed += p->remaining_time;
                    p->remaining_time = 0;
                    p->completion_time = timeElapsed;
                    p->turn_around_time = p->completion_time - p->arrival_time;
                    p->wait_time = p->turn_around_time - p->burst_time;
                }
                
				else
				{
                    timeElapsed += tQ;
                    p->remaining_time -= tQ;
                }

                // If any process has arrived and is left to execute while a process is get executed by CPU then put it into ready queue
                for(int i = 0; i < n; i++)
				{
                    if(p[i].processNo != p->processNo && p[i].arrival_time <= timeElapsed && p[i].isInQueue == false && p[i].remaining_time > 0)
					{
                   	    p[i].isInQueue = true;
                        readyQueue.push(&p[i]);
                    }
                }
                
                //If process is remaining to be executed then put into back into readyQueue
                if(p->remaining_time > 0)
				{
                    p->isInQueue = true;
                    readyQueue.push(p);
                }

                // For Gantt Chart
                q[j].processNo = p->processNo;
                q[j].completion_time = timeElapsed;
                j++;
            }
            cout << endl;
        }
        
        friend void displayGanttChart(Process p[],Process q[],int n)
		{
		    for(int i=0;i<6*n;i++)
                cout << "-";

            for(int i=0;i<n;i++)
                cout << "-";

            cout << endl;

            for(int i=0;i<n;i++)
                cout << "|  P" << q[i].processNo  << "  ";

            cout << "|" << endl;

            for(int i=0;i<6*n;i++)
                cout << "-";

            for(int i=0;i<n;i++)
                cout << "-";

            cout << "\n" <<p[0].arrival_time;

            for(int i=0;i<n;i++)
                cout << setw(7) << q[i].completion_time;
        }
        
		friend void findAvg(Process p[],float average_waiting_time,float average_turnaround_time)
		{
            average_turnaround_time = 0;
            average_waiting_time = 0;
            for(int i = 0; i < n; i++)
			{
                average_turnaround_time += p[i].turn_around_time;
                average_waiting_time += p[i].wait_time;
            }
            
			average_waiting_time = average_waiting_time/(n*1.0);
            average_turnaround_time = average_turnaround_time/(n*1.0);
            cout << "\n\nAverage Waiting Time = " << average_waiting_time << endl;
            cout << "Average Turnaround Time = " << average_turnaround_time << endl;
        }
};

bool comparator(Process p1, Process p2) 
{
   return(p1.arrival_time < p2.arrival_time);
}

int main()
{
    int timeSlice,BT,AT,j;

    cout << "Enter the number of processes:";
    cin >> n;

    Process *p = new Process[n];
    Process *q = new Process[n*20];
    cout << "Enter the burst time and arrival time of each process:" << endl;
    
    for(int i=0; i<n; i++)
	{
        cin >> BT >> AT;
        p[i].setInput(i,BT,AT);
    }

    cout << "Enter the time slice/ time quantum:";
    cin >> timeSlice;

    // Sort processes by arrival time
    sort(p, p + n,comparator);
	
    roundRobin(p,q,timeSlice,j);
    
    cout << endl;
    cout << "Process" << setw(30) << "Burst Time"<< setw(25);
    cout << "turn_around_time" << setw(35) << "Waiting Time" << endl;
    
    for(int i = 0; i < n; i++)
	{
        p[i].display();
	}
	
    displayGanttChart(p,q,j);

    findAvg(p,average_waiting_time,average_turnaround_time);

    return 0;
}
