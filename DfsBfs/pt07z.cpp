#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long int ull;
#define pb push_back
#define mp make_pair
#define iso ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int> adj[100005];
int vis[100005],c=0,n,el,t,ma=0;
const ll m=1e9+7;
ll prime[100005];
void sieve()
{
    prime[0]=1;prime[1]=1;
    for(int i=2;i*i<100005;i++)
    {
        for(int j=i*2;j<100005;j+=i)
            prime[j]=1;
    }
}
ll gcd(ll a,ll b)
{

    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
////////////////////////////
void dfs(int s,int p)
{
    int i;
    vis[s]=1;
    if(p>ma)
    {
        ma=p;
        el=s;
    }

        for(i=0;i<adj[s].size();i++)
        {
            if(vis[adj[s][i]]==0)
            {
                dfs(adj[s][i],p+1);
            }

        }



}



int main()
{
    iso;
    int a,b,i;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);

    }
    dfs(1,0);

    for(i=1;i<=n;i++)
        vis[i]=0;
    dfs(el,0);
    cout<<ma;

    return 0;
}
