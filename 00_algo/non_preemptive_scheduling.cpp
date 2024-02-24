#include<iostream>
using namespace std;

void sortSjf(int at[], int bt[], int p[],int time, int process, int n){
    for(int i=process+1;i<n&&at[i]<=time;i++){
    for(int j=i;j<n&&at[j]<=time;j++){
        if(bt[j]<bt[i]){
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
}
void sjf(int n, int bt[], int at[],int p[], int ct[], int tat[], int wt[]){
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
    cout<<"\nExecution started for first come first serve\n";
    int time = at[0];
    if(time!=0)cout<<"processor idle from 0 to "<<time<<endl;
    int tatsum=0, wtsum=0;
    for(int i=0;i<n;i++){
      cout<<time<<" - process "<<p[i]+1<<" - "<<time+bt[i]<<endl;
      time+=bt[i];
      ct[i] = time;
      tat[i] = time - at[i];
      tatsum+=tat[i];
      wt[i] = tat[i] - bt[i];
      wtsum+=wt[i];
      cout<<"tat: "<<tat[i]<<" wt: "<<wt[i]<<endl;
      sortSjf(at,bt,p,time,i, n);
    }
    cout<<"average waiting time: "<<(float)wtsum/(float)n<<"\taverage tat: "<<(float)tatsum/(float)n<<endl;
    cout<<"Execution ended\n";
}

void fcfs(int n, int bt[], int at[],int p[], int ct[], int tat[], int wt[]){
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
    cout<<"\nExecution started for first come first serve\n";
    int time = at[0];
    if(time!=0)cout<<"processor idle from 0 to "<<time<<endl;
    int tatsum=0, wtsum=0;
    for(int i=0;i<n;i++){
      cout<<time<<" - process "<<p[i]+1<<" - "<<time+bt[i]<<endl;
      time+=bt[i];
      ct[i] = time;
      tat[i] = time - at[i];
      tatsum+=tat[i];
      wt[i] = tat[i] - bt[i];
      wtsum+=wt[i];
      cout<<"tat: "<<tat[i]<<" wt: "<<wt[i]<<endl;
    }
    cout<<"average waiting time: "<<(float)wtsum/(float)n<<"\taverage tat: "<<(float)tatsum/(float)n<<endl;
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

    fcfs(n,bt,at,p, ct,tat,wt);
    //  sjf(n,bt,at,p,ct,tat,wt);
    return 0;
}