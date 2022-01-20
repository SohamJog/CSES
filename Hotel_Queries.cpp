
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



//WALKING ON A SEGMENT TREE


struct segtree
{
    ll tree[MAXN*4];
    
    
    void buildTree( ll node, ll start, ll end)
    {
        if(start == end)
        {
            return;
        }
        ll mid = (start + end)/2;
        buildTree( 2*node, start, mid);
        buildTree(  2*node + 1, mid + 1, end);
        tree[node] = max(tree[node*2],tree[node*2 + 1]);
    }
    
    
    
    void update(ll node, ll start, ll end, ll l, ll val)
    {

        if(l > end || l < start || start > end){return;}

        if(l<=start&&l>=end)
        {
            tree[node]+=(end-start+1)*val;
            
            return;
        }
        
        ll mid=(start+end)/2;
        update(node*2, start, mid, l, val);
        update(node*2+1, mid+1, end, l, val);
        
        tree[node]=max(tree[node*2], tree[node*2+1]);

    }
    
    //walk
    
    ll query(ll node, ll start, ll end, ll val)
    {
        
        
        if(start==end)
        {
            if(tree[node]<val)return 0;
            return start+1;
        }
        
        ll mid = (start + end)/2;
        
        if(tree[2*node]>=val)
        {
            return query(2*node, start, mid, val);
        }
        if(tree[2*node+1]>=val)
        {
            return query(2*node+1, mid+1, end, val);
        }
        return 0;
        
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
        S.update(1, 0, n-1, i, x);
    }
    
    while(q--)
    {
        ll x;
        cin>>x;
      

        ll lel=S.query(1, 0, n-1, x);
        cout<<lel<<" ";
        if(lel)
        {
            lel--;
            S.update(1, 0, n-1, lel, -x);
        }
    }
    cout<<endl;
    

    
}
    




int main()
{
    
    fast;
    //tcase
        solve();
    
    
    
}







