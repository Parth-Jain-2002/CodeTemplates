#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

void dfs(int node,int parent, vector<int>&vis, vector<int> &tin,vector<int> &low,
         int &timer, vector<int> adj[]){

   vis[node] = 1;
   tin[node] = low[node] = timer++;
   for(auto it:adj[node]){
      if(it == parent) continue;

      if(!vis[it]){
         dfs(it,node,vis,tin,low,timer,adj);
         low[node] = min(low[node],low[it]);
         if(low[it]>tin[node]){
            cout<<node<<" "<<it<<endl;
         }
      }
      else{
         low[node] = min(low[node],tin[it]);
      }
   }
}