#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertion(int arr[], int n){
    for(int i=0;i<n;i++){
        int key = arr[i];
        int j=i-1;

        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    cout<<"INSERTION SORT!\n";
    int arr[] = {2, 5, 1, 29, 2, 12, 34, -4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion(arr, n);
    printArray(arr, n);
    return 0;
}