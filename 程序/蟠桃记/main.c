#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m=0;
    scanf("%d",&m);
    while (m!=0)
    {
        double a=0,b=0,c=0;
        scanf("%lf %lf %lf",&a,&b,&c);
        if (a+b>c&&a+c>b&&c+b>a)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
            m--;
    }
    return 0;
}
