
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

    //CPH pg 104
    
    int n, x;
    cin>>n>>x;
    int w[n];
    rep(i,n)cin>>w[i];
    vii dp;
    dp.resize((1<<n));
    
    //compute 2 values for each dp state: the min number of rides(which we have to output) and the min weight of the latest group
    
    
    
    for(int s=1;s<(1<<n);s++)
    {
        dp[s]={n+1,0};        //inf
        for(int p=0;p<n;p++)
        {
            if(!(s&(1<<p)))continue;
            
            pii option=dp[s^(1<<p)];        //s^(1<<p) is basically s minus the pth person
            
            if (option.ss+w[p]<=x)
            {
                //fits in the latest ride
                option.ss+=w[p];
            }
            else
            {
                option.ff++;
                option.ss=w[p];
            }
            
            dp[s]=min(dp[s], option);       //less rides are better than less latestRideWt
            
        }
    }
    cout<<dp[(1<<n)-1].ff+1<<endl;
    
    
    
}
    




int main()
{
    
    fast;
    //tcase
        solve();
    
    
    
}







