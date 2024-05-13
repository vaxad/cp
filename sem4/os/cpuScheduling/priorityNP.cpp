#include<iostream>

using namespace std;

class Process{
    public:
    int at, wt, tat, bt, ct, id, pr;

    void print(){
        cout<<id<<"\t"<<at<<"\t"<<bt<<"\t"<<pr<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt<<"\n";
    }
};

void sortOnPriority(Process p[100], int n){
    int time=p[0].at;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[j].at<=time&&p[j].pr>p[i].pr){
                Process temp;
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
        }
        time+=p[i].bt;
    }
}
void priorityNP(Process p[100], int n){
    //sort based on arrival time
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[j].at<p[i].at){
                //swap
                Process temp;
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
        }
    }

    sortOnPriority(p,n);

    //schedule
    int time=p[0].at;
    for(int i=0;i<n;i++){
        time+=p[i].bt;
        p[i].ct=time;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }

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
    cout<<"PRIORITY NON PREEMPTIVE CPU SCHEDULING\n";
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
        cout<<"enter priority of process "<<i<<": ";
        cin>>p.pr;
        processes[i]=p;
    }
    priorityNP(processes, n);
    gnattChart(processes, n);
    cout<<"id\tat\tbt\tpr\tct\ttat\twt\n";
    for(int i=0;i<n;i++){
        processes[i].print();
    }

    return 0;
}