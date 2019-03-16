#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int num[2002];
int dp[2002];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }

    int i,j;
    for(i=1;i<=n;i++)
    {
        dp[i]=1;
        for(j=1;j<i;j++)
        {
            if(num[i]>num[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    printf("%d\n",*max_element(dp+1,dp+1+n));
    return 0;
}
