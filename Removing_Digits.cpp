 
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
 
 
 
void USACO(string s) {
    fast;
    
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
 
int dp[1000010]={0};
int n;
 
 
int recur(int x)
{
    if(x<0)
    {
        return 1e9;
    }
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    if(x==0)
    {
        dp[x]=0;
        return 0;
    }
    dp[x]=1e9;
    int temp=x;
    while(temp)
    {
        if(temp%10)
        {
            dp[x]=min(dp[x], 1+recur(x-(temp%10)));
        }
        temp/=10;
    }
    
    return dp[x];
}
 
void solve()
{
   // USACO("promote");
    memset(dp, -1, sizeof(dp));
    cin>>n;
    cout<<recur(n)<<endl;
 
}
 
int main()
{
    fast;
   // tcase
        solve();
    
}
 
 
