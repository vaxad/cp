#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubble(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main(){
    cout<<"BUBBLE SORT!\n";
    int arr[] = {2, 5, 1, 29, 2, 12, 34, -4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble(arr, n);
    printArray(arr, n);
    return 0;
}