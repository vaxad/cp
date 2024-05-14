#include<stdio.h>
#include<stdbool.h>

int i,j,k;

void printArr(int arr[100], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void printGraph(int graph[100][100], int n){
    printf("graph:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int minIndex(int dist[100], bool visited[100], int n){
    int min=999, minInd=-1;
    for(i=0;i<n;i++){
        if(!visited[i]&&dist[i]<min){
            min=dist[i];
            minInd=i;
        }
    }
    return minInd;
}
void djikstra(int graph[100][100], int src,int n){
    bool visited[100];
    int dist[100];
    int prev=0;
    int minInd;

    for(i=0;i<n;i++){
        visited[i]=false;
        dist[i]=999;  //INF
    }

    dist[src]=0;
    for(int i=0;i<n;i++){
        minInd=minIndex(dist, visited, n);
        printf("minInd: %d (i=%d)\n", minInd, i);
        if(minInd==-1)continue;
        prev=dist[minInd];
        visited[minInd]=true;
        for(j=0;j<n;j++){
            if(graph[minInd][j]&&!visited[j]){
                if((graph[minInd][j]+prev)<dist[j]){
                    printf("VISITING %d from %d (%d -> %d)\n", j, minInd, dist[j], graph[minInd][j]+prev);
                    dist[j]=graph[minInd][j]+prev;
                }
            }
        }
        printArr(dist, n);            
    }
}

int main(){
    int n, graph[100][100], src;
    printf("DJIKSTRA'S ALGORITHM\n");
    printf("enter number of vertices: ");
    scanf("%d",&n);
    //  1 source se sab nodes tak ka shortest path
    printf("enter adjacency matrix(0 for no edge):\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("enter source index:\n");
    scanf("%d",&src);
    printGraph(graph, n);
    djikstra(graph, src, n);
    return 0;
}