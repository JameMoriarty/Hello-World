#include <stdio.h>

int main()
{
    int num[50][50];
    int n,m;
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&num[i][j]);
        }
 }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j!=1)    printf(" ");
            printf("%d",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}
