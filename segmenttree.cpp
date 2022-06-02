#include<bits/stdc++.h>
using namespace std;

// Segment tree for the max
class SGTree{
    vector <int> seg;
    public:
    SGTree(int n){
       seg.resize(4*n+1);
    }

    void build(int ind,int low,int high,vector<int> a){
        if(low==high){
            seg[ind]=a[low];
            return;
        }
        int mid=(high-low)/2+low;
        build(2*ind+1,low,mid,a);
        build(2*ind+2,mid+1,high,a);
        seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
    }

    int query(int ind,int low,int high,int l,int r){
        // Complete overlap condition
        if(low>=l && high<=r){
            return seg[ind];
        }

        // No overlap condition
        if(high<l || low>r) return INT_MIN;

        // Partial overlap
        int mid = (high-low)/2+low;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return max(left,right);
    }

    void update(int ind, int low, int high, int i, int val){
        if(low==high){
            seg[ind]=val;
            return;
        }

        int mid = (high-low)/2+ low;
        if(i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);

        seg[ind] = max(seg[2*ind+1],seg[2*ind+1]);
    }
};


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SGTree sq1(n);
    sq1.build(0,0,n-1,a);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
           int l,r;
           cin>>l>>r;
           cout<<sq1.query(0,0,n-1,l,r)<<"\n";
        }
        else{
           int i,val;
           cin>>i>>val;
           sq1.update(0,0,n-1,i,val);
        }
    }
}