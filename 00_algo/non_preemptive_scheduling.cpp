#include<iostream>
using namespace std;

void sjf(int n, int bt[], int at[],int p[], int ct[], int tat[], int wt[]){
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(at[i]<at[j]){
            int temp = p[j];
            p[j] = p[i];
            p[i] = temp;
            temp = at[j];
            at[j] = at[i];
            at[i] = temp;
            temp = bt[j];
            bt[j] = bt[i];
            bt[i] = temp;
        }
    }
    }
    
    for(int i=0;i<n;i++){
        cout<<"process "<<p[i]+1<<" at: "<<at[i]<<" bt:"<<bt[i]<<endl;
    }

    int total=at[0]+bt[0];
    for(int i=1;i<n;i++){
    for(int j=i+1;j<n&&at[j]<=total;j++){
        if((bt[i]<bt[j])){
            int temp = p[j];
            p[j] = p[i];
            p[i] = temp;
            temp = at[j];
            at[j] = at[i];
            at[i] = temp;
            temp = bt[j];
            bt[j] = bt[i];
            bt[i] = temp;
        }
    }
        total=total+at[i]+bt[i];
        cout << total <<endl;
    }
    for(int i=0;i<n;i++){
        cout<<"process "<<p[i]+1<<" at: "<<at[i]<<" bt:"<<bt[i]<<endl;
    }
    cout<<"\nExecution started for shortest job first\n";
    int time = at[0];
    if(time!=0)cout<<"processor idle from 0 to "<<time<<endl;
    for(int i=0;i<n;i++){
      cout<<time<<" - process "<<p[i]+1<<" - "<<time+bt[i]<<endl;
      time+=bt[i];
      ct[i] = time;
      tat[i] = time - at[i];
      wt[i] = tat[i] - bt[i];
      cout<<"tat: "<<tat[i]<<" wt: "<<wt[i]<<endl;
    }
    cout<<"Execution ended\n";
    
}

void fcfs(int n, int bt[], int at[],int p[], int ct[], int tat[], int wt[]){
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(at[i]<at[j]){
            int temp = p[j];
            p[j] = p[i];
            p[i] = temp;
            temp = at[j];
            at[j] = at[i];
            at[i] = temp;
            temp = bt[j];
            bt[j] = bt[i];
            bt[i] = temp;
        }
    }
    }
    for(int i=0;i<n;i++){
        cout<<"process "<<p[i]+1<<" at: "<<at[i]<<" bt:"<<bt[i]<<endl;
    }
    cout<<"\nExecution started for first come first serve\n";
    int time = at[0];
    if(time!=0)cout<<"processor idle from 0 to "<<time<<endl;
    for(int i=0;i<n;i++){
      cout<<time<<" - process "<<p[i]+1<<" - "<<time+bt[i]<<endl;
      time+=bt[i];
      ct[i] = time;
      tat[i] = time - at[i];
      wt[i] = tat[i] - bt[i];
      cout<<"tat: "<<tat[i]<<" wt: "<<wt[i]<<endl;
    }
    cout<<"Execution ended\n";
}

int main(){
    cout<<"varad prabhu\n";
    int n,p[100]={-1}, bt[100], at[100], ct[100], tat[100], wt[100];
    cout<<"Enter number of processes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter burst time for process "<<i+1<<": ";
        cin>>bt[i];
        cout<<"Enter arrival time for process "<<i+1<<": ";
        cin>>at[i];
        p[i]=i;
    }
    for(int i=0;i<n;i++){
        cout<<"process "<<i+1<<" at: "<<at[i]<<" bt:"<<bt[i]<<endl;
    }
    // fcfs(n,bt,at,p, ct,tat,wt);
    sjf(n,bt,at,p,ct,tat,wt);
    return 0;
}