
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int arr[3][2]= {{100, 20}, {120, 30},{60, 10}};
    int w = 50;
    double ratio[3];
    int max=-1;
    for(int i = 0; i < 3; i++ ){
        ratio[i]=(double)arr[i][0]/(double)arr[i][1];
    }
    for(int i=0; i<3; i++){
        for(int j=i;j<3;j++){
            if(ratio[j]>ratio[i]){
                int temp[2] = {arr[j][0],arr[j][1]};
                arr[j][0]=arr[i][0];
                arr[j][1]=arr[i][1];
                arr[i][0]=temp[0];
                arr[i][1]=temp[1];
            }
        }
    }
    int profit = 0;
    for(int i = 0; i < 3; i++ ){
        if(arr[i][1]<=w){
            w-=arr[i][1];
            profit+=arr[i][0];
            cout<<profit<<", "<<w<<endl;
        }else{
            profit+=((double)w/(double)arr[i][1])*arr[i][0];
            w=0;
            cout<<profit<<", "<<w<<endl;
        }
        cout<<arr[i][0]<<", "<<arr[i][1]<<", ratio:"<<ratio[i]<<endl;
    }
    cout<<"weight: "<<w<<"profit: "<<profit;
    return 0;
}