#include <stdio.h>
#include <stdlib.h>

int father[50003];

int findfather(int x)
{
    if(father[x]==x)    return x;
    else                return findfather(father[x]);
}

int main()
{

      int n,m;
    scanf("%d %d",&n,&m);
    int i;
    for(i=1;i<=n;i++)   father[i]=i;
    while(m--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int fa=findfather(a);
        int fb=findfather(b);
        if(fa==fb)  continue;
        else        father[fa]=fb;
    }
    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(father[i]==i)    ans++;
    }
    printf("%d\n",ans);
    return 0;
}
