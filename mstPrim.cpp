#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    
    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }

    vector<int> parent(n),key(n);
    vector<bool> mst(n);
    for(int i=0;i<n;i++){
        parent[i]=-1;
        mst[i]=false;
        key[i]=INT_MAX;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    parent[0]=-1;
    key[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(mst[node]) continue;
        mst[node]=true;

        for(auto it:adj[node]){
            if(mst[it.first]==false && it.second<key[it.first]){
                parent[it.first]=node;
                key[it.first]=it.second;
                cout<<it.first<<" "<<key[it.first]<<"\n";
                pq.push({key[it.first],it.first});
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<parent[i]<< "-"<< i <<"\n";
    }
    return 0;
}