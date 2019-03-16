#include <stdio.h>
#include <stdlib.h>
int dp[1005][1005];
int max (int a,int b);
int main()
{
    int t=0,m=0;
    while (scanf("%d%d",&t,&m)==2)
    {
      //  printf("%d",dp[1][1]);
        int i=0,j=0,tim[1005],val[1005],ans=0;

        for (i=1;i<=m;i++)
        {
            scanf("%d%d",&tim[i],&val[i]);
        }

        for (i=1;i<=m;i++)
        {
            for (j=1;j<=t;j++)
            {

                if (j>=tim[i])
                {
                    int a=dp[i-1][j-tim[i]]+val[i],b=dp[i-1][j];
                   dp[i][j]= max(a,b);
                }

                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        ans=dp[m][t];
        printf("%d\n",ans);

    }
    return 0;
}
int max (int a,int b)
{

    if (a>b)
        return a;
    else
        return b;
}



///////////////
”≈ªØ
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int t,m;
    int hh[1005],val[1005];
    int dp[1005]={0};
    scanf("%d %d",&t,&m);
    for(int i=1;i<=m;i++) scanf("%d %d",&hh[i],&val[i]);
    int maxn=-1;
    for(int i=1;i<=m;i++)
    {
        for(int j=t;j>=hh[i];j--)
        {
            dp[j]=max(dp[j],dp[j-hh[i]]+val[i]);
        }
    }
    printf("%d\n",dp[t]);
    return 0;
}
