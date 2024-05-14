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

int calculateEdges(int graph[100][100],int edge[3][100], int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]){
                edge[0][count]=i; //source vertex
                edge[1][count]=j; //destination vertex
                edge[2][count]=graph[i][j]; // weight of edge
                printf("{ %d, %d, %d}\n", i, j, graph[i][j]);
                count++;
            }
        }
    }
    return count;
}

void bellmanFord(int graph[100][100], int src,int n){
    int dist[100];
    int edge[3][100];
    int ne = calculateEdges(graph, edge, n);
    int u, v, w;

    for(i=0;i<n;i++)dist[i]=999;  //INF

    dist[src]=0;
    for(int i=0;i<n-1;i++){
        for(j=0;j<ne;j++){
            u=edge[0][j];
            v=edge[1][j];
            w=edge[2][j];
            if(dist[u]+w<dist[v]){
                printf("VISITING %d from %d (%d -> %d)\n", u, v, dist[v], w+dist[u]);
                dist[v]=dist[u]+w;
            }
        }
        printArr(dist, n);            
    }

    for(j=0;j<ne;j++){
        u=edge[0][j];
        v=edge[1][j];
        w=edge[2][j];
        if(dist[u]+w<dist[v]){
            printf("GRAPH CONTAINS NEGATIVE CYCLE\n");
            return;
        }
    }
    printArr(dist, n);    

}

int main(){
    int n, graph[100][100], src;
    printf("BELLMAN FORD'S ALGORITHM\n");
    printf("enter number of vertices: ");
    scanf("%d",&n);

    printf("enter adjacency matrix(0 for no edge):\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("enter source index:\n");
    scanf("%d",&src);
    printGraph(graph, n);
    bellmanFord(graph, src, n);
    return 0;
}