/*
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[10005][10005];
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M,x=0,j=1,b,c;
        memset(a,0,sizeof(int)*10005*10005);
        scanf("%d%d",&N,&M);
        for(int i=1;i<=M;i++)
        {
            scanf("%d%d",&b,&c);
            a[b][c]=1;
        }
        if(a[N][1]!=1)
            x++;
        while(j<N)
        {
            if(a[j][j+1]!=1)
                x++;
            j++;
        }
        printf("%d\n",x);
       // a[N][N]={0};
       for (int i=1;i<=M;i++)
       {
           for (int j=0;j<=M;j++)
           {
               a[i][j]=0;
           }
       }
    }
    return 0;
}
*/

#include <iostream>
using namespace std;

int main()
{

    int T;
    cin>>T;
    for (int i=0;i<T;i++)
    {
        int N,M;
        cin >>N>>M;
        char a[10005];
        for (int i=0;i<M;i++)
        {
            cin >> a[i];
        }
    }

    return 0;
}


