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
////////////////////////////////////////////
ll dp[2005][2005];
int main()
{
    ll i,j,l1,l2, arr[26],ans=0;
    string st1,st2;
    cin>>l1>>l2;
    for(i=0;i<26;i++)
        cin>>arr[i];
    cin>>st1;
    cin>>st2;
    for(i=0;i<l1;i++)
        dp[i][0]=0;
    for(i=0;i<l2;i++)
        dp[0][i]=0;

    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            if(st1[i-1]==st2[j-1])
                dp[i][j]=dp[i-1][j-1]+arr[st1[i-1]-97];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(i=1;i<=l1;i++)
        for(j=1;j<=l2;j++)
        ans=max(ans,dp[i][j]);
    cout<<ans;
    return 0;
}
