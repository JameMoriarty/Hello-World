#include <stdio.h>
#include <stdlib.h>
int sort (int a[],int n);
int main()
{
    int n=0,m=0;
    while (scanf("%d%d",&n,&m)==2)
    {
        int a[100001],i=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int k=0;
        k=sort (a,n);
        printf("%d",k);
        int l=0;
        for (i=1;i<=n;i++)
        {
            l+=a[i];
        }
        check(a[],l,k);
    }
    return 0;
}

int sort (int a[],int n)
{
    int i=0;
    for (i=1;i<=n;i++)
    {
        int j=0;
        for (j=1;j<=n;j++)
        {
           if (a[i]<a[j])
           {
               int k=0;
               k=a[i];
               a[i]=a[j];
               a[j]=k;
           }
        }
    }
    return a[n];
 //   for (i=1;i<=n;i++)
 //   printf("%d ",a[i]);
 //   return 0;
}

