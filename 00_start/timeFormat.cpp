#include <bits/stdc++.h>
using namespace std;

string timeConversion(string s) {
    int hrs = (s[0]-'0')*10+(s[1]-'0');
    int mins = (s[3]-'0')*10+(s[4]-'0');
    int secs = (s[6]-'0')*10+(s[7]-'0');
    char time = s[8];
    if(time=='P'){
        if(hrs!=12)
        hrs+=12;
    }
    char res[9];
    res[0]=((hrs/10)+'0');
    res[1]=((hrs%10)+'0');
    res[2]=':';
    res[3]=((mins/10)+'0');
    res[4]=((mins%10)+'0');
    res[5]=':';
    res[6]=((secs/10)+'0');
    res[7]=((secs%10)+'0');
    res[8]='\0';
    return res;
}

int main(){
    cout<<"hii";
    vector<int> a1 = {11, 2, 4};
    vector<int> a2 = {4, 5, 6};
    vector<int> a3 = {10, 8, -12};
    vector<vector<int>> arr={a1,a2,a3};
    string x=timeConversion("12:45:54PM");
    cout<<x;
    cout<<"end";
    return 0;
}
