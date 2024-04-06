#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& v){
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

void printMatrixVector(vector<vector<int>>& v){
    for(auto i:v){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int calcSum(vector<int> v,auto  start, auto end){
    int currSum = 0;
    printVector(v);
    for(auto i=start;i!=end;i++){
        currSum+=*i;
    }
    cout<<"sum: "<<currSum<<endl;
    return currSum;
}
int getLongestSubarray(vector<int>& nums, int k){
     // Write your code here
    int max=0;
    // vector<vector<int>> v;
    for (auto i = nums.begin(); i < nums.end(); i++) {
      for (auto j = i+1; j <= nums.end(); j++){
        //   vector<int> temp (i,j);
          if(calcSum(nums,i,j)==k){
              if(j-i>max)max=j-i;
          }
      }
    }
    return max;
}
int justGreater(vector<int> v, auto ind){
        cout<<"finding just greater than "<<v[ind]<<endl;
        int minInd=ind+1;
        for(auto i=ind+1;i<v.size();i++){
            cout<<" checking "<<v[i]<<endl;

            if(v[i]>v[ind]&&v[i]<v[minInd]){
                minInd=i;
            }
        }
        return minInd;
    }
    void nextPermutation(vector<int>& nums) {
        int breakPoint = -1;
        for(int i=nums.size()-2;i>=0;--i){
            cout<<" checking "<<nums[i]<<endl;
            if(nums[i]<nums[i+1]){
                breakPoint=i;
                cout<<"(BREAKPOINT "<<nums[i]<<")\n";
                break;
            }
        }
        if(breakPoint==-1){
            cout<<"Reversing!\n";
            reverse(nums.begin(),nums.end());
            printVector(nums);
        }else{
            int justGreaterInd = justGreater(nums,breakPoint);
            cout<<"swapping "<<nums[breakPoint]<<" and "<<nums[justGreaterInd]<<endl;
            swap(nums[breakPoint],nums[justGreaterInd]);
            reverse(nums.begin()+breakPoint+1,nums.end());
            printVector(nums);

        }
    }

    void makeRowZero(vector<int>& row){
        cout<<"making this row zero: ";
        printVector(row);
        for(int i=0;i<row.size();i++){
            row[i]=0;
        }
    }
    void makeColumnZero(vector<vector<int>>& rows,int n){
        cout<<"making this col zero: ";
        for(int i=0;i<rows.size();i++){
            cout<<rows[i][n]<<" ";
            rows[i][n]=0;
        }
        cout<<endl;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeroes;
        printMatrixVector(matrix);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    zeroes.push_back({i,j});
                }
            }
        }
        printMatrixVector(zeroes);
        for(auto i:zeroes){
            makeRowZero(matrix[i[0]]);
            makeColumnZero(matrix,i[1]);
        }
        printMatrixVector(matrix);
    }

void testVector(){
    // vector<int> v {1,2,3,4,5,6,7}; //declaring
    // //v.push_back(4);      // insert at end
    // //v.emplace(v.begin(), 1);     //insert at start
    // printVector(v);
    // vector<int> v1(v.end()-3,v.end());    //copy a vector
    // vector<int> v2(v.begin(),v.end()-3);
    // printVector(v1);
    // printVector(v2);
    // v1.insert(v1.end(), v2.begin(), v2.end());  //merging
    // printVector(v1);
    // for (auto i = v.begin(); i < v.end(); i++) {
    //   for (auto j = i+1; j < v.end(); j++){
    //       vector<int> temp (i,j);
    //       printVector(temp);
    //   }
    // }
    // vector<int> t{-1, 1, 1};
    // getLongestSubarray(t,1);
    // vector<int> v {1,3,2};
    // printVector(v);
    // nextPermutation(v);
    // printVector(v);
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
}

void printMap(map<int,int> &m){
    for(auto i:m){
        cout<<" ("<<i.first<<", "<<i.second<<") ";
    }
    cout<<endl;
}
void testMap(){
    map<int, int> m;
    m[2]=4;
    m[3]=5;
    m.insert(pair<int, int>(1,2));
    printMap(m);
}
int main(){
    testVector();
    //testMap();
    return 0;
}