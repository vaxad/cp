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

int firstOccurence(int arr[100], int n, int i){
    while(i<n){
        if(arr[i]==n)return i;
        i++;
    }
    return -1;
}
int optimalInd(int p[100], int b[100], int np, int nb, int curri, int currj){
    int min=-1, minInd=currj;
    if(b[currj]==0)return currj;
    for(int i=0;i<nb;i++){
        int occurence = firstOccurence(p,b[i],curri+1);
        if(occurence==-1)return i;
        else{
            cout<<b[i]<<"will be used at index "<<occurence<<endl;
            if(min<occurence-curri){
                min=occurence-curri;
                minInd=i;
            }
        }
        // for(int j=curri+1;j<np;j++){
        //    if(p[j]==b[i]){
        //     cout<<b[i]<<"will be used at index "<<j<<endl;
        //     if(min<j-curri){
        //         min=j-curri;
        //         minInd=i;
        //     }
        //     break;
        //    } 
        // }
    } 
    return minInd;
}
void optimal(int p[100], int b[100], int np, int nb){
    int hit=0, miss=0, k=0;
    for(int i=0;i<np;i++){
        printPages(b,nb);
        cout<<"INSERTING PAGE "<<p[i]<<endl;
        if(pageHit(b, nb, p[i])){
            cout<<"PAGE HIT!\n";
            hit++;
        }else{
            miss++;
            k = optimalInd(p,b,np,nb,i,k);
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

    cout<<"OPTIMAL PAGE REPLACEMENT:\n";
    cout<<"enter number of blocks: ";
    cin>>nb;
    cout<<"enter number of processes: ";
    cin>>np;
    cout<<"enter process sequence: ";
    for(int i=0;i<np;i++){
        cin>>p[i];
    }

    optimal(p,b,np,nb);
    
    return 0;
}