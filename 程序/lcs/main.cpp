#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

char str1[2005];
char str2[2005];
int dp[2005][2005];

int main()
{
    while(scanf("%s %s",str1+1,str2+1)!=EOF)
    {
        int len1=strlen(str1+1);
        int len2=strlen(str2+1);

        memset(dp,0,sizeof(dp));

        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(str1[i]==str2[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
