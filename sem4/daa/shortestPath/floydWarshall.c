#include<stdio.h>
#include<stdbool.h>

int i,j,k,l;

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

int min(int a, int b){
    return a<b?a:b;
}
void floydwarshall(int graph[100][100],int n){
    bool visited[100];
    int dist[100][100];
    int prev=0;

    for(i=0;i<n;i++){
        visited[i]=false;
        for(j=0;j<n;j++){
            dist[i][j]=(i==j?0:(graph[i][j]?graph[i][j]:999));  //INF
        }
    }
    // all vertex se all vertex tak 0->[0 , 3, 8] 1->[9, 0, 3] 2->[1, 4, 0]
    printGraph(dist, n);
    // 3->4 (12) (3->1 [4] 1->4 [6]) 
    k=0;
    while(k<n){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                dist[i][k]=min(dist[i][k], dist[i][j]+dist[j][k]);
            }
        }
        k++;
    }

    printGraph(dist, n);
}

int main(){
    int n, graph[100][100], src;
    printf("FLOYD WARSHALL'S ALGORITHM\n");
    printf("enter number of vertices: ");
    scanf("%d",&n);

    printf("enter adjacency matrix(0 for no edge):\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printGraph(graph, n);
    floydwarshall(graph, n);
    return 0;
}