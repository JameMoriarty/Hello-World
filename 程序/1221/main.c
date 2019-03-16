#include <stdio.h>
#include <stdlib.h>
int judge(int a[],int s);
int main()
{
    int a[100],i,n,k[100],j,s=1,dp[100],d,q;
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
   // j=-1;
   //    for (i=0;i<n;i++)
   //     {
    for (i=0;i<n;i++)
   {

 /*       for (j=i;j<n;j++)
        {
            if (a[i]<a[j+1])
            {
  //              if (a[j]<a[i+1])
  for (q=j+1;q<n;q++)
    if (a[j+1]<a[q+1])
                s++;

            }
                else
                break;
for (i=0;i<n;i++)
    */    dp[i]=judge(a,s);
        }



 //   }

        }
 //   for (i=1;i<=n;i++)
  //  {
 //       k[i]=dp[i-1]+dp[i];

 //   }
    for (i=0;i<n;i++)
    {
        if (dp[i]<dp[i+1])
        {
            d=dp[i];
            dp[i]=dp[i+1];
            dp[i+1]=d;
        }
    }

    printf("%d",dp[1]);
    return 0;
}

int judge(int a[],int s)
{
    for (i=0;i<n;i++)
  for (j=i;j<n;j++)
        {
            if (a[i]<a[j+1])
            {
  //              if (a[j]<a[i+1])
//  for (q=j+1;q<n;q++)
 //   if (a[j+1]<a[q+1])
                s++;
                judge(a[],s);

            }
                else
                break;
        }
        return s;
}
