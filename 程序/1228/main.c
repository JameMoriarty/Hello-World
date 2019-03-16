#include <stdio.h>
#include <stdlib.h>
int lowbit(int x);
int main()
{
    int n,x,k,i,q;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&x);
        k=lowbit(x-1);
        q=lowbit(x+1);
        printf("%d %d\n",k,q);
    }
    return 0;
}

int lowbit(int x)
{
    return ((-x+1)&x);
}
