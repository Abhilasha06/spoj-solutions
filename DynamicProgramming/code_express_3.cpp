#include<bits/stdc++.h>
using namespace std;
long a[100000],l[100000],m[100000];
int main ()
{
    long n,i,ans=1,j,t;
    cin>>t;
    while(t--)
    {ans=1;
    cin>>n;

    for(i=0;i<n;i++)
       {
           cin>>a[i];
           l[i]=0;m[i]=0;
       }

    l[0]=1;
    for(i=1;i<n;i++)
    {  l[i]=1;
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i]&&l[i]<l[j]+1)
            {
                l[i]=l[j]+1;
            }


        }

    }

     for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>=i;j--)
        {
            if(a[j]<a[i]&&m[i]<m[j]+1)
            {
                m[i]=m[j]+1;
            }
        }
    }

    for(i=0;i<n;i++)
    {
       if(l[i]+m[i]>=ans)
            ans=l[i]+m[i];
    }
    cout<<ans<<"\n";
    }
    return 0;
}

