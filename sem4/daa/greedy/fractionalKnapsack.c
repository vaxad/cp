#include<stdio.h>
struct Item{
    int p;
    int w;
};

int max(int a, int b){
    return a>b?a:b;
}

void sortOnPW(struct Item it[100], int n){
    for(int i=0;i<n;i++){
        float ri = (float)it[i].p/(float)it[i].w; 
        for(int j=0;j<n;j++){
            float rj = (float)it[j].p/(float)it[j].w; 
            if(rj<ri){
                struct Item temp = it[i];
                it[i] = it[j];
                it[j] = temp;
            }
        }
    }
}

int fractionalKnapsack(struct Item it[100], int w, int n){
    sortOnPW(it, n);
    float p=0;
    for(int i=0;i<n;i++){
        if(it[i].w<=w){
            w-=it[i].w;
            p+=it[i].p;
        }else{
            p+=(float)w*((float)it[i].p/(float)it[i].w);
            w=0;
            break;
        }
    }
    return p;
}
int main(){
    int n, w;
    struct Item it[100];
    printf("FRACTIONAL KNAPSACK:\n");
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
    printf("MAX PROFIT: %d\n", fractionalKnapsack(it, w, n));
    return 0;
}