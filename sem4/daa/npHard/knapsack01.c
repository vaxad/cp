#include<stdio.h>
struct Item{
    int p;
    int w;
};

int max(int a, int b){
    return a>b?a:b;
}

int knapsack01(struct Item it[100], int w, int n){
    // printf("w = %d, n = %d\n",w,n);
    if(n==0 || w==0)    //max weight exhausted OR elements over
        return 0;

    if(w<it[n-1].w)
        return knapsack01(it, w, n-1);      //current element's weight > remaining weight capacity
    else
        return max( (it[n-1].p+knapsack01(it, w-it[n-1].w, n-1)), knapsack01(it, w, n-1) );
        //     max betwn (select current item(include its profit) + profit from remaining items) & (do not select current item (do noy include its profit)+ profit from remaining items)

}
int main(){
    int n, w;
    struct Item it[100];
    printf("0 1 KNAPSACK:\n");
    printf("enter number of items: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter weight of item %d: ", i);
        scanf("%d",&(it[i].w));
        printf("enter profit of item %d: ", i);
        scanf("%d",&(it[i].p));
    }
    printf("enter maximum capacity: ");
    scanf("%d",&w);
    printf("MAX PROFIT: %d\n", knapsack01(it, w, n));
    return 0;
}