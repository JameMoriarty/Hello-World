#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n=0,i=0;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        int m=0,j=0;
        double a[150],ans=0,b=0;
        scanf("%d",&m);
        for (j=1;j<=m;j++)
        {
            b=pow(-1,j+1);
            a[j]=1.0/j*b;
        }
        for (j=1;j<=m;j++)
        {
            ans=ans+a[j];
        }

        printf("%.2lf\n",ans);
    }
    return 0;
}
