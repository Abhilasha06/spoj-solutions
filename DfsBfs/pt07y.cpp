#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100000];
int vis[100000];
void dfs(int s)
{

    vis[s]=1;
    for(int i=0;i<adj[s].size();i++)
    {
        if(vis[adj[s][i]]==1)
            continue;
        else
        {
            vis[adj[s][i]]=1;
            dfs(adj[s][i]);
        }
    }
}

int main()
{
   int m,n,a,b,i,flag=0;
   cin>>n>>m;
   for(i=0;i<m;i++)
   {
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);

   }
   dfs(1);
   if(m==n-1)
   {
       flag=1;
      for(i=2;i<=n;i++)
      {
          if(vis[i]==0)
            {flag=0;
            break;
            }
      }
   }
   if(flag==1)
    cout<<"YES";
   else
    cout<<"NO";

    return 0;
}
