#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

void KMP(string pat, string text){
    int n = text.size();
    int m = pat.size();
    vector<int> lps(m,0);
    int i=1, len=0,j;
    while(i<lps.size()){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else if(len!=0){
            len = lps[len-1];
        }
        else{
            lps[i]=0;
            i++;
        }
    }
    for(auto k:lps) cout<<k<<" ";
    cout<<"\n";
    i=0;      // For haystack
    j=0;      // For needle
    while(i<n){
        if(text[i] == pat[j]){
            i++; j++;
        }
        else if(j==0){
            i++;
        }
        else{
            j = lps[j-1];
        }
        //cout<<i<<" "<<j<<" ";
        if(j == m){
            cout<<"Index found at : "<<i-j<<"\n";
            j = lps[j-1];
        }
    }
}

int main(){
    string s,t;
    cin>>s>>t;
    KMP(s,t);
    return 0;
}


void kmp(string text,string pat){
    int n = text.length();
    int m = pat.length();
    vector<int> lps(m,0);

    int i=1, len=0;
    while(i<m){
        if(pat[i]=pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else if(len!=0){
            len = lps[len-1];
        }
        else{
            lps[i]=0;
            i++;
        }
    }

    i=0;
    int j=0;
    while(i<n){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        else if(j!=0){
            j = lps[j-1];
        }
        else{
            i++;
        }

        if(j==m){
            cout<<"Index found at : "<<i-j<<"\n";
            j = lps[j-1];
        }
    }
}