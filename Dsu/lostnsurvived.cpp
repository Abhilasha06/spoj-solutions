#include<bits/stdc++.h>

using namespace std;

#define iso ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef long long ll;

typedef unsigned long long ull;

#define pb push_back

#define mp make_pair

#define mod 1000000007

int Size[100005], arr[100005];
multiset<int> s;
void initialize(int N)

{

    for(int i = 1;i<=N;i++)

    {

        arr[ i ] = i ;

        Size[ i ] = 1;

    }

}



int root (int i)

{

    while(arr[ i ] != i)

    {

        arr[ i ] = arr[ arr[ i ] ] ;

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

     s.erase(s.find(Size[root(A)]));
     s.erase(s.find(Size[root(B)]));

    if(Size[root_A] < Size[root_B ])

    {

        arr[ root_A ] = arr[root_B];

        Size[root_B] += Size[root_A];
        s.insert(Size[root_B]);

    }

    else

    {

        arr[ root_B ] = arr[root_A];

        Size[root_A] += Size[root_B];
        s.insert(Size[root_A]);



    }

}



int main()

{

    iso;

    long n,m,q,a,b,ones,i;



    cin>>n;

    cin>>q;

    initialize(n);
    for(int i=0;i<n;i++)
    {
        s.insert(1);
    }


    while(q--)

    {

        cin>>a>>b;

        if(Find(a,b)==false)
        {
            Union(a,b);

        }

        cout<<*s.rbegin()-*s.begin()<<"\n";
    }

    return 0;

}
