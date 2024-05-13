#include<stdio.h>
#include<stdbool.h>

int max(int a, int b){
    return a>b?a:b;
}
void printBoolArr(bool arr[100], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]?1:0);
    }
    printf("\n");
}
void sos(int arr[100], bool selected[100], int s, int n,int i){
    // printBoolArr(selected, n);
    if(s==0){
        printf("[ ");
        for(int i=0;i<n;i++){
            if(selected[i]){
                printf("%d ",arr[i]);
            }
        }
        printf("]\n");
        return;
    }
    if(i==n)return;

    sos(arr, selected, s, n, i+1);

    if(arr[i]<=s){
        selected[i]=true;
        sos(arr, selected, s-arr[i], n, i+1);
        selected[i]=false;
    }
}

int main(){
    int n, s;
    int arr[100];
    bool selected[100];
    printf("SUM OF SUBSETS:\n");
    printf("enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter element %d: ", i);
        scanf("%d",&arr[i]);
        selected[i]=false;
    }
    printf("enter required sum: ");
    scanf("%d",&s);
    sos(arr, selected, s, n, 0);
    return 0;
}