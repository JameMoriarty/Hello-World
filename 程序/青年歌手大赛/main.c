#include<stdio.h>
int main()
{
    int n=0;
    double sum=0,m[150],k=0;
    while (scanf("%d ",&n)!=EOF&&n>2&&n<=100)
    {
        sum=0;
        int i=0;
        for (i=0;i<n;i++)
        {
            scanf("%lf",&m[i]);
        }
        for (i=0;i<n-1;i++)
        {
            if (m[i]<m[i+1])
            {
                k=m[i];
                m[i]=m[i+1];
                m[i+1]=k;
            }
        }
        for (i=1;i<n-1;i++)
        {
            sum+=m[i];
        }
        sum=sum/(n-2);
        printf("%.2lf\n",sum);

    }
    return 0;
}
