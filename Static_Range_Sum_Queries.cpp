#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1,0),pre(n+1,0);

    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<"\n";
    }
}