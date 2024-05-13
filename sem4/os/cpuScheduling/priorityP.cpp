#include<iostream>

using namespace std;

class Process{
    public:
    int at, wt, tat, bt, ct, id, pr, ogbt, ogpr;

    void print(){
        cout<<id<<"\t"<<at<<"\t"<<ogbt<<"\t"<<ogpr<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt<<"\n";
    }
};

void getMaxOnPriority(Process p[100], int n, int time){
    for(int j=1;j<n;j++){
        if(p[j].at<=time&&p[j].pr>p[0].pr){
            Process temp;
            temp=p[j];
            p[j]=p[0];
            p[0]=temp;
        }
    }
}
bool jobsCompleted(Process p[100], int n){
    for(int i=0;i<n;i++){
        if(p[i].bt!=999)return false;
    }
    return true;
}
void sortOnArrivalTime(Process p[100], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[j].at<p[i].at){
                Process temp;
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
        }
    }
}
void priorityP(Process p[100], int n){
    //sort based on arrival time
    int time=0;
    sortOnArrivalTime(p,n);
    cout<<time<<"---CPU_IDLE---"<<p[0].at;
    time=p[0].at;
    while(!jobsCompleted(p,n)){
        getMaxOnPriority(p,n,time);
        time++;
        cout<<"---P"<<p[0].id<<"---"<<time;
        if(p[0].bt==1){
            p[0].bt=999;
            p[0].pr=-1;
            p[0].ct=time;
            p[0].tat=p[0].ct-p[0].at;
            p[0].wt=p[0].tat-p[0].ogbt;
        }else{
            p[0].bt--;
        }
    }
    cout<<endl;

}

void gnattChart(Process p[100], int n){
    cout<<0<<"---CPU_IDLE---"<<p[0].at;
    for(int i=0;i<n;i++){
        cout<<"---"<<"P"<<p[i].id<<"---"<<p[i].ct;
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"PRIORITY PREEMPTIVE CPU SCHEDULING\n";
    cout<<"enter number of processes: ";
    cin>>n;
    Process processes[100];
    for(int i=0;i<n;i++){
        Process p;
        p.id=i;
        cout<<"enter arrival time of process "<<i<<": ";
        cin>>p.at;
        cout<<"enter burst time of process "<<i<<": ";
        cin>>p.bt;
        p.ogbt=p.bt;
        cout<<"enter priority of process "<<i<<": ";
        cin>>p.pr;
        p.ogpr=p.pr;
        processes[i]=p;
    }
    priorityP(processes, n);
    // gnattChart(processes, n);
    cout<<"id\tat\tbt\tpr\tct\ttat\twt\n";
    for(int i=0;i<n;i++){
        processes[i].print();

    }

    return 0;
}