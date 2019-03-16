#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,i;
    double x=0,y=0;
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        y=n;
        x=0;
        for (i=1;i<m;i++)
        {
            y=sqrt(y);
            x+=y;
        }
        printf("%.2lf\n",x+n);
    }
    return 0;
}
