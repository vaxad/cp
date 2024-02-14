#include<iostream>
#include<bitset>

using namespace std;

bool fullAdder(bool b1, bool b2, bool& carry) 
{ 
    cout<<"\n"<<b1<<b2<<carry;
    bool sum = (b1 ^ b2) ^ carry; 
    carry = (b1 && b2) || (b1 && carry) || (b2 && carry); 
    cout<<": "<<sum;
    return sum; 
} 
// Function to add two bitsets 
bitset<4> bitsetAdd(bitset<4> x, bitset<4> y) 
{
    cout<<"adding: "<<x<<", "<<y;
    bool carry = 0; 
    // bitset to store the sum of the two bitsets 
    bitset<4> ans; 
    for (int i = 0; i < 4; i++) { 
        ans[i] = fullAdder(x[i], y[i], carry); 
    }
    cout<<"answer"<<ans<<endl;
    return ans; 
} 
void division(bitset<4> m, bitset<4> q){
    int n = 4;
    bitset<4>  a(0);
    bitset<4> temp(1);
    bitwise<4> mcomp = ~m;
    cout<<mcomp;
    while(n>0){
        a<<=1;
        a[0]=q[3];
        q<<=1;
        cout<<"\n"<<a<<", "<<q<<", "<<bitsetAdd((~m),temp)<<", "<<~m;
        a = bitsetAdd(a, bitsetAdd((~m),temp));
        cout<<"\n"<<a<<"\n"<<q<<"\n";
        if(a[3]==0){
            q[0]=1;
        }else{
            q[0]=0;
            a = bitsetAdd(a,m);
        }
        n--;
    }
    cout<<"\n"<<a<<"\n"<<q;
}
// 1101
// 1001

int main(){
    int temp;
    cout<<"enter dividend:";
    cin>>temp;
    bitset<4> dividend(temp);
    cout<<"enter divisor:";
    cin>>temp;
    bitset<4> divisor(temp);
    division(dividend, divisor);
    
    return 0;
}