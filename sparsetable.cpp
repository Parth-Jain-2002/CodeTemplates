#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

void buildSparseTree(int n,vector<int> arr){
    for(int i=0;i<n;i++)
        table[i][0] = arr[i];

    for(int j=1, j<=log2(n);j++)
        for(int i=0;i+(1<<j)<=n;i++)
            table[i][j] = min(table[i][j-1],table[i+(1<<(j-1))][j-1])
}

void query(int l,int r){
    int j = log2(R-L+1);
    return min(table[l][j]+table[r-(1<<j)+1][j]);
}