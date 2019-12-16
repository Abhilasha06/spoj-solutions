#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long int ull;
#define pb push_back
#define mp make_pair
#define iso ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int> adj[1000005];
int ch[1000005],level[1000005],vis[1000005],cnt=0;
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
/////////////////////////////////

int bfs(int s,int l)
{
    int i;
   queue<int>q;


   if(ch[s]!=s&&ch[s]!=0)
   {
       return -1;
   }
   q.push(s);
   level[s]=0;

   ch[s]=s;

   while(!q.empty())
   {
       int st=q.front();
       q.pop();
       for(i=0;i<adj[st].size();i++)
       {


               if(ch[adj[st][i]]==s)
               {
                   continue;
               }
               else if(ch[adj[st][i]]!=s&&ch[adj[st][i]]!=0)
               {
                   return -1;
               }

               else
               {
                    level[adj[st][i]]=level[st]+1;
                if(level[adj[st][i]]<=l)
                {


                q.push(adj[st][i]);

                ch[adj[st][i]]=s;
                }
                else
                    break;

               }
               //cout<<adj[st][i]<<" "<<level[adj[st][i]]];

   }
   }
   return 0;

}



int main()
{
    iso;
    int t;
    cin>>t;
    while(t--)
    {

        //adj.clear();
        int n,r,m,a,b,i,flag=1;
        cin>>n>>r>>m;
        for(i=0;i<=1000000;i++)
        {


            ch[i]=0;
            level[i]=0;
            adj[i].clear();
        }
        for(i=0;i<r;i++)
        {
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);

        }
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            if(b==0)
            {
                if(ch[a]!=a&&ch[a]!=0)
                 flag=0;
                 else
                    ch[a]=a;


            }

            else
            {
            int p=bfs(a,b);
            if(p==-1)
                flag=0;
            }


        }

        if(flag==0)
            cout<<"No\n";
        else
        {
            for(i=1;i<=n;i++)
            {
                if(ch[i]==0)
                {
                flag=0;
                break;

                }

            }
            if(flag==1)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }


    }
    return 0;
}
