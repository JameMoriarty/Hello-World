#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,k=0,n=0,numl[105],j=5;
    for (i=0;i<j;i++)
    {
        scanf("%d",&numl[i]);
    }
    printf("\n");

    printf("\n");
    for (i=0;i<j-1;i++)
    {
        for (n=i+1;n<j;n++)
        {
            if (numl[i]<numl[n])
            {
                k=numl[i];
                numl[i]=numl[n];
                numl[n]=k;
            }
        }
    }
    for (i=0;i<j;i++)
    {
        printf("%d",numl[i]);
    }
    printf("numl=%d",numl[0]);
    return 0;
}
