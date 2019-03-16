#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    while (scanf("%d",&n)==1)
    {
        int a[200001],i=1;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
    //     while (i<=n-i+1)
    for (i=1;i<=n-i+1;i++)
            {
                int k=0;
                if (i%2==1)
                {
                    k=a[i];
                    a[i]=a[n-i+1];
                    a[n-i+1]=k;

                }


            }
        printf("%d",a[1]);
        for (i=2;i<=n;i++)
        {
            printf(" %d",a[i]);
        }
        printf("\n");


    }
    return 0;
}
