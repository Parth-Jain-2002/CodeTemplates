#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int binary_lifting(int src,int par,vector<vector<int>> &up,vector<vector<int>> &tree){
    up[src][0] = par;
    for(int i = 1;i < 24; i++){
        if(up[src][i-1]!=-1)
           up[src][i]=up[up[src][i-1]][i-1];
        else up[src][i]=1;
    }

    for(int child: tree[src]){
        if(child!=src){
            binary_lifting(child,src,up,tree);
        }
    }
}

int ans_query(int node, int jump,vector<vector<int>> &up){
    if(node == -1 || jump == 0)
       return node;

    for(int i=24;i>=0;i--){
        if(jump >= (1<<i)){
            return ans_query(up[node][i],jump - (1<<i),up);
        }
    }
}

int main(){
    ll t;
    t = 1;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<vector<int>> adj(n+1);
        for(int i = 2;i<=n;i++){
            ll u; cin>>u;
            adj[u].push_back(i);
        } 
        vector<vector<int>> up(n+1,vector<int>(25,0));
        binary_lifting(1,-1,up,adj);
        while(q--){
            ll x,k;
            cin>>x>>k;
            cout<<ans_query(x,k,up)<<"\n";
        }
    }
    return 0;
}