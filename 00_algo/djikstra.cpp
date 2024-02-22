#include <iostream>
using namespace std;
int visited[5]={0};
int cost=0;
int ctr=0;
void kruskal(int graph[4][4]){
    for (int step = 0; step < (4 - 1); step++){
        int minSrc=-1,minDest=-1 , min =100;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(graph[i][j] < min && (visited[j] == 0 || visited[i] == 0)){
                    min = graph[i][j];
                    minDest = j;
                    minSrc = i;
                }
            }

        }
        if(min==100) {
            cout << "Error no suitable edge found!" << endl;
            break;
        };
        cost+=min;
        visited[minSrc] = 1;
        visited[minDest] = 1;
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
    kruskal(graph);
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<graph[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}