#include<stdio.h>


void merge(int arr[], int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];

    int i=0,j=0,k=left;
    for(i=0;i<n1;i++){
        L[i] = arr[left+i];
    }

    for(i=0;i<n2;i++){
        R[i] = arr[middle+1+i];
    }

    i=0;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int middle = (left+right)/2;

        mergeSort(arr,left, middle);
        mergeSort(arr, middle+1, right);

        merge(arr, left, middle, right);
    }

}

void main(){
    int arr[] = {3,5,1,9,10,2,372,44,8,0,32,44};
    int n =12, i;
    mergeSort(arr,0,12);
    printf("Merge Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}
