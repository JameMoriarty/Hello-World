#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    while (scanf("%d",&n)!=EOF)
    {
        int m=0,p=0,a[150];
        scanf ("%d %d",&m,&p);
        for (i=1;i<=m;i++)
        {
            scnaf("%d",&a[i]);
        }
        int x=0;
        for (i=1;i<=m;i++)
        {
            for (j=1;j<=m;j++)
            {
                if (a[i]==a[j])
                {
                    x=1;
                    break;
                }
            }
        }
    }
    return 0;
}
