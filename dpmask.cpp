#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    cin>>n;
    ll cost[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(1<<n,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<(1<<n);j++){
            if(i==0 && j==0){
                dp[i][j]=0;
                continue;
            }
            ll ans = INT_MAX;
            for(int k=0;k<n;k++){
                if((j & (1<<k))){
                    ans = min(ans,(ll)(cost[k][i-1]+dp[i-1][j ^ (1<<k)]));
                }
            }
            //cout<<i<<" "<<j<<" "<<ans<<"\n";
            dp[i][j]=ans;
        }
    }
    cout<<dp[n][(1<<n)-1];
    return 0;
}