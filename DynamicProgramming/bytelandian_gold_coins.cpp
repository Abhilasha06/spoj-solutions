#include<bits/stdc++.h>
using namespace std;
map<long ,long long>dp;
long long rec(long n)
{
    if(n==0)
        return 0;
    if(dp[n]!=0)
        return dp[n];
    long long a=rec(n/2)+rec(n/3)+rec(n/4);
    if(a>n)
        dp[n]=a;
    else
        dp[n]=n;
    return dp[n];

}
int main()
{
    long n;long long ans;
    while(scanf("%ld",&n)==1)
        {ans=rec(n);
        cout<<ans<<"\n";}

    return 0;
}
