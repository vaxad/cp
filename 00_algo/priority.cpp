#include<iostream>
using namespace std;


void sortPriority(int at[], int bt[], int p[],int time, int n,int pt[], int tempBt[]){
    for(int i=0;i<n&&at[i]<=time;i++){
    for(int j=i;j<n&&at[j]<=time;j++){
        if(pt[j]>pt[i]){
            int temp = p[j];
            p[j] = p[i];
            p[i] = temp;
            temp = at[j];
            at[j] = at[i];
            at[i] = temp;
            temp = bt[j];
            bt[j] = bt[i];
            bt[i] = temp;
            temp = pt[j];
            pt[j] = pt[i];
            pt[i] = temp;
            temp = tempBt[j];
            tempBt[j] = tempBt[i];
            tempBt[i] = temp;
        }
    }
    }
    cout<<"at time = "<<time<<endl;
    for(int i=0;i<n;i++){
        cout<<"process "<<p[i]+1<<" at: "<<at[i]<< " bt: "<<bt[i]<<" pt: "<<pt[i]<<endl;
    }
    cout<<endl;
}

void priority(int n, int bt[], int at[], int p[], int ct[], int tat[], int wt[], int pt[], int total, int tempBt[]){
    for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        if(at[j]<at[i]||(at[j]==at[i]&&pt[j]>pt[i])){
            int temp = p[j];
            p[j] = p[i];
            p[i] = temp;
            temp = at[j];
            at[j] = at[i];
            at[i] = temp;
            temp = bt[j];
            bt[j] = bt[i];
            bt[i] = temp;
            temp = pt[j];
            pt[j] = pt[i];
            pt[i] = temp;
            temp = tempBt[j];
            tempBt[j] = tempBt[i];
            tempBt[i] = temp;
        }
    }
    }
    cout<<"\nExecution started for priority\n";
    int temp = at[0];
    if(temp!=0)cout<<"processor idle from 0 to "<<temp<<endl;
    for(int i=temp+1;i<total;i++){
        bt[0]--;
        int time = i;
        if(bt[0]==0){
            pt[0]=-1;
            cout<<at[0]<<" - process "<<p[0]+1<<" - "<<time<<endl;
            ct[0] = time;
            tat[0] = ct[0] - at[0];
            wt[0] = tat[0] - tempBt[0];
            cout<<"tat: "<<tat[0]<<" wt: "<<wt[0]<<endl;
        }
        sortPriority(at,bt,p,time,n,pt,tempBt);
    }
    int tatsum=0, wtsum=0;
    cout<<endl;
    // for(int i=0;i<n;i++){
    //   tat[i] = time - at[i];
    //   tatsum+=tat[i];
    //   wt[i] = tat[i] - bt[i];
    //   wtsum+=wt[i];
    //   cout<<"tat: "<<tat[i]<<" wt: "<<wt[i]<<endl;
    // }
    // cout<<"\naverage waiting time: "<<(float)wtsum/(float)n<<"\taverage tat: "<<(float)tatsum/(float)n<<endl;
    // cout<<"Execution ended\n";
    cout<<"Execution ended\n";
}
int main(){
    cout<<"varad prabhu\n";
    int n,p[100]={-1}, bt[100], at[100],pt[100], ct[100], tat[100], wt[100],st[100],et[100],tempBt[100], total=0;
    cout<<"Enter number of processes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter burst time for process "<<i+1<<": ";
        cin>>bt[i];
        tempBt[i]=bt[i];
        total+=bt[i];
        cout<<"Enter arrival time for process "<<i+1<<": ";
        cin>>at[i];
        cout<<"Enter priority for process "<<i+1<<": ";
        cin>>pt[i];
        p[i]=i;
        st[i]=-1;
        et[i]=-1;
    }

    priority(n,bt,at,p, ct,tat,wt,pt,total,tempBt);
    //  sjf(n,bt,at,p,ct,tat,wt);
    return 0;
}