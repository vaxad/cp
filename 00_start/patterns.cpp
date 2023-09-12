#include<bits/stdc++.h>

using namespace std;

void rectangle(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void triangle1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=n-i-1){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void numtriangle1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
void numtriangle2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
void pyramid(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=2*n;j++){
            if(j>n-i&&j<=n+i+1){
            cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
int main(){

    int n,m;
    cin>>n>>m;
    //rectangle(n,m);
    pyramid(n);
    return 0;
}