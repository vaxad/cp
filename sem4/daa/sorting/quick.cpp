#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[], int l, int h){
    int pivot = arr[h];
    int i=l;

    for(int j=l;j<=h;j++){
        if(arr[j]<pivot){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
    int temp = arr[h];
    arr[h] = arr[i];
    arr[i] = temp;
    return i;
    
}
void quickSort(int arr[], int l, int h){
    if(l<h){
        int p = partition(arr,l,h);

        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }

}
int main(){
    cout<<"QUICK SORT!\n";
    int arr[] = {2, 5, 1, 29, 2, 12, 34, -4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}