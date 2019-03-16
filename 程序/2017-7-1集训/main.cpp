#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main ()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        if (n==0)
            break;
        int a,i,dp[100005]={0},judge[100005]={-1};
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a);
            judge[a]=i;
            if (judge[a]!=-1)
            {
                if (a==999)
                {
                    dp[i]=max(dp[i-1],dp[judge[a]]+3);
                }
                else
                {
                    dp[i]=max(dp[i-1],dp[judge[a]]+1);
                }
            }
            else
                dp[i]=dp[i-1];


        }

        for (i=1;i<=n;i++)
        {
            printf("%d ",judge[i]);
        }
        printf("\n");
        printf("%d\n",dp[n]);
    }
    return 0;
}

//
//int dp[100010];
//bool vis[100010];
//int a[100010];
//
//int main(){
//    int n;
//
//    while(scanf("%d",&n)!=EOF){
//            if(n==0)
//            break;
//
//
//        memset(dp,0,sizeof(dp));
//        memset(a,0,sizeof(a));
//        memset(vis,false,sizeof(vis));
//
//       for(int i=0;i<n;i++){
//        scanf("%d",&a[i]);
//       }
//
//         int sum=-1;
//
//           int point=a[0];
//           vis[point]=true;
//
//
//
//         for(int i=1;i<n;i++){
//             int next=a[i];
//             if(!vis[next]){
//
//                dp[next]=dp[point];
//                vis[next]=true;
//             }
//             else{
//                 if(next==999){
//                    dp[next]=max(dp[point],dp[next]+3);
//                    }
//                else{
//                   dp[next]=max(dp[point],dp[next]+1);
//                   }
//             }
//
//             point=next;
//
//             if(dp[next]>sum)
//                sum=dp[next];
//
//         }
//         printf("%d\n",sum);
//    }
//    return 0;
//}
