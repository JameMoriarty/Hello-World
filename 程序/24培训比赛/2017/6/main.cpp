//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <algorithm>
//
//using namespace std;
//
//struct hubs_connect
//{
//    int a;
//    int b;
//    int line;
//};
//int main()
//{
//    int n,m;
//    struct hubs_connect hubs[20000];
//    scanf("%d %d",&n,&m);
//    for (int i=0;i<m;i++)
//    {
//        scanf("%d %d %d",&hubs[i].a,&hubs[i].b,&hubs[i].line);
//    }
//
//    /////////
//    struct hubs_connect t;
//    for (int i=0;i<m;i++)
//    {
//        for (int j=0;j<m;j++)
//        {
//            if (hubs[i].line<hubs[j].line)
//            {
//                t=hubs[i];
//                hubs[i]=hubs[j];
//                hubs[j]=t;
//            }
//
//        }
//
//    }
//
//    /////////////////
//    struct hubs_connect out[20000];
//    int nl,nr,p=0,mark[20000]={0};
//    nr=hubs[0].b;
//    nl=hubs[0].a;
//    mark[0]=nl;
//    out[0]=hubs[0];
//    for (int i=1;i<m;i++)
//    {
//        if(hubs[i].a==nr)
//        {
//            nr=hubs[i].b;
//
//            p++;
//            mark[p]=nr;
//            out[p]=hubs[i];
//
//        }
//    }
//    int k[20000];
//    if (p+1<n)
//    {
//
//
//        for (int i=1;i<m;i++)
//        {
//            for (int j=0;j<=p;j++)
//            {
//                if (hubs[i].a==mark[j]&&hubs[i].b!=)
//                {
//
//                }
//            }
//
//        }
//        for (int i=0;i<m;i++)
//        {
//            for (int j=0;j<m;j++)
//            {
//                for (int l=0;l<m;l++)
//                {
//                    if (hubs[i].b==k[j]&&hubs[i].a==mark[l])
//                    {
//                        p++;
//                        out[p]=hubs[i];
//                    }
//                }
//
//            }
//
//        }
//    }
//
//
//    ////////////////
////    for (int i=0;i<m;i++)
////    {
////        printf("%d %d %d\n",hubs[i].a,hubs[i].b,hubs[i].line);
////    }
//    printf("%d\n",p);
//    for (int i=0;i<=p;i++)
//    {
//        printf("%d %d\n",out[i].a,out[i].b);
//    }
//    return 0;
//}
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 1010
#define maxm 20000
using namespace std;

struct node{
    int u, v, w;
};

node edge[maxm];
int per[maxn];
int n, m;
int ans[maxn];//记录依次选择边的序号
int maxedge, k, num;

int cmp(node a, node b){
    return a.w < b.w;
}

void init(){
    for(int i = 1; i <= n; ++i)
        per[i] = i;
}

int find(int x){
    if(x == per[x])
        return x;
    return per[x] = find(per[x]);
}

void kruskal(){
    for(int i = 1; i <= m; ++i){
        int u = find(edge[i].u);
        int v = find(edge[i].v);
        if(u != v){
            per[u] = v;
            ans[k++] = i;
            num++;
            if(maxedge < edge[i].w)
                maxedge = edge[i].w;
        }
        if(num >= n - 1) break;
    }
}

int main (){
    while(scanf("%d%d", &n, &m) != EOF){
    for(int i = 1; i <= m; ++i)
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    sort(edge + 1, edge + 1 + m, cmp);
    init();
    num = k = maxedge = 0;
    kruskal();
    printf("%d\n", maxedge);
    printf("%d\n", num);
    for(int i = 0; i < num; ++i)
        printf("%d %d\n", edge[ans[i]].u, edge[ans[i]].v);
    }
    return 0;
}

