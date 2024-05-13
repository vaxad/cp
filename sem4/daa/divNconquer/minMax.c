#include<stdio.h>

int max, min;
void printArr(int arr[100], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void minMax(int arr[100], int l, int h){
    int m, max1, min1;
    if(l==h){
        max=min=arr[l];
    }else if(l==h-1){
        if(arr[l]<arr[h]){
            min=arr[l];
            max=arr[h];
        }else{
            min=arr[h];
            max=arr[l];
        }
    }else{
        m=l+(h-l)/2;
        minMax(arr,l,m);
        min1=min;
        max1=max;
        minMax(arr,m+1,h);
        if(max1>max){
            max=max1;
        }
        if(min>min1){
            min=min1;
        }
    }
}
int main(){
    int n, arr[100];
    printf("MINMAX ALGO:\n");
    printf("enter number of elements in array: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("enter element at index %d: ",i);
        scanf("%d",&arr[i]);
    }

    printArr(arr, n);
    minMax(arr, 0, n-1);
    
    printf("MAX: %d\nMIN: %d", max, min);
    return 0;
}
