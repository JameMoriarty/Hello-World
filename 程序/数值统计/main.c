#include<stdio.h>
int main()
{
    int n=0,i;
    double x=0;
    while (scanf("%d",&n)!=0)
    {
        if (n==0)
            break;
        else
        {
            int a=0,b=0,c=0;
            for (i=0;i<n;i++)
            {
                scanf("%lf",&x);
                if (x>0)
                    c++;
                else if (x==0)
                    b++;
                else if (x<0)
                    a++;
            }
            printf("%d %d %d\n",a,b,c);
        }


    }
    return 0;
}
