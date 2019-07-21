#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long int ull;
#define pb push_back
#define mp make_pair
#define iso ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int vis[1000005],level[1000005],u,f,flag=0,s,g,d,x,c=0;
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
void bfs(int s)
{
    int t;
    queue <int> q;

        q.push(s);
        vis[s]=1;
        level[s]=0;
        while(!q.empty())
        {
            t=q.front();
            q.pop();



            if(t+u<=f&&vis[t+u]==0)
            {
                vis[t+u]=1;
                level[t+u]=level[t]+1;
                q.push(t+u);
            }
            if(t-d>=1&&vis[t-d]==0)
            {
                vis[t-d]=1;
                level[t-d]=level[t]+1;
                q.push(t-d);


            }

        }

}



int main()
{
    iso;

    cin>>f>>s>>g>>u>>d;
    level[g]=-1;
    bfs(s);
    if(level[g]!=-1)
        cout<<level[g]<<"\n";
    else
        cout<<"use the stairs\n";


    return 0;
}
