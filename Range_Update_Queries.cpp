
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include <cmath>
#include<string.h>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include<climits>
#include <iomanip>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include <cmath>
#include<string.h>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include<climits>
#include <iomanip>
#include <unordered_set>


using namespace std;



#define ll long long
#define clr(x) memset(x, 0, sizeof(x))
#define tcase ll t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define GCJ ll t;cin>>t;for(ll HtestCase=1;HtestCase<=t;HtestCase++){cout<<"Case #"<<HtestCase<<": ";solve();}
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"
//comment out the above line when coding probs which require flushing the output
#define prarr(a,n) for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
#define remDup(v) sort(all(v));v.resize(unique(all(v))-v.begin());
#define vi vector<ll>
#define pii pair<ll, ll>
#define vii vector<pii>
#define vvi vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<n;i++)
#define crep(i,x,n) for(ll i=x;i<n;i++)
#define ss second
#define ff first
#define pb push_back
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))


void USACO(string s){fast;freopen((s+".in").c_str(),"r",stdin);freopen((s+".out").c_str(),"w",stdout);}
void FHC (string s, string o){fast;freopen((s).c_str(),"r",stdin);freopen((o).c_str(),"w",stdout);}



const ll MAXN =262145;
const ll mod = 1000000007;



struct segtree
{
    ll tree[MAXN*4];
    ll delta[MAXN*4];
    
    void buildTree( ll node, ll start, ll end)
    {
        if(start == end)
        {
            return;
        }
        ll mid = (start + end)/2;
        buildTree( 2*node, start, mid);
        buildTree(  2*node + 1, mid + 1, end);
        tree[node] = tree[node*2] + tree[node*2 + 1];
    }
    
    void update(ll node, ll start, ll end, ll l, ll r, ll val)
    {
        //propagate
        if(delta[node])
        {
            tree[node]+=(end-start+1)*delta[node];
            delta[node*2]+=delta[node];
            delta[node*2 +1]+=delta[node];
            delta[node]=0;
        }
        //out of range
        if(l > end || r < start || start > end){return;}

        //fully in range
        if(l<=start&&r>=end)
        {
            tree[node]+=(end-start+1)*val;
            delta[node*2]+=val;
            delta[node*2 +1]+=val;
            
            return;
        }
        
        //partially
        ll mid=(start+end)/2;
        update(node*2, start, mid, l, r, val);
        update(node*2 +1, mid+1, end, l, r, val);

    }
    
    
    ll query(ll node, ll start, ll end, ll l, ll r)
    {
        if(delta[node])
        {
            tree[node]+=(end-start+1)*delta[node];
            delta[node*2]+=delta[node];
            delta[node*2 +1]+=delta[node];
            delta[node]=0;
        }
        
        //out of range
        if(l > end || r < start || start > end){return 0;}
        
        
        //completely in
        if(l <= start && end <= r){return tree[node];}
        
        //partially
        ll mid = (start + end)/2;
        
        ll p1 = query(2*node, start, mid, l, r);
        ll p2 = query(2*node + 1, mid + 1, end, l, r);
        return p1 + p2;
        
    }
    
    
    
}S;



void solve()
{
    ll n, q;
    cin>>n>>q;
    
    ll V=n;
    
    n=pow(2,ceil(log2(n)));
    S.buildTree(1, 0, n-1);

    
    
    rep(i,V)
    {
        int x;
        cin>>x;
        S.update(1, 0, n-1, i, i, x);
    }
    
    while(q--)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            ll a, b, val;
            cin>>a>>b>>val;
            a--,b--;
            S.update(1,0,n-1,a,b,val);
        }
        else
        {
            ll k;
            cin>>k;
            k--;
            cout<<S.query(1, 0, n-1, k, k)<<endl;
        }
        
    }
    

    
}
    




int main()
{
    
    fast;
    //tcase
        solve();
    
    
    
}







