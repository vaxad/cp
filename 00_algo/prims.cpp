
#include <iostream>
using namespace std;
int visited[5]={0};
int cost=0;
int ctr=0;
void prims(int graph[4][4]){
    visited[0]=1;
    for (int step = 0; step < (4 - 1); step++){
        int min=100, minInd = -1;
        for(int i=0;i<4;i++){
            if(visited[i]==1){
                for(int j=0;j<4;j++){
                    if(graph[i][j]<min&&visited[j]!=1){
                        min = graph[i][j];
                        minInd = j;
                        cout<<graph[i][j]<<endl;
                    }
                }
            }
        }
        cost+=min;
        visited[minInd]=1;
        cout<<"min: "<<minInd<<", "<<min<<endl;
    }
    cout<<"cost: "<<cost<<endl;
}
int main() {
    int graph[4][4] = {0};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j){
                graph[i][j]=100;
                continue;
            }
            if(graph[i][j]==0){
                cout<<"enter weight if there is an edge between node "<<i<<" and "<<j<<" (0 if not)"<<endl;
                int temp;
                cin>>temp;
                if(temp==0)
                temp=100;
                graph[i][j]=temp;
                graph[j][i]=graph[i][j];
            }
        }
    }
    prims(graph);
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<graph[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}