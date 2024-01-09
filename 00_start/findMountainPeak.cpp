#include <bits/stdc++.h>

using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
    int min=arr[0];
    int ind=0;
    int low=0;
    int high=arr.size()-1;
    int mid=low+((high-low)/2);
    while(low<high){
        cout<<mid<<","<<high<<","<<low<<endl;
        if((arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])){
            // cout<<arr[mid];
            return mid;
        }else if(arr[mid]>arr[mid-1]){
            // min=arr[mid];
            cout<<arr[mid]<<endl;
            // ind=mid;
            low=mid;
            mid=low+((high-low)/2);
            ind=mid;
        }else{
            // low=(2*mid)-high;
            // mid=low+((high-low)/2);
            cout<<arr[mid]<<endl;
            high=mid;
            mid=low+((high-low)/2);
            ind=mid;


        }
    }
    return ind;
}

int main(){
    cout<<"hii";
    vector<int> arr={3,5,3,2,0};
    int x=peakIndexInMountainArray(arr);
    cout<<x;
    cout<<"end";
    return 0;
}
