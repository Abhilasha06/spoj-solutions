#include<bits/stdc++.h>
using namespace std;
int vis[100007];
vector<int>adj[1000007];
void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++)
    {
        if(vis[adj[s][i]]==0)
            dfs(adj[s][i]);

    }
}
int main()
{
    int t,n,e,a,i,b,c;
    cin>>t;
    while(t--)
    {
        c=0;
        cin>>n>>e;
        for(i=0;i<n;i++)
        {
            vis[i]=0;
            adj[i].clear();
        }
        for(i=0;i<e;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);

        }
        for(i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                c++;
                dfs(i);
            }
        }
        cout<<c<<"\n";

    }
    return 0;
}

