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
#define GCJ ll t;cin>>t;for(ll H=1;H<=t;H++){cout<<"CASE #"<<H<<": ";solve();}
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
#define revrep(n,i) for(ll i=n-1;i>=0;i--)
#define crevrep(n,x,i) for(ll i=n-1;i>=x;i--)
#define ss second
#define ff first
#define incr(x,y) x=max(x, y)
#define decr(x,y) x=min(x, y)
#define pb push_back
void USACO(string s){fast;freopen((s+".in").c_str(),"r",stdin);freopen((s+".out").c_str(),"w",stdout);}
 
const ll MAXN = 100100;
 
 
 
int dp[510][510];
 
int recur(int a, int b)
{
    if(dp[a][b]!=-1)
    {
        return dp[a][b];
    }
    if(dp[b][a]!=-1)
    {
        dp[a][b]=dp[b][a];
        return dp[a][b];
    }
    if(a==b)
    {
        dp[a][b]=0;
        return 0;
    }
    dp[a][b]=1e9;
    
    for(int i=1;i<a;i++)
    {
        dp[a][b]=min(dp[a][b], recur(a-i, b)+recur(i, b)+1);
    }
    for(int i=1;i<b;i++)
    {
        dp[a][b]=min(dp[a][b], recur(a, b-i)+1+recur(a, i));
    }
    
    
    
    return dp[b][a]=dp[a][b];
}
 
 
void solve()
{
    
    //USACO("boards");
    memset(dp, -1, sizeof(dp));
    int a, b;
    cin>>a>>b;
    cout<<recur(a, b)<<endl;
    
    
}
 
int main()
{
    
    
    fast;
    
 
    
    // tcase
    solve();
    
    
}
