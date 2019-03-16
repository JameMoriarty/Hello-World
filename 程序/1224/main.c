#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],i,j,dp[100][100],n,k,q[100][100],m,b;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++)
    {

        for (j=i+1;j<n;j++)
        {

            if (a[i]<a[j])
            {

                k=1;
            }
            else
                k=0;
           dp[i][j]=k;
        }



    }
    for (i=0;i<n;i++)
    {
        m=0;
        for (j=i+1;j<n;j++)
        {
            m+=dp[j][j+1];

        }
         for (j=i+1;j<n;j++)
        {
            q[i][j]=dp[i][j]+m+1;

        }

    }
    for (i=0;i<n;i++)
    {
        for (j=i;j<n;j++)
        {
        if (q[i][j]<q[i][j+1])
        {
            b=q[i][j];
            q[i][j]=q[i][j+1];
            q[i][j+1]=b;
        }
        }
    }
    for (i=0;i<n;i++)
    {
        if (q[i][1]<q[i+1][1])
        {
            b=q[i][1];
            q[i][1]=q[i+1][1];
            q[i+1][1]=b;
        }
    }
     printf("%d",q[0][1]);

    return 0;
}
