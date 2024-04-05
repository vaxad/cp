#include<iostream>

using namespace std;

typedef struct 
{
    int process_id;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    int priority;
    int rt;
    int flag;
} process;

void at_sort(process p[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j+1].at)
            {
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    int n, quanta;
    cout<<"Enter number of processes ";
    cin>>n;
    process p[n];
    for (int i=0; i<n; i++)
    {
        p[i].process_id = i+1;
        cout<<"Enter arrival time: ";
        cin>>p[i].at;
        cout<<"Enter burst time: ";
        cin>>p[i].bt;
        p[i].rt = p[i].bt;
    }

    cout<<"Enter time quanta: ";
    cin>>quanta;

    at_sort(p, n);

    int curr_time = 0;
    int completed = 0;
    int index=-1;

    while (completed != n) {
        int ctr = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= curr_time && p[i].rt > 0 && p[i].flag == 0) {
                index=i;
                p[i].flag = 1;
                ctr = 1;
                break;
            }
        }
        if (ctr == 0)
        {
            for (int i = 0; i < n; i++) {
                p[i].flag = 0;
            }
        }
        
        if (index == -1) {
            curr_time++;
        } else {
            curr_time += quanta;
            cout<<curr_time -  quanta<<" process " << p[index].process_id <<": "<<curr_time;
            p[index].rt -= quanta;
            if (p[index].rt == 0)
            {
                p[index].ct = curr_time;
                p[index].tt = p[index].ct - p[index].at;
                p[index].wt = p[index].tt - p[index].bt;
                completed++;
            }
        }
    }

    int tt = 0, wt = 0;
    for (int i=0; i<n; i++)
    {
        tt += p[i].tt;
        wt += p[i].wt;
        cout<< " Process ID : "<< p[i].process_id << " Priority: "<< p[i].priority <<" Arrival Time"<< p[i].at <<" Burst Time"<< p[i].bt <<" Completion Time: "<< p[i].ct<< " Turnaround time"<< p[i].tt <<" Waiting time"<< p[i].wt << endl;
    }

    cout<<"Average Turnaround time: "<< (float)tt/n;
    cout<<"Average Waiting time: "<< (float)wt/n;

    return 0;
}
