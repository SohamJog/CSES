

//sort the queries in the increasing order of the ending values
//store the last occurence of every number


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
//#define endl "\n"
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
 
 
 
 
 
 
const ll MAXN =1000010;
const ll mod = 1000000007;
 
 
 
 
 
 
ll fen[2*MAXN]={0};
 
void add(ll id, ll x)
{
    for(;id<2*MAXN;id+=(id&-id))
    {
        fen[id]+=x;
    }
}
 
ll sum(ll id)
{
    ll ret=0;
    
    
    for(;id;id-=(id&(-id)))
    {
        ret+=fen[id];
    }
    
    return ret;
}
 
 
struct query {
    ll first, second, num;
    bool operator<(const query X)const
    {
         return ss<X.ss;
    }
    
};
 
bool cmp(pii a, pii b)
{
    return a.ss<b.ss;
}
 
void solve()
{
    ll n, q;cin>>n>>q;
    
    ll a[n+1];
    
    a[0]=0;
    
    rep(i,n)
    {
        cin>>a[i+1];
    }
    
    vector<query>v;
    
    rep(i,q)
    {
        ll a, b;
        cin>>a>>b;
        v.pb({a,b,i});
    }
    
    sort(all(v));
    reverse(all(v));
    
    map<ll,ll>last;
    
    crep(i,1,n+1)last[a[i]]=-1;
    
    
    ll ans[q];
    
    
    for(ll i=1;i<=n;i++)
    {
        if(last[a[i]]!=-1)
        {
            add(last[a[i]], -1);
        }
        add(i,1);
        last[a[i]]=i;
        
        while(v.back().ss==i)
        {
            ans[v.back().num]=sum(v.back().ss)-sum(v.back().ff-1);v.pop_back();
        }
    }
    
    rep(i,q)cout<<ans[i]<<endl;
    
    
    
    
}
 
 
 
 
int main()
{//
    
    fast;
    
    
    //FHC("runway_input.txt", "out.txt");
    //GCJ
    
    
    
    //tcase
    solve();
    
    
    
}
 
 
 
 
 
 
