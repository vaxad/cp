#include<iostream>

using namespace std;

bool pageHit(int b[100], int nb, int p){
    for(int i=0;i<nb;i++){
        if(b[i]==p)return true;
    }
    return false;
}
void printPages(int b[100], int nb){
    for(int i=0;i<nb;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
int lruInd(int p[100], int b[100], int np, int nb, int curri, int currj){
    int min=-1, minInd=currj;
    if(b[currj]==0)return currj;
    for(int i=0;i<nb;i++){
        for(int j=curri-1;j>=0;j--){
           if(p[j]==b[i]){
            cout<<b[i]<<"was last used at index "<<j<<endl;
            if(min<curri-j){
                min=curri-j;
                minInd=i;
            }
            break;
           } 
        }
    } 
    return minInd;
}
void lru(int p[100], int b[100], int np, int nb){
    int hit=0, miss=0, k=0;
    for(int i=0;i<np;i++){
        printPages(b,nb);
        cout<<"INSERTING PAGE "<<p[i]<<endl;
        if(pageHit(b, nb, p[i])){
            cout<<"PAGE HIT!\n";
            hit++;
        }else{
            miss++;
            k = lruInd(p,b,np,nb,i,k);
            cout<<"LEAST RECENTLY USED PAGE: "<<b[k]<<endl;
            b[k]=p[i];
            k=(k+1)%nb;
            cout<<"PAGE MISS!\n";
        }
    }
    printPages(b,nb);
    cout<<"HIT RATIO: "<<hit<<"/"<<np<<"\nMISS RATIO: "<<miss<<"/"<<np<<endl;
}
int main(){
    int np, nb, p[100], b[100]={0};

    cout<<"LRU PAGE REPLACEMENT:\n";
    cout<<"enter number of blocks: ";
    cin>>nb;
    cout<<"enter number of processes: ";
    cin>>np;
    cout<<"enter process sequence: ";
    for(int i=0;i<np;i++){
        cin>>p[i];
    }

    lru(p,b,np,nb);
    
    return 0;
}