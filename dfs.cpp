#include<bits/stdc++.h>
using namespace std;


class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node);     // DFS Logic
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> storeDfs; 
	    vector<int> vis(V+1, 0); 
      for(int i = 1;i<=V;i++) {
        if(!vis[i]) dfs(i, vis, adj, storeDfs); 
      }
	    return storeDfs; 
	}
};

// This is the base code.... now this can be changed according to requirements
void dfs(int v,vector<int> &vis, vector<int> adj[]){
	// Print statement or store it...
	vis[v]=1;
	for(auto i: adj[v]){
		if(!vis[i]){
			dfs(i,vis,adj);
		}
	}
}

// To count no of Connected Components
// void cc(int n){
// 	int cc=0;
// 	for(int i=1;i<=n;i++){
//         if(!vis[i]){
// 			dfs(i);
// 			cc++;
// 		}
// 	}
// }

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends