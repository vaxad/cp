#include<iostream>

using namespace std;

void nextFit(int p[100], int b[100], int np, int nb, int f[100]){
    bool allocated[100]={false};
    int lastAllocatedInd=-1;
    for(int i=0;i<np;i++){
        for(int j=(lastAllocatedInd+1)%nb;j!=lastAllocatedInd;j=(j+1)%nb){
            cout<<p[i]<<" in "<<b[j]<<" status: "<<allocated[j]<<endl;
            if(b[j]>=p[i]&&!allocated[j]){
                allocated[j]=true;
                f[j]=b[j]-p[i];
                lastAllocatedInd=j;
                cout<<"--> PROCESS "<<i<<" ALLOCATED IN BLOCK "<<j<<" (fragmentation="<<f[j]<<")\n";
                break;
            }
        }
    }
}
int main(){
    int np, nb;
    int p[100], b[100], f[100];
    cout<<"NEXT FIT MEMORY ALLOCATION:\n";
    cout<<"enter number of blocks: ";
    cin>>nb;
    cout<<"enter number of processes: ";
    cin>>np;
    for(int i=0;i<nb;i++){
        cout<<"enter size of block "<<i<<": ";
        cin>>b[i];
    }

    for(int i=0;i<np;i++){
        cout<<"enter size of process "<<i<<": ";
        cin>>p[i];
    }

    nextFit(p, b, np, nb, f);

    return 0;
}