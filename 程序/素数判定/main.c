#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=1,y=1,n=0,i=0,ans=0;
    while (scanf("%d%d",&x,&y)!=EOF)
    {
            if (x==0&&y==0)
            break;
        else
        {
            int a=0;
            for (n=x;n<=y;n++)
            {
                ans=n^2+n+41;
                int k=0;
                for (i=2;i<ans;i++)
                {
                    if (ans%i!=0)
                        k++;
                }
                if (k==ans-2)
                    a++;
            }
            if (a==y-x)
                printf("OK\n");
            else
                printf("Sorry\n");
        }
    }
    return 0;
}
