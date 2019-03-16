//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    int n,m;
//    while(scanf("%d %d",&n,&m)!=EOF)
//    {
//        int e[250][250],k,i,j,t1,t2,t3;
//        int inf=99999999; //用inf(infinity的缩写)存储一个我们认为的正无穷值(用来表示两点之间没有边，根据题目可改为负数)
//        //读入n和m，n表示顶点个数，m表示边的条数
//        //初始化
//        for(i=0;i<n;i++)
//            for(j=0;j<n;j++)
//                if(i==j) e[i][j]=0;
//                    else e[i][j]=inf;
//        //读入边
//        for(i=0;i<m;i++)
//        {
//            scanf("%d %d %d",&t1,&t2,&t3);
//            e[t1][t2]=t3;
//            //双向边需
//            e[t2][t1]=t3;
//        }
//        //Floyd-Warshall算法核心语句
//        for(k=0;k<n;k++)
//            for(i=0;i<n;i++)
//                for(j=0;j<n;j++)
//                    e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
//        //输出最终的结果矩阵
////        for(i=0;i<n;i++)
////        {
////            for(j=0;j<n;j++)
////            {
////                printf("%10d ",e[i][j]);
////            }
////            printf("\n");
////        }
//        int a,b;  //起点和终点；
//        scanf("%d %d",&a,&b);
//        if (e[a][b]==inf)  //当两点之间没有路时为-1;
//        {
//            e[a][b]=-1;
//        }
//        printf("%d\n",e[a][b]);  //输出两点之间的最短距离;
//    }
//    return 0;
//}


#include <iostream>
#include <cstdio>
using namespace std;
const int INF = INT_MAX / 2;
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int w[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                w[i][j] = INF;
        int a, b, c;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            if (c < w[a][b])                //一个坑，无向图可能有多条路，求最短的
            w[a][b] = w[b][a] = c;
        }
        int start, end;
        scanf("%d %d", &start, &end);
        int d[n], v[n];
        for (int i = 0; i < n; ++i)
            v[i] = 0;
        for (int i = 0; i < n; ++i)
            d[i] = (i == start ? 0 : INF);
        for (int i = 0; i < n; ++i)
        {
            int x, m = INF;
            for (int y = 0; y < n; ++y)
                if (!v[y] && d[y] <= m)
                    m = d[x=y];
            v[x] = 1;
            for (int y = 0; y < n; ++y)
                d[y] = d[y] < d[x] + w[x][y] ? d[y] : d[x] + w[x][y];
        }
        if (d[end] != INF)
            printf("%d\n", d[end]);
        else
            printf("-1\n");
    }
    return 0;
}
