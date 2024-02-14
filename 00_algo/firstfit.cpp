// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int nb,np,block[100],process[100],avail=0;
    bool used[100] = {false};
    cout << "First Fit Algorithm: ";
    cout<<"enter number of blocks: ";
    cin>>nb;
    for(int i=0;i<nb;i++){
    cout<<"enter size of block "<<i+1<<": ";
    cin>>block[i];
    avail+=block[i];
    }
    cout<<"enter number of processes: ";
    cin>>np;
    for(int i=0;i<np;i++){
    cout<<"enter size of process "<<i+1<<": ";
    cin>>process[i];
    }
    for(int i=0;i<np;i++){
    for(int j=0;j<nb;j++){
    if(process[i]<=block[j]){
        if(!used[j]){
            cout<<"\nprocess"<<i+1<<" allocated in block "<<j+1<<endl;
            block[j]-=process[i];
            used[j]=true;
            break;
        }
    }else if(j==nb-1){
        cout<<"\nprocess"<<i+1<<" could not be allocated in any block "<<endl;
    }
    }
    }
    int frag=0;
    for(int i=0;i<nb;i++){
        frag+=block[i];
    }
    cout<<avail<<" available and "<<frag<<" used\n";
    float ratio = (float)(avail-frag)/(float)(avail);
    cout<<"ratio "<<ratio;
    return 0;
}