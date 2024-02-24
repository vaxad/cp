#include<iostream>
using namespace std;


void rr(int n, int bt[], int at[],int p[], int ct[], int tat[], int wt[], int q){
    for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        if(at[j]<at[i]){
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
    cout<<"\nExecution started for Round Robin\n";
    int time = at[0];
    if(time!=0)cout<<"processor idle from 0 to "<<time<<endl;
    int timeStamp = time+1;
    int completed = 0, index=0;
    while(completed<n){
        for(int i=0;i<n;i++){
            if(at[0]<=timeStamp){

            }
        }
        timeStamp = timeStamp + q;
    }
    // for(int i=0;i<n;i++){
    //   cout<<time<<" - process "<<p[i]+1<<" - "<<time+bt[i]<<endl;
    //   time+=bt[i];
    //   ct[i] = time;
    //   tat[i] = time - at[i];
    //   wt[i] = tat[i] - bt[i];
    //   cout<<"tat: "<<tat[i]<<" wt: "<<wt[i]<<endl;
    // }
    cout<<"Execution ended\n";
}

int main(){
    cout<<"varad prabhu\n";
    int n,p[100]={-1}, bt[100], at[100], ct[100], tat[100], wt[100], q;
    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<"Enter time quanta: ";
    cin>>q;
    for(int i=0;i<n;i++){
        cout<<"Enter burst time for process "<<i+1<<": ";
        cin>>bt[i];
        cout<<"Enter arrival time for process "<<i+1<<": ";
        cin>>at[i];
        p[i]=i;
    }

    rr(n,bt,at,p, ct,tat,wt,q);
    return 0;
}