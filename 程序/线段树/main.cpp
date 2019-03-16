//A

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Node
{
    int sum;
    int l;
    int r;
    int val;
}node[300009];
void  build(int l,int r,int pos);
int query(int l,int r,int pos);

int main()
{
    //维护每个线段L-R所有气球被涂色的次数
    //把一个线段L-R分成两部分 L-MID || MID+1-R
    //一直分直到分成L==R时；
    int t;
    while(scanf("%d",&t)==1&&t!=0)
    {
        int a,b,l,r,pos;
        l=1;
        r=t;
        pos=1;
        build(l,r,pos);
        for (int i=0;i<t;i++)
        {
            scanf("%d %d",&a,&b);
            int lc,rc;
            lc=a;
            rc=b;
            for (int i=0;i<t;i++)
            {
                node[i].val=query(lc,rc,pos);
            }

            printf("%d",node[0].val);
            for (int i=1;i<t;i++)
            {
                printf(" %d",node[i].val);
            }
            printf("\n");


        }
    }


    return 0;
}

void  build(int l,int r,int pos)
{
    node[pos].l=l;
    node[pos].r=r;
    node[pos].sum=0;
    node[pos].val=0;
    if (node[pos].l!=node[pos].r)
    {
        build(l,(l+r)>>1,pos*2);
        build(((l+r)>>1)+1,r,pos*2+1);
    }
    return ;

}

int query(int lc,int rc,int pos)
{
    if (lc==node[pos].l&&rc==node[pos].r)
    {


    }
    if (rc<node[pos*2].r)
        return query(lc,rc,pos*2);
    if (lc>node[pos*2+1].l)
        return query(lc,rc,pos*2+1);
    if (lc<=pos*2&&rc>=pos*2+1)
    {
        return query(lc,(node[pos].l+node[pos].r)>>1,pos*2);
        return query((((node[pos].l+node[pos].r)>>1)+1),rc,pos*2+1);

    }

}
