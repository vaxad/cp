#include<stdio.h>

struct Activity{
    int start;
    int end;
};

void sortOnEndTime(struct Activity a[100], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j].end<a[i].end){
                struct Activity temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


void activitySelection(struct Activity a[100], int n){
    sortOnEndTime(a, n);
    int prev=a[0].start;
    for(int i=0;i<n;i++){
        if(a[i].start>=prev){
            printf("EXECUTING JOB %d (%d -> %d)\n", i, a[i].start, a[i].end);
            prev=a[i].end;
        }
    }
}

int main(){
    struct Activity a[100];
    int n;
    printf("ACTIVITY SELECTION:\n");
    printf("enter number of activities:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter start-time of job %d: ",i);
        scanf("%d",&(a[i].start));
        printf("enter end-time of job %d: ",i);
        scanf("%d",&(a[i].end));
    }
    activitySelection(a,n);
    return 0;
}