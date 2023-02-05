#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

// int N,M;
// vector<vector<pair<int,int>>> g;

// int dijkstra(int src,int dest){
//     vector<int> arrival(N+1,1e9);
//     vector<int> departure(N+1,1e9);
//     vector<int> visited(N+1,0);
//     arrival[src]=0;
//     set<pair<int,int>> s;
//     s.insert({0,src});
//     while(!s.empty()){
//         auto x = *(s.begin());
//         s.erase(x);
//         visited[x.second]=1;
//         departure[x.second]=arrival[x.second];
//         for(auto it: g[x.second]){
//             if(arrival[it.first]> departure[x.second]){
//                 s.erase({arrival[it.first],it.first});
//                 arrival[it.first] = departure[x.second];
//                 s.insert({arrival[it.first],it.first});
//             }
//         }
//     }
// }

const int inf = 1e9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> dis(n+1,inf);
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int src;
    cin>>src;


    // This is the implementation. We need a distance array, with all entries initialized to inf
    // Then we need a set, with first element as distance, so that it gets sorted
    // Then we doing the other stuff
    dis[src]=0;
    set<pair<int,int>>s;
    s.insert({0,src});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto it: graph[x.second]){
            if(dis[it.first]>dis[x.second]+it.second){
                s.erase({dis[it.first],it.first});
                dis[it.first]= dis[x.second]+it.second;
                s.insert({dis[it.first],it.first});
            }
        }
    }


    for(int i=1;i<=n;i++){
        if(dis[i]!=inf){
            cout<<dis[i]<<" ";
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}