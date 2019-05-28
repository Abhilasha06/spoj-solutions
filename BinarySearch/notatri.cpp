
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int n,i,p;
    cin>>n;
    while(n)
    {   int c=0,j,p,num;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(i=n-1;i>=2;i--)
        {
            num=a[i];
            for(j=i-1;j>=0;j--)
            {   p=num-a[j];
                int beg=0,last=j-1,mid,flag=0;
                while(beg<=last)
                    {
                        mid=(beg+last)/2;
                        if(p==a[mid]&&a[mid]!=a[mid-1])
                            {
                                flag=1;break;
                            }
                        else if(p>a[mid])
                            beg=mid+1;
                        else
                            last =mid-1;

                    }
                    if(flag==1)
                        c+=mid;
                    else
                        c+=beg;

            }

        }
        cout<<c<<"\n";

        cin>>n;
    }
    return 0;
}
