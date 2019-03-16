#include<stdio.h>
int main()
{
    int m,a,b,x[600001],y[600001],suma=0,sumb=0,i=1,j=1,q;
    scanf("%d",&m);
    for (q=0;q<m;q++)
    {
        scanf("%d%d",&a,&b);
        for (i=1;i<a;i++)
        {
            if (a%i==0)
            {
                x[i]=i;
            }
            else
                x[i]=0;
                suma+=x[i];
        }
        for (j=1;j<b;j++)
        {
            if (b%j==0)
            {
                y[j]=j;
            }
            else
                y[j]=0;
                sumb+=y[j];
        }
        if (suma==b&&sumb==a)
            printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}

