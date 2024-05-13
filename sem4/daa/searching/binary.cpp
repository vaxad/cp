#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int binarySearch(int arr[], int n, int key){
    int l=0, h=n-1;
    while(l<=h){
        int m = l + (h-l)/2;
        // cout<<arr[m]<<endl;
        if(arr[m]==key){
            return m;
        }else if(arr[m]<key){
            l=m+1;
        }else{
            h=m-1;
        }
    }
    return -1;
}

int main(){
    cout<<"BINARY SEARCH!\n";
    int arr[] = {-4, 1, 2, 2, 3, 5, 12, 29, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<binarySearch(arr, n, 2)<<endl;
    printArray(arr, n);
    return 0;
}