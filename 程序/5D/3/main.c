/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x=0;
    int a[55][55];
    int i=0,j=0;
    for (j=1;j<=54;j++)
    {
        if (j<6)
        a[1][j]=1;
        else
            a[1][j]=2+(j-6);
    }


    for (i=2;i<=54;i++)
    {
        if (i<=15)
            {
        for (j=1;j<=54;j++)
        {

                if (j<5*2+(i-2))
                a[i][j]=0;
                else
                a[i][j]=1+(j-(5*2+(i-1)));

            }
            }
            else if (i>15&&i<30)
            {
                if (j<5*3+(i-2))
                    a[i][j]=0;
                else
                    a[i][j]=1+(j-(5*3+(i-1)));
            }

        }
    }
    for (i=1;i<=54;i++)
    {
        for (j=1;j<=54;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    while (scanf("%d",&x)==1)
    {
        int ans=0;
        for (i=1;i<=54;i++)
        {
            ans+=a[i][x];
        }
        printf("%d\n",ans);
    }

    return 0;
}
*/

#include <stdio.h>
#include <string.h>
int main()
{
    int a[55][55],i=0,j=0;
        for (j=0;j<5;j++)
        {
            a[1][j]=1;
        }
        for (j=0;j<5;j++)
        {
            a[2][j]=j+1;
        }
    for (i=3;i<=11;i++)
    {
        a[i][0]=a[i-1][0]+a[i-1][4];
        for (j=1;j<=5;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }

    int x=0;
    while (scanf("%d",&x)==1)
    {
        printf("%d\n",a[x/5+1][x%5]);
    }
    return 0;
}

