#include<stdio.h>
#include<stdlib.h>

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
} process;

void at_sort(process processes[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].at > processes[j+1].at)
            {
                process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process processes[n];
    for (int i=0; i<n; i++)
    {
        processes[i].process_id = i+1;
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].at);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].bt);
        processes[i].rt = processes[i].bt;
        printf("Enter priority: ");
        scanf("%d", &processes[i].priority);
    }

    at_sort(processes, n);

    int current_time = 0;
    int completed = 0;
    int max_priority_index = -1;

    while (completed != n) {
        max_priority_index = -1;
        int max_priority = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].at <= current_time && processes[i].priority > max_priority && processes[i].rt > 0) {
                max_priority = processes[i].priority;
                max_priority_index = i;
            }
        }
        
        if (max_priority_index == -1) {
            current_time++;
        } else {
            current_time += 1;
            printf("%d:process %d:%d\n", current_time - 1, processes[max_priority_index].process_id, current_time);
            processes[max_priority_index].rt -= 1;
            if (processes[max_priority_index].rt == 0)
            {
                processes[max_priority_index].ct = current_time;
                processes[max_priority_index].tt = processes[max_priority_index].ct - processes[max_priority_index].at;
                processes[max_priority_index].wt = processes[max_priority_index].tt - processes[max_priority_index].bt;
                // processes[max_priority_index].priority = -1;
                completed++;
            }
        }
    }

    printf("Process ID\t\tPriority\t\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tTurnaround time\t\tWaiting time\n");
    int tt = 0, wt = 0;
    for (int i=0; i<n; i++)
    {
        tt += processes[i].tt;
        wt += processes[i].wt;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].priority, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tt, processes[i].wt);
    }

    printf("Average Turnaround time: %.2f\n", (float)tt/n);
    printf("Average Waiting time: %.2f\n", (float)wt/n);

    return 0;
}