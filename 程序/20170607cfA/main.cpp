#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i;
        int a[1005],b[1005],c[1005];
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        int j=0,p[1005],f1,f2,ma,mb;
        for (i=0;i<n;i++)
        {
            if (a[i]==b[i])
            {
                c[i]=a[i];
            }
            else
            {
                c[i]=0;
                p[j]=i;
                j++;
            }
        }
        f1=p[0];
        f2=p[1];
        ma=a[f1];
        mb=b[f1];
        a[f1]=-1;
        if (j>1)
        {
            for (i=0;i<n;i++)
            {
                if ((ma==a[f2]&&b[f1]!=b[f2])&&ma==c[i])
                {
                    ma=b[f1];
                }
            }
            c[f1]=ma;
            for (int m=1;m<=n;m++)
            {
                int k=-1;
                for (i=0;i<n;i++)
                {
                    if (c[i]==m)
                    {
                        k=0;
                        break;
                    }
                    else
                        k=1;
                }
                if (k==1)
                {
                    c[f2]=m;
                    break;
                }

            }
        }
        else if (j==1)
        {
            for (int m=1;m<=n;m++)
            {
                int k=-1;
                for (i=0;i<n;i++)
                {
                    if (c[i]==m)
                    {
                        k=0;
                        break;
                    }
                    else
                        k=1;
                }
                if (k==1)
                {
                    c[f1]=m;
                    break;
                }

            }
        }

        for (i=0;i<n;i++)
        {
            printf("%d ",c[i]);
        }
        printf("\n");


    }
    return 0;
}
