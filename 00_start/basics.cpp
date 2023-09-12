#include<bits/stdc++.h>

using namespace std;

void func (string sample){
    sample[0]='x';
    cout<<sample<<endl;
}
void funcref (string &sample){
    sample[0]='x';
    cout<<sample<<endl;
}
int main() {
    string str;
    getline(cin,str);
    cout<<"entered string is: "<<str<<endl;
    int x;
    cin>>x;
    if(x<18){
        cout<<"kiddo\n";
    }else{
        cout<<"biggie\n";
    }
    if(x<35){
        cout<<"C";
    }else if(x<55){
        cout<<"B";
    }else if(x<75){
        cout<<"A";
    }else if(x<85){

        cout<<"A+";
    }else if(x<95){
        cout<<"O";
    }else{
        cout<<"top";
    } 
    cout<<endl;
    switch(x/10){
        case 1:
        cout<<"10s";
        break;
        case 2:
        cout<<"20s";
        break;
        case 3:
        cout<<"30s";
        break;
        case 4:
        cout<<"40s";
        break;
        case 5:
        cout<<"50s";
        break;
        case 6:
        cout<<"60s";
        break;
        case 7:
        cout<<"70s";
        break;
        default:
        cout<<"above 80";
    }
    string arr="varad";
    for (int i=0;i<arr.size();i++){
        cout<<"enter element at "<<i<<" th position";
        cin>>arr[i];
    }
    cout<<arr<<endl;
    func(arr);
    cout<<arr<<endl;
    funcref(arr);
    cout<<arr<<endl;
    return 0;
}
