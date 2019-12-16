/* dsu with max neighbour size = m*/

#include<bits/stdc++.h>
using namespace std;
#define iso ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define mod 1000000007

unordered_map <string, string> st;
unordered_map <string, int> Size;

string root (string i)
{
    while(st[ i ] != i)
    {
        st[ i ] = st[ st[ i ] ] ;
        i = st[ i ];
    }
    return i;
}

void Union(string A,string B)
{
    string root_A = root(A);
    string root_B = root(B);
    if(Size[root_A] < Size[root_B ])
    {
        st[ root_A ] = st[root_B];
        Size[root_B] += Size[root_A];
    }
    else
    {
        st[ root_B ] = st[root_A];
        Size[root_A] += Size[root_B];
    }
}

int main()
{
    iso;
    int t,n,i;
    string p,q;
    cin>>t;

    while(t--)
    {

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>p>>q;
            if(st[p].length()==0)
                st[p]=p;
            if(st[q].length()==0)
                st[q]=q;
            if(Size[p]==0)
                Size[p]=1;
            if(Size[q]==0)
                Size[q]=1;

            if(root(p)!=root(q))
                Union(p,q);

            cout<<Size[root(p)]<<"\n";


        }
        st.clear();
        Size.clear();
    }
    return 0;
}
