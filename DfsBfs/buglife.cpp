#include<bits/stdc++.h>
using namespace std;
int prime[100005],vis[100005],dist[100005];
void sieve()
{
    prime[0]=1;prime[1]=1;
    for(int i=2;i*i<100005;i++)
    {
        for(int j=i*2;j<100005;j+=i)
            prime[j]=1;
    }
}

int main()
{
    sieve();
    int t,a,b,dig[4],i,j,c,num;
    cin>>t;
    while(t--)
    {
        for(i=0;i<100005;i++)
        {
            vis[i]=0;
            dist[i]=-1;
        }

        queue<int> q;
        cin>>a>>b;


        q.push(a);
        vis[a]=1;
        dist[a]=0;
        while(!q.empty())
        {
            int x=q.front();

        for(i=0;i<=3;i++)
        {
             c=x;
        dig[3]=c%10;
        c/=10;
        dig[2]=c%10;
        c/=10;
        dig[1]=c%10;
        c/=10;
        dig[0]=c%10;
            for(j=0;j<=9;j++)
            {
                dig[i]=j;
                num=dig[0]*1000+dig[1]*100+dig[2]*10+dig[3];

                if(num>=1000&&prime[num]==0&&vis[num]==0)
                {
                    vis[num]=1;
                    dist[num]=dist[x]+1;
                    q.push(num);
                }

            }
        }

        q.pop();
        }
        if(dist[b]!=-1)
            cout<<dist[b]<<"\n";
        else
            cout<<"Impossible \n";

    }

    return 0;

}
