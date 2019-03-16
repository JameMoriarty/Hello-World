#include<stdio.h>
int main()
{
    int i,j,x,y;
    scanf("%d%d",&i,&j);
    int a[100][100];
    for (x=0;x<=i;x++)
    {
        for(y=0;y<=j;y++)
        {
        scanf("%d",&a[x][y]);
        }
    }
        for (x=0;x<=i;x++)
        {
            for(y=0;y<=j;y++)
            {
                if (y!=0)
                printf(" ");
            printf("%d",&a[x][y]);
            }
            printf("\n");
        }
        return 0;

}
