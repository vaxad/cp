#include<iostream>

using namespace std;

class Process{
    public:
    int id;
    int need[100];
    int alloc[100];
    int max[100];
    int nr;

    void print(){
        cout<<id<<"\t";
        for(int i=0;i<nr;i++){
            cout<<max[i]<<" ";
        }
        cout<<"\t";
        for(int i=0;i<nr;i++){
            cout<<alloc[i]<<" ";
        }
        cout<<"\t\t";
        for(int i=0;i<nr;i++){
            cout<<need[i]<<" ";
        }
        cout<<"\n";
    }

    bool needsExecution(){
        for(int i=0;i<nr;i++){
            if(need[i]>0)return true;
        }
        return false;
    }

    bool isExecutable(int avail[100]){
        for(int i=0;i<nr;i++){
            if(need[i]>avail[i])return false;
        }
        return true;
    }

    void execute(int avail[100]){
        cout<<"EXECUTING P"<<id<<endl;
        for(int i=0;i<nr;i++){
            avail[i]=avail[i]+alloc[i];
            alloc[i]=0;
            need[i]=0;
        }
        cout<<"AVAILABLE RESOURCES: ";
        for(int i=0;i<nr;i++){
            cout<<avail[i]<<" ";
        }
        cout<<endl;
    }

};

void printProcesses(Process p[100], int np){
    cout<<"id\tMAX_RES\tALLOC_RES\tNEED_RES\n";
    for(int i=0;i<np;i++){
        p[i].print();
    }
}
bool jobsCompleted(Process p[100], int np){
    for(int i=0;i<np;i++){
        if(p[i].needsExecution())return false;
    }
    return true;
}
void bankers(Process p[100], int res[100], int np){
    int i=0;
    while(!jobsCompleted(p,np)){
        if(p[i].needsExecution()&&p[i].isExecutable(res)){
            p[i].execute(res);
        }
        i=(i+1)%np;
    }
}
int main(){
    int np,nr;
    cout<<"BANKERS ALGORITHM\n";
    cout<<"enter number of resources: ";
    cin>>nr;
    int res[100];
    for(int i=0;i<nr;i++){
        cout<<"enter number of available instances of resource "<<char('A'+i)<<": ";
        cin>>res[i];
    }
    
    cout<<"enter number of processes: ";
    cin>>np;
    int alloc[100], max[100];
    Process p[100];
    for(int i=0;i<np;i++){
        p[i].id=i;
        p[i].nr=nr;
        for(int j=0;j<nr;j++){
            cout<<"enter number of allocated instances of resource "<<char('A'+j)<<" to process P"<<i<<": ";
            cin>>p[i].alloc[j];
            cout<<"enter number of required instances of resource "<<char('A'+j)<<" for process P"<<i<<": ";
            cin>>p[i].max[j];
            p[i].need[j]=p[i].max[j]-p[i].alloc[j];
        }
    }
    printProcesses(p, np);
    cout<<"AVAILABLE RESOURCES: ";
    for(int i=0;i<nr;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    bankers(p, res, np);
    cout<<"TOTAL RESOURCES: ";
    for(int i=0;i<nr;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}