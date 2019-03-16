#include <stdio.h>
#include <math.h>
#define M 5
#define N 5

int main()
{
    int m[M][N];
    int i,j,t,max,x,y;
    for(i=0;i<5;i++)
    {
        max=0;
        for(j=0;j<5;j++)
        {
            scanf("%d",&m[i][j]);
            if(abs(m[i][j])>abs(max));
            {
                max=m[i][j];
                x=i;
                y=j;
            }
            if(j==4)
            {
                 t=m[i][i];
                 m[i][i]=max;
                 m[x][y]=t;
            }
        }
    }
        for(i=0;i<5;i++)
        {
            printf("%d",m[i][0]);
            for(j=1;j<5;j++)
            {
            printf(" %d",m[i][j]);
            }
            printf("\n");
        }
        return 0;
}
