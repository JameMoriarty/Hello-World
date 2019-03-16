#include<stdio.h>
int main()
{
    int x=0,y=0,i=0,k=0;
    while (scanf("%d%d",&x,&y)!=EOF)
    {
        int m=0,n=0;
        if (x>y)
        {
            k=x;
            x=y;
            y=k;
        }
        for (i=x;i<=y;i++)
        {
            if (i%2!=0)
            {
                m+=i*i*i;
            }
            else
                n+=i*i;
        }
        printf("%d %d\n",n,m);
    }
    return 0;
}
