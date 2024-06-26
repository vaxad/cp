#include<iostream>
#include<vector>
using namespace std;
void printGraph(int graph[100][100], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==999)
            cout<<"-"<<" ";
            else
            cout<<graph[i][j]<<" ";            
        }
        cout<<endl;
    }
}

void printArray(bool arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void prims(int graph[100][100], int n){
    bool visited[100] = {false};
    visited[0]=true;
    for(int k=0;k<n;k++){
        int min=999, minBox[]= {-1,-1};
        for(int i=0;i<n;i++){
            if(!visited[i])continue;
            for(int j=0;j<n;j++){
                if(visited[i]^visited[j]){
                    if(graph[i][j]<min){
                        min=graph[i][j];
                        minBox[0] = i;
                        minBox[1] = j;
                    }
                }
            }
        }
        printArray(visited, n);
        if(min==999)continue;
        if(visited[minBox[0]]){
            cout<<"VISITING VERTEX "<<minBox[1]<<" FROM "<<minBox[0]<<" WITH WEIGHT "<<graph[minBox[0]][minBox[1]]<<endl;
            visited[minBox[1]]=true;
        }else{
            cout<<"VISITING VERTEX "<<minBox[0]<<" FROM "<<minBox[1]<<" WITH WEIGHT "<<graph[minBox[0]][minBox[1]]<<endl;
            visited[minBox[0]]=true;
        }
    }
}

int main(){
    cout<<"PRIMS ALGO:\n";
    int n, graph[100][100];
    cout<<"enter number of vertices: ";
    cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         graph[i][j]=999;            
    //     }
    // }
    // 0 2 4 0
    // 3 0 87 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                int temp;
                cout<<"enter weight between vertex "<<i<<" and vertex "<<j<<"(0 if no edge): ";
                cin>>temp;
                graph[i][j]=temp==0?999:temp;
                // graph[j][i]=graph[i][j];
        }
    }
    printGraph(graph, n);
    prims(graph, n);
    return 0;
}