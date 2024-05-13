#include<stdio.h>
#include<stdbool.h>

void printGraph(int graph[100][100], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void printIntArr(int arr[100], int n){
    printf("COLORS: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

bool isSafe(int graph[100][100], int color[100], int n, int c, int i){
    for(int j=0;j<n;j++){
        if(graph[i][j] && c==color[j])return false;
    }
    return true;
}

bool colorGraph(int graph[100][100], int color[100], int n, int i){
    if(i==n)return true;

    for(int c=1;c<=n;c++){
        if(isSafe(graph, color, n, c, i)){
            color[i]=c;
            if(colorGraph(graph, color, n, i+1))
                return true;
            else
                color[i]=0;
        }
    }
    return false;
}

int main(){
    int n, graph[100][100], color[100];
    printf("GRAPH COLORING:\n");
    printf("enter number of vertices: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &graph[i][j]);
        }
        color[i]=0;
    }
    if(colorGraph(graph, color, n, 0))
        printIntArr(color, n);
    else
        printf("GRAPH COLORING NOT POSSIBLE!\n");
}