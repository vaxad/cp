#include <bits/stdc++.h>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int d1=0,d2=0;
    cout<<arr.size();
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<"\n";
            if(i==j){
                d1+=arr[i][j];
                cout<<"d1:"<<d1<<endl;
            }
            if(j==arr[i].size()-1-i){
                d2+=arr[i][j];
                cout<<"d2:"<<d2<<endl;

            }
        }
    }
    return d1-d2<0?d2-d1:d1-d2;
}

int main(){
    cout<<"hii";
    vector<int> a1 = {11, 2, 4};
    vector<int> a2 = {4, 5, 6};
    vector<int> a3 = {10, 8, -12};
    vector<vector<int>> arr={a1,a2,a3};
    int x=diagonalDifference(arr);
    cout<<x;
    cout<<"end";
    return 0;
}
