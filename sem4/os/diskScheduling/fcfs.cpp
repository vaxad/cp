#include<iostream>

using namespace std;

int abs(int n){
    return n<0?(-1*n):n;
}
void fcfs(int arr[100], int n, int h){
    int tsm=0;
    for(int i=0;i<n;i++){
        cout<<"VISITING "<<arr[i]<<" FROM "<<h<<endl;
        tsm+=abs(h-arr[i]);
        h=arr[i];
    }
    cout<<"TOTAL SEEK TIME: "<<tsm;
}

int main(){
    int n, arr[100]={0}, h;
    cout<<"FCFS DISK SCHEDULING:\n";
    cout<<"enter number of requests: ";
    cin>>n;
    cout<<"enter requests: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter initial head position: ";
    cin>>h;

    fcfs(arr, n, h);
    return 0;
}