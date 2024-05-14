#include<stdio.h>
#include<string.h>

int max(int a, int b){
    return a>b?a:b;
}

int lcs(char* s1, char* s2, int i, int j){
    if(s1[i]==0 || s2[j]==0)return 0;
    if(s1[i] == s2[j])return  (1+ lcs(s1, s2, i+1, j+1));
    else return max(lcs(s1,s2,i+1,j), lcs(s1, s2, i, j+1));
}

int main(){
    int n;
    char s1[100], s2[100];
    printf("LCS:\n");
    printf("enter string 1: ");
    scanf("%s",s1);
    printf("enter string 2: ");
    scanf("%s",s2);
    
    printf("LCS: %d\n",lcs(s1, s2, 0, 0));

    return 0;
}