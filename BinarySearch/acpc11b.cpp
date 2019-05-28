#include<bits/stdc++.h>
using namespace std;
int calc(int n1,int n2,int arr1[],int arr2[]);
int main()
{
    int t,n1,n2,i,j,k;
    cin>>t;
    int res[t];
    for(i=0;i<t;i++)
    {
        cin>>n1;
        int arr1[n1];
        for(j=0;j<n1;j++)
            cin>>arr1[j];
        cin>>n2;
        int arr2[n2];
        for(k=0;k<n2;k++)
            cin>>arr2[k];

        if(n2>=n1)
        res[i]=calc(n1,n2,arr1,arr2);
        else
            res[i]=calc(n2,n1,arr2,arr1);
    }
    for(i=0;i<t;i++)
        cout<<res[i]<<"\n";
    return 0;
}
int calc(int n1,int n2,int arr1[],int arr2[])
{   int flag=1,mini=1000000,i;
sort(arr1,arr1+n1);
        sort(arr2,arr2+n2);
        for(i=0;i<n2;i++)
        {
            int ns=arr2[i];
            int beg=0,en=n1-1,mid;
            while(beg<=en)
            {
                mid=(beg+en)/2;
                if(ns>arr1[mid])
                {
                   beg=mid+1;
                   if(abs(ns-arr1[mid])<mini)
                        mini=abs(ns-arr1[mid]);

                }
                else if(ns==arr1[mid])
                {
                    mini=0;
                    flag=0;
                    break;
                }
                else
                {
                    en=mid-1;
                    if(abs(arr1[mid]-ns)<mini)
                        mini=abs(ns-arr1[mid]);
                }
            }
            if(flag==0)
                break;
        }
    return mini;
}
