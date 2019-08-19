#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long int ull;
#define pb push_back
#define mp make_pair
#define iso ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
//////////////////////////////////////
int a[25],b[25];
int dp[1000][1000];
int ans,mm;
int fun(int p,int n)
{
    //cout<<p<<" "<<n<<"\n";
    if(dp[p][n]!=-1)
        return dp[p][n];
    if(p==mm)
    {
        if(n==0)
            return 1;
        return 0;

    }

    else
    {
        int x=0;

        for(int i=a[p];i<=b[p]&&n>=i;i++)
        {
            x+=fun(p+1,n-i);
        }
        dp[p][n]=x;

    }
    return dp[p][n];
}
int main()
{
    iso;
    int n,i,j;
    while(1)
    {
        for(i=0;i<1000;i++)
            for(j=0;j<1000;j++)
            dp[i][j]=-1;
        ans=0;

    cin>>mm>>n;
    if(mm==0&&n==0)
        break;
    for(int i=0;i<mm;i++)
        cin>>a[i]>>b[i];
    fun(0,n);
    cout<<dp[0][n];
    }
    return 0;
}
