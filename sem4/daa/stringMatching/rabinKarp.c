#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

int calcHash(char* s, int n){
    int sum=0;
    // printf("%s (n=%d)\n",s, n);
    for(int i=0;i<n;i++){
        sum+=((int)pow(26, n-i-1)*(s[i]-'a')); //4-0-1 26^3 ^2 ^1 ^0 a --> 0 'a'-'a' ==>0 'b'-'a'-->1
        // printf("pow:%d, sum: %d\n", (int)pow(26, n-i-1),sum);
    }
    // printf("hash for %s from 0 to %d: %d\n",s,n-1,sum);
    return sum;
}

int slideHash(int hash, char* s, int i, int n ){
    // printf("hprev: %d, leaving: %d, diff: %d\n",hash,((int)pow(26, n-1)*(s[i-1]-'a')), ((hash-((int)pow(26, n-1)*(s[i-1]-'a')))*26));
    int newHash = (hash-((int)pow(26, n-1)*(s[i-1]-'a')))*26 + (s[i+n-1]-'a');
    // printf("hash for %s from %d to %d: %d (leaving: %d, entering: %d)\n",s,i,i+n-1,newHash,s[i-1]-'a',s[i+n-1]-'a');
    return newHash;
}

int rabinKarp(char* s1, char* s2, int l1, int l2){
    if(l1<l2)return -1;
    int h2 = calcHash(s2, l2);
    int h1 = calcHash(s1, l2);
    int i=0;
    while(i<l1-l2){
        if(h1==h2)return i;
        i++;
        h1=slideHash(h1,s1,i,l2);
    }
    if(h1==h2)return i;
    return -1;
}

bool check(char* s1, char* s2, int i, int n){
    for(int j=0;j<n;j++){
        if(s1[i+j]!=s2[j])return false;
    }
    return true;
}
int main(){
    char s1[100], s2[100];
    int l1,l2;
    printf("RABIN KARP\n");
    printf("enter test string: ");
    scanf("%s",s1);
    printf("enter pattern string: ");
    scanf("%s",s2);
    l1=strlen(s1);
    l2=strlen(s2);
    int ind = rabinKarp(s1, s2, l1, l2);
    if(ind==-1)
        printf("PATTERN NOT FOUND!\n");
    else
        printf("PATTERN FOUND AT INDEX: %d\n", ind);
    return 0;
}