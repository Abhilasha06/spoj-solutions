#include<bits/stdc++.h>
using namespace std;
#define iso ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define mod 1000000007
int Size[100005], arr[100005];
void initialize(int N)
{
    for(int i = 1;i<=N;i++)
    {
        arr[ i ] = i ;
        Size[ i ] = 1;
    }
}

int root(int i)
{
    while(arr[ i ] != i)
    {
     i = arr[ i ];
    }
    return i;
}

bool Find(int A,int B)
{
    if( root(A)==root(B) )
    return true;
    else
    return false;
}

void Union(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(Size[root_A] < Size[root_B ])
    {
        arr[ root_A ] = arr[root_B];
        Size[root_B] += Size[root_A];
    }
    else
    {
        arr[ root_B ] = arr[root_A];
        Size[root_A] += Size[root_B];
    }

}

int main()
{
    iso;
    long n,m,q,a,b;
    char ch;
    cin>>n>>m;
    cin>>q;
    initialize(n);
    while(q--)
    {
        cin>>ch;
        if(ch=='S')
        {
            cin>>a;
            cout<<Size[root(a)]<<"\n";

        }
        else if(ch=='A')
        {
            cin>>a>>b;
            //cout<<Size[a]+Size[b]<<"\n";
            if(Size[root(a)]+Size[root(b)]<=m)
                Union(a,b);

        }
        else
        {
            cin>>a>>b;
            if(Find(a,b))
                cout<<"Yes\n";
            else
                cout<<"No\n";


        }

    }

    return 0;
}
