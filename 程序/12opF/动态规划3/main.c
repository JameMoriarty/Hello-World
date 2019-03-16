#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,dp[50][50],a[50];
    for (i=0;i<=40;i++)
    {
        dp[0][i]=0;
        dp[i][0]=1;
    }
    dp[0][0]=1;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=40;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
        }
    }
    printf("%d\n",dp[n][40]/40);
    return 0;
}
