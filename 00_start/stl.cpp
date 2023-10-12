#include<bits/stdc++.h>
using namespace std;

//pairs
void examplePair(){
    pair<int, int> p1 = {1,2};
    cout<<p1.first<<", "<<p1.second<<endl;
    pair<int, string> p2 = {1,"hello"};
    cout<<p2.first<<", "<<p2.second<<endl;
    pair<int, pair<int, int>> p3 = {1,{2,3}};
    cout<<p3.first<<", "<<p3.second.first<<", "<<p3.second.second<<endl;
    pair <int, string> p_arr[] = {{1,"varad"},{2,"siddhant"},{3,"tirath"}};
    cout<<p_arr[0].first<<", "<<p_arr[0].second<<", "<<p_arr[1].first<<endl;
}

void exampleVector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);  //faster

    vector<pair<int,int>> v_pair;
    v_pair.push_back({1,2});
    v_pair.emplace_back(3,4);   //{} not needed in emplace_back

    vector<int> v2(5,100);  //declaresa a container: {100,100,100,100,100}, 5 is resizable

    vector<int> v3(3);  //{0,0,0}

    vector<int> v4(v3); //copies

    cout<<v[0]<<", "<<v.at(0)<<endl;

    cout<<v.back()<<endl;

}
int main(){
    cout<<"hello g\n";
    //examplePair();
    exampleVector();
    return 0;
}