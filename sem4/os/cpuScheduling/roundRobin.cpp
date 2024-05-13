#include<iostream>
#include<queue>
using namespace std;

class Process{
    public:
    int at, wt, tat, bt, ct, id, ogbt;

    void print(){
        cout<<id<<"\t"<<at<<"\t"<<ogbt<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt<<"\n";
    }
};

void getNextJob(Process p[100], int n, int time){
    for(int j=1;j<n;j++){
        if(p[j].at<=time){
            

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

void printQueue(queue<Process> pq){
    queue<Process> cp = pq;
    while(!cp.empty()){
        cout<<cp.front().id<<" ";
        cp.pop();
    }
    cout<<endl;
}
bool processInQueue(queue<Process> pq, Process p){
    queue<Process> cp=pq;
    while(!cp.empty()){
        if(cp.front().id==p.id)return true;
        cp.pop();
    }
    return false;
}
void roundRobin(Process p[100], int n, int q){
    //sort based on arrival time
    int time=0;
    sortOnArrivalTime(p,n);
    queue<Process> pq;
    // for(int i=0;i<n;i++){
    //     if(p)
    //     pq.push(p[i]);
    // }
    pq.push(p[0]);
    cout<<time<<"---CPU_IDLE---"<<p[0].at;
    time=p[0].at;
    while(!pq.empty()){
        // printQueue(pq);
        Process pcurr=pq.front();
        time=pcurr.bt<q?time+pcurr.bt:time+q;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].bt!=999&& !processInQueue(pq,p[i])){
                pq.push(p[i]);
            }
        }
        pq.pop();
        cout<<"---P"<<pcurr.id<<"---"<<time;
        if(pcurr.bt<=q){
            pcurr.ct=time;
            pcurr.bt=999;
            pcurr.tat=pcurr.ct-pcurr.at;
            pcurr.wt=pcurr.tat-pcurr.ogbt;
            for(int i=0;i<n;i++){
                if(p[i].id==pcurr.id){
                    p[i]=pcurr;
                }
            }
        }else{
            pcurr.bt=pcurr.bt-q;
            pq.push(pcurr);
            // cout<<"pushed "<<pcurr.id<<endl;
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
    int n, q;
    cout<<"ROUND ROBINN CPU SCHEDULING\n";
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
        processes[i]=p;
    }
    cout<<"enter time quanta: ";
    cin>>q;
    roundRobin(processes, n, q);
    // gnattChart(processes, n);
    cout<<"id\tat\tbt\tct\ttat\twt\n";
    for(int i=0;i<n;i++){
        processes[i].print();

    }

    return 0;
}