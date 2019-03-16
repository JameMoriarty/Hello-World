#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

const int inf=1<<29;
const int maxn=210;

struct node
{
    int c;  //残余
    int f;  //流量
};

int n,m;
int sx,ex;
int pre[maxn];
node map[maxn][maxn];

bool spfa()
{
    memset(pre,-1,sizeof(pre));
    queue <int> q;
    q.push(sx);
pre[sx]=sx;
//if(flag)	ans.push(sx);
    while(!q.empty())
    {
        int pos=q.front();  q.pop();
        for(int i=sx;i<=ex;i++)
        {
            if(pre[i]==-1&&map[pos][i].c-map[pos][i].f)
            {
                pre[i]=pre[pos]+1;
                if(i==ex)   return true;
                q.push(i);
		//		if(flag)	ans.push(sx);最小割点集
            }
        }
    }
    return false;
}
int dinic(int pos,int flow)
{
    int f=flow;
    if(pos==ex) return flow;
    for(int i=1;i<=ex;i++)
    {
        if(map[pos][i].c-map[pos][i].f&&pre[pos]+1==pre[i])
        {
            int a=map[pos][i].c-map[pos][i].f;
            int t=dinic(i,min(a,flow));
            map[pos][i].f+=t;
            map[i][pos].f-=t;
            flow-=t;
        }
    }
    return f-flow;
}

int solve()
{
    int sum=0;
    while(spfa())
    {
        sum+=dinic(sx,inf);
    }
    return sum;
}
int main()
{
    for(int n=2;n<=80;n++)
    {
        sx=1,ex=n;
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
                map[i][j].c=(i-1)^(j-1);
        }
        printf("%d\n",solve());
    }
}
