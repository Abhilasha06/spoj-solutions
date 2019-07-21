#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long int ull;
#define pb push_back
#define mp make_pair
#define iso ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

////////////////////////////
ll arr[1005][1005],vis[1005][1005],dfsc=0,c[6250005];
void bfs(ll a,ll b,ll m,ll n)
{
    queue< pair<ll,ll> >q;
    q.push(mp(a,b));
    ll cnt=0;
    ll x,y;
    //cout<<x<<" "<<y<<"\n";
    while(!q.empty())
    {

        cnt++;
        x=q.front().first;
        y=q.front().second;
        //cout<<x<<" "<<y<<"\n";
        q.pop();
        vis[x][y]=1;

        if(x+1<=m&&vis[x+1][y]==0)
        {
            if(arr[x+1][y]==1)
            vis[x+1][y]=-1,q.push(mp(x+1,y));
            else
                vis[x+1][y]=1;

        }
        if(y+1<=n&&vis[x][y+1]==0)
        {
            if(arr[x][y+1]==1)
            vis[x][y+1]=-1,q.push(mp(x,y+1));
            else
                vis[x][y+1]=1;

        }
        if(x-1>=0&&vis[x-1][y]==0)
        {
            if(arr[x-1][y]==1)
            vis[x-1][y]=-1,q.push(mp(x-1,y));
            else
                vis[x-1][y]=1;

        }
        if(y-1>=0&&vis[x][y-1]==0)
        {
            if(arr[x][y-1]==1)
            vis[x][y-1]=-1,q.push(mp(x,y-1));
            else
                vis[x][y-1]=1;

        }




    }
    c[cnt]+=1;
}
int main()
{
    iso;
    ll x,y,i,j;

    while(true)
    {
         for(i=0;i<=6250005;i++)
            c[i]=0;

        for(i=0;i<=1000;i++)
        {

            for(j=0;j<=1000;j++)
            {

                vis[i][j]=0;

            }
        }
        cin>>x;
        cin>>y;
        if(x==0&&y==0)
            break;



        for(i=1;i<=x;i++)
        {
            for(j=1;j<=y;j++)
                cin>>arr[i][j];
        }




        for(i=1;i<=x;i++)
        {

            for(j=1;j<=y;j++)
            {



              if(vis[i][j]==0&&arr[i][j]==1)
               {

                  dfsc++;
                bfs(i,j,x,y);
               }
            }
        }
        cout<<dfsc<<"\n";
            dfsc=0;
        for(i=0;i<=x*y;i++)
        {
           if(c[i]>0)
             cout<<i<<" "<<c[i]<<"\n";

        }

    }


    return 0;


}
