class Solution {
public:
    int min(int a, int b){
        return a<=b?a:b;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string arr=strs[0];
        int ctr = strs[0].length();
        for(auto it=strs.begin(); it!=strs.end(); ++it ){
            string s=*it;
            if(s==""){
                return "";
            }
            ctr=min(ctr,s.length());
            for(int i=0;i<s.length();i++){
                if(s[i]!=arr[i]){
                    arr[i]='\0';
                    ctr=min(i,ctr);
                }
            }
        }
        char arr2[strs[0].length()+1];
        for(int i=0;i<ctr;i++){
            arr2[i]=strs[0][i];
        }
        arr2[ctr]='\0';
        return arr2;
    }
};