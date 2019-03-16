//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int maxn=1003;
//int a[maxn],b[maxn];
//int p[maxn];
//bool vis[maxn];
//void print_ans(int n)
//{
//    printf("%d",p[1]);
//    for(int i=2;i<=n;i++)
//        printf(" %d",p[i]);
//    printf("\n");
//    }
//    int get_rand(int n)
//     {
//         for(int i=1;i<=n;i++)
//            if(vis[i]==false)
//            return i;
//         }
//         bool check(int n)
//         {
//             memset(vis,false,sizeof(vis));
//             for(int i=1;i<=n;i++)
//                {
//                    if(vis[p[i]]==false)
//                    vis[p[i]]=true;
//             else
//                return false;
//             }
//             return true;
//             }
//             int main()
//             {
//                 int n;
//                 while(scanf("%d",&n)!=EOF)
//                    {
//                        for(int i=1;i<=n;i++)
//                        scanf("%d",&a[i]);
//                 for(int i=1;i<=n;i++)
//                    scanf("%d",&b[i]);
//                 int cnt=0;
//                 for(int i=1;i<=n;i++)
//                    {
//                        if(a[i]!=b[i])
//                        cnt++;
//                 else vis[a[i]]=true;
//                 }
//                 if(cnt==1)
//                 {
//                        for(int i=1;i<=n;i++)
//                        {
//                            if(i>1) putchar(' ');
//                 if(a[i]==b[i])
//                    printf("%d",a[i]);
//                 else printf("%d",get_rand(n));
//                 } printf("\n");
//                 }
//                 else
//                    {
//                        cnt=0;
//                 int posa=0;
//                 int posb=0;
//                 for(int i=1;i<=n;i++)
//                    {
//                        if(a[i]==b[i])
//                        p[i]=a[i];
//                 else
//                    {
//                        if(cnt==0)
//                        {
//                            posa=i;
//                 p[i]=a[i];
//                 cnt++;
//                 }
//                 else
//                    {
//                        posb=i;
//                 p[i]=b[i];
//                 }
//                  }
//                  }
//                  if(check(n))
//                    print_ans(n);
//                  else
//                    {
//                        p[posa]=b[posa];
//                  p[posb]=a[posb];
//                  print_ans(n);
//                  }
//                  }
//                  }
//                  return 0;
//                  }

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int alphabet=26;
char str[1700];
int dp[alphabet][1700];
void init(int n)
{
    for(int ch=0;ch<26;ch++)
        {
            for(int i=1;i<=n;i++)
            {
                int num=0;
    for(int j=i;j>=1;j--)
        {
            if(str[j]-'a'==ch)
            num++;
    dp[ch][i-j+1-num]=max(dp[ch][i-j+1-num],i-j+1);
    }
    }
    }
    }
    int main()
    {
        int n;
        while(scanf("%d",&n)!=EOF)
            {
                scanf("%s",str+1);
        memset(dp,-1,sizeof(dp));
        init(n);
        int q;
        scanf("%d",&q);
         while(q--)
            {
                int m;
         char ch;
         scanf("%d %c",&m,&ch);
         if(dp[ch-'a'][m]==-1)
            printf("%d\n",n);
         else printf("%d\n",dp[ch-'a'][m]);
         }
         }
         return 0;
         }

