#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int a,int b,int c){
        u = a;
        v = b;
        wt = c;
    }
};

bool comp(node a,node b){
    return a.wt<b.wt;
}

int findPar(int u, vector<int> &parent){
    if(u == parent[u]) return u;
    return parent[u] = findPar(parent[u],parent);
}

void unionn(int u,int v, vector<int> &parent, vector<int> &rank){
    u = findPar(u,parent);
    v = findPar(v,parent);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[u]>rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    int n, m;
    cin>> n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    sort(edges.begin(),edges.end(),comp);

    vector<int> parent[n];
    for(int i=0;i<n;i++) parent[i] = i;
    vector<int> rank(n,0);

    int cost = 0;
    vector<pair<int,int>> mst;
    for(auto it:edges){
        if(findPar(it.v,parent)!=findPar(it.u,parent)){
            cost+=it.wt;
            mst.push_back({it.v,it.u});
            unionn(it.u,it.v,parent,rank);
        }
    }
    cout << cost << endl;
    for(auto it:mst) cout<<it.first <<"-"<<it.second <<endl;
    return 0;
}