#include<iostream>

using namespace std;

int abs(int n){
    return n<0?(-1*n):n;
}

void printArr(int arr[100], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort(int arr[100], int n, int h){
    // int cp[100]={0};
    bool visited[100]={false};
    for(int i=0;i<n;i++){
        int min=999, minInd=-1;
        for(int j=0;j<n;j++){
            if(abs(arr[j]-h)<min&&!visited[j]){
                min=abs(arr[j]-h);
                minInd=j;
            }
        }
        if(minInd==-1)continue;
        // cp[i]=arr[minInd];
        h=arr[minInd];
        int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd]=temp;
        visited[i]=true;
    }
    printArr(arr, n);
}


void sstf(int arr[100], int n, int h){
    int tsm=0;
    sort(arr, n, h);
    for(int i=0;i<n;i++){
        cout<<"VISITING "<<arr[i]<<" FROM "<<h<<endl;
        tsm+=abs(h-arr[i]);
        h=arr[i];
    }
    cout<<"TOTAL SEEK TIME: "<<tsm;
}

int main(){
    int n, arr[100]={0}, h;
    cout<<"SSTF DISK SCHEDULING:\n";
    cout<<"enter number of requests: ";
    cin>>n;
    cout<<"enter requests: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter initial head position: ";
    cin>>h;

    sstf(arr, n, h);
    return 0;
}