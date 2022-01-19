
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



const ll MAXN =2000;
const ll mod = 1000000007;




void solve()
{

    ll n;
    cin>>n;

    ll a[n];
    rep(i,n)cin>>a[i];
    
    vector<vii>dp;          //{odd player, even player}
    dp.resize(n);
    rep(i,n)
    {
        dp[i].resize(n);
    }
    
    
    
    for(ll diff=0;diff<n;diff++)
    {
        for(ll i=0;i+diff<n;i++)
        {
            ll l=i, r=i+diff;
            if(diff==0)
            {
                dp[l][r].first=a[l];continue;
            }
            bool p=(diff+1)%2;
            if(p)
            {
                
                if(dp[l+1][r].ff+a[l]>dp[l][r-1].first+a[r])
                {
                    dp[l][r].first=dp[l+1][r].ff+a[l];
                    dp[l][r].second=dp[l+1][r].ss;
                }
                if(dp[l+1][r].ff+a[l]<dp[l][r-1].first+a[r])
                {
                    dp[l][r].first=dp[l][r-1].first+a[r];
                    dp[l][r].ss=dp[l][r-1].ss;
                }
                if(dp[l+1][r].ff+a[l]==dp[l][r-1].first+a[r])
                {
                    dp[l][r].first=dp[l][r-1].first+a[r];
                    dp[l][r].ss=max(dp[l+1][r].ss, dp[l][r-1].ss);
                }

            }
            else
            {
                if(dp[l+1][r].ss+a[l]>dp[l][r-1].ss+a[r])
                {
                    dp[l][r].ss=dp[l+1][r].ss+a[l];
                    dp[l][r].ff=dp[l+1][r].ff;
                }
                if(dp[l+1][r].ss+a[l]<dp[l][r-1].ss+a[r])
                {
                    dp[l][r].ss=dp[l][r-1].ss+a[r];
                    dp[l][r].ff=dp[l][r-1].ff;
                }
                if(dp[l+1][r].ss+a[l]==dp[l][r-1].ss+a[r])
                {
                    dp[l][r].ss=dp[l][r-1].ss+a[r];
                    dp[l][r].ff=max(dp[l+1][r].ff, dp[l][r-1].ff);
                }
                
            }
            
            
        }
    }
    
    if(n%2)
    {
        cout<<dp[0][n-1].ff<<endl;
    }
    else
    {
        cout<<dp[0][n-1].ss<<endl;
    }
    
}
    




int main()
{
    
    fast;
    //tcase
        solve();
    
    
    
}







