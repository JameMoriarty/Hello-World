#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,j=0,k=0,num[10];
    for (i=1;i<=5;i++)
    {
        scanf("%d",&num[i]);
    }
    for (i=1;i<5;i++)
    {
        for (j=i+1;j<=5;j++)
        {
            if (num[i]>num[j])
            {
                k=num[i];
                num[i]=num[j];
                num[j]=k;
            }
        }
    }
    for (i=1;i<=5;i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}
