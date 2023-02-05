#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

class SGTree{
    
    public:
    vector<ll> seg;
    SGTree(ll n){
        seg.resize(4*n+1);
    }

    void buildTree(ll ind,ll low,ll high, vector<ll> &a){
        //cout<<low<<" "<<high<<"\n";
        if(low == high){
            seg[ind] = a[low];
            return;
        }
        ll mid = (high - low)/2 + low;
        buildTree(2*ind+1,low,mid,a);
        buildTree(2*ind+2,mid+1,high,a);
        seg[ind] = 0;
    }

    void update(ll ind,ll low,ll high,ll l,ll r,int u){
        if(l<=low && high<=r){
            seg[ind]+=u;
            return;
        }
        if(high<l || r<low) return;
        ll mid = (high-low)/2 + low;
        if(low!=l) update(2*ind+1,low,mid,l,r,u);
        if(high!=r) update(2*ind+2,mid+1,high,l,r,u);
    }

    ll query(ll ind,ll low, ll high,ll i){
        if(low==high&& high==i) return seg[ind];
        if(low==high && low!=i) return 0;
        if(i<low || high<i) return 0;
        ll mid = (high-low)/2 + low;
        //cout<<low<<" "<<high<<" "<<mid<<"\n";
        ll left = query(2*ind+1,low,mid,i);
        ll right = query(2*ind+2,mid+1,high,i);
        //cout<<left<<" "<<right<<" "<<low<<" "<<high<<"\n";
        return left+right+seg[ind];
    }
};

int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n,0);
    for(ll i = 0;i<n;i++){
        cin>>a[i];
    }
    SGTree seg(n);
    seg.buildTree(0,0,n-1,a);
    //for(auto i:seg.seg) cout<<i<<" ";
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
           int l,r,u;
           cin>>l>>r>>u;
           seg.update(0,0,n-1,l-1,r-1,u);
        }
        else{
           int i;
           cin>>i;
           cout<<seg.query(0,0,n-1,i-1)<<"\n";
        }
    }
}