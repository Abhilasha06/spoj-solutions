#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > v;
int bfs(int x,int y,int a,int b)
{
    bool vis[9][9];int i,j;
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++)
         vis[i][j]=false;

     pair<int,int> p;
     queue< pair<int,int> >q;
    int cnt=0;
    q.push(make_pair(x,y));
    q.push(make_pair(0,0));
    vis[x][y]=true;
    while(q.size()>1)
    {
        p=q.front();
        q.pop();
        if(vis[a][b]==true)
            break;
        if(p.first==0&&p.second==0)
            {
                cnt++;
                q.push(make_pair(0,0));
                continue;
            }


            for( i=0;i< 9;i++)
            {int g=v[i].first+p.first,h=v[i].second+p.second;
                if((g>=1)&&(g<=8)&&(h>=1)&&(h<=8))
                    {
                        if(!vis[g][h])
                        {
                            vis[g][h]=true;
                            q.push(make_pair(g,h));
                        }
                    }
            }

    }return cnt;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t,x,y,a,b;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        x=s1[0]-'a'+1;
        y=s1[1]-'0';
        a=s2[0]-'a'+1;
        b=s2[1]-'0';

        v.push_back(make_pair(1,2));
         v.push_back(make_pair(2,1));
          v.push_back(make_pair(-1,-2));
           v.push_back(make_pair(-2,-1));
            v.push_back(make_pair(-1,2));
             v.push_back(make_pair(2,-1));
              v.push_back(make_pair(-2,1));
               v.push_back(make_pair(1,-2));

        if(x==a&&y==b)
            cout<<"0\n";

        else
        cout<<bfs(x,y,a,b)+1<<"\n";



    }
    return 0;
}

