#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

void dfs(int i,stack<int> &st, vector<int> &vis, vector<int> adj[]){
    vis[i]=1;
    for(auto j:adj[i]){
       if(!vis[j]){
           dfs(j,st,vis,adj);
       }
    }
    st.push(i);
}

void revDFS(int node,vector<int> &vis, vector<int> transpose[],vector<int> &component){
    component.push_back(node);
    vis[node]=1;
    for(auto it:transpose[node]){
        if(!vis[it]){
            revDFS(it,vis,transpose,component);
        }
    }

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    stack <int> st;
    vector<int> vis(n,0);
    
    // Doing dfs so to get a topological sort
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,st,vis,adj);
        }
    }
    
    // Doing transpose
    vector<int> transpose[n];
    for(int i=0;i<n;i++){
        for(auto it: adj[i]){
            transpose[it].push_back(i);
        }
    }
    
    // To reuse the list and save space
    for(int i=0;i<n;i++) vis[i]=0;
    
    // Condensation Graph
    vector<int> roots(n);
    vector<int> rootnodes;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            vector<int> component;
            revDFS(node,vis,transpose,component);
            rootnodes.push_back(component[0]);
            for(auto i:component) roots[i]=component[0];
        }
    }
    
    vector<int> condensation[n];
    for(int v=0;v<n;v++){
        for(auto u:adj[v]){
            int root_u = roots[u],root_v = roots[v];
            if(root_u!=root_v) condensation[root_v].push_back(root_u);
        }
    }

    for(auto i:rootnodes) cout<<i<<" ";
}