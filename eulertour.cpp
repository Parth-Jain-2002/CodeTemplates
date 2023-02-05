void dfs(int node,int par){
    S[node] = timer;
    FT[timer] = node;
    timer++;

    for(auto i:adj[node]){
        if(i == par) continue;
        dfs(i,node);
    }
    
    T[node] = timer;
    FT[timer] = node;
    timer++;   // If we remove this line, this will pave the way to count elements in subtree
}