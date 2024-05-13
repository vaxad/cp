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
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
        }
    }
    printArr(arr, n);
}

int startInd(int arr[100], int n, int h){
    for(int i=1;i<n;i++)
        if(arr[i-1]<=h&&arr[i]>=h)return i;
    return arr[0]>h?0:n-1;
}


void cscan(int arr[100], int n, int h, int end){
    int tsm=0;
    sort(arr, n, h);
    int start = startInd(arr, n, h);
    
    
    for(int i=start;i<n;i++){
        cout<<"VISITING "<<arr[i]<<" FROM "<<h<<endl;
        tsm+=abs(h-arr[i]);
        h=arr[i];
    }
    cout<<"VISITING "<<end<<" FROM "<<h<<endl;
    tsm+=abs(h-end);
    h=end;
    cout<<"VISITING "<<0<<" FROM "<<h<<endl;
    tsm+=abs(h-0);
    h=0;
    for(int i=0;i<start;i++){
        cout<<"VISITING "<<arr[i]<<" FROM "<<h<<endl;
        tsm+=abs(h-arr[i]);
        h=arr[i];
    }
    cout<<"TOTAL SEEK TIME: "<<tsm;
}

int main(){
    int n, arr[100]={0}, h, end;
    cout<<"CSCAN DISK SCHEDULING:\n";
    cout<<"enter number of requests: ";
    cin>>n;
    cout<<"enter requests: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter initial head position: ";
    cin>>h;

    cout<<"enter end position: ";
    cin>>end;

    cscan(arr, n, h, end);
    return 0;
}