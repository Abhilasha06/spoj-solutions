#include<bits/stdc++.h>
using namespace std;
int main()
{
    long t,k,arr[100000],i,j,ans,mid,n,c,p,x,temp;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        for(int p=0;p<n;p++)
            cin>>arr[p];

        sort(arr,arr+n);
        i=1;
        j=1000000001;
        while(i<=j)
        {
            mid=(i+j)/2;
            x=arr[0];
            temp=1;
            for(k=1;k<n;k++)
            {
                if(arr[k]-x>=mid)
                {
                    x=arr[k];
                    temp++;
                }
            }
            if(temp<c)
              j=mid-1;
            else
            {
                ans=mid;
                i=mid+1;
            }

        }
        cout<<ans<<"\n";
    }
    return 0;
}

