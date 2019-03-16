/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int numl[],int j);
int main()
{
    int t,p;
    char a[1005];
    scanf("%d",&t);
    for (p=0;p<t;p++)
    {
        fflush(stdin);
        gets(a);
        int i,numa=0,numl[1005]={0},j=0,n=0,M=0,MUN=0;

        for (i=0;i<=strlen(a);i++)
        {
            if (a[i]=='A')
            {
                numa++;
                M=0;
            }

            else if (a[i]=='L')
            {


                M++;
                numl[j]=M;


            }
            else if (a[i]=='O')
            {

                j++;
                M=0;
            }

        }
/////////////////////////////////////////////
        for (i=0;i<=j;i++)
        {
            printf("%d",numl[i]);
        }
        printf("\n");
////////////////////////////////////////////
        if (numa>=2)
            printf("NO\n");
        else
        {
            MUN=max(numl,j);

            if (MUN>=3)
                printf("NO\n");
            else
                printf("YES\n");
        }

    }
    return 0;
}

int max(int numl[],int j)
{
    int i=0,k=0,n=0;
    for (i=0;i<=j-1;i++)
    {
        for (n=i+1;n<=j;n++)
        {
            if (numl[i]<numl[n])
            {
                k=numl[i];
                numl[i]=numl[n];
                numl[n]=k;
            }
        }
    }
    return numl[0];
}

*/

#include <stdio.h>
#include <string.h>
int main()
{
    char a[1005];
    int n;
    while (scanf("%d".&n)==1)
    {
        int dp[1005],dp1[1005]={0},dp2[1005]={0},dp3[1005]={1},i,j,k;
        dp[1005]={0};
        for (i=0;i<n;i++)
        {
            dp1[i]=i;
            dp2[i]=dp1[i-1]+dp1[i];
            dp3[i]=dp
//            for (j=0;j<n;j++)
//            {
//                for (k=0;k<n;k++)
//                {
//                    dp1[]
//                }
//            }
        }

    }
    return 0;
}
