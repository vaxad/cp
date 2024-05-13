#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selection(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main(){
    cout<<"SELECTION SORT!\n";
    int arr[] = {2, 5, 1, 29, 2, 12, 34, -4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection(arr, n);
    printArray(arr, n);
    return 0;
}