#include<iostream>

using namespace std;

void worstFit(int p[100], int b[100], int np, int nb, int f[100]){
    bool allocated[100]={false};
    for(int i=0;i<np;i++){
        int max=-1, maxInd=-1;
        for(int j=0;j<nb;j++){
            cout<<p[i]<<" in "<<b[j]<<" status: "<<allocated[j]<<endl;
            if(b[j]>=p[i]&&!allocated[j]){
                if(b[j]-p[i]>max){
                    max=b[j]-p[i];
                    maxInd=j;
                }
            }
        }
        if(maxInd!=-1){
            allocated[maxInd]=true;
            f[maxInd]=max;
            cout<<"--> PROCESS "<<i<<" ALLOCATED IN BLOCK "<<maxInd<<" (fragmentation="<<f[maxInd]<<")\n";
        }
    }
}
int main(){
    int np, nb;
    int p[100], b[100], f[100];
    cout<<"WORST FIT MEMORY ALLOCATION:\n";
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

    worstFit(p, b, np, nb, f);

    return 0;
}