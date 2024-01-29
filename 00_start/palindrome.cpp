class Solution {
public:
    long long reverse(int n){
        long long rev=0;
        while(n!=0){
            rev=rev*10+(n%10);
            n=n/10;
        }
        return rev;
    }
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int rev = reverse(x);
        return rev==x;
    }
};