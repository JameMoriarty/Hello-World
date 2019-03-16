#include <stdio.h>
#include <string.h>
char a[1115][5];
void dfs(int d)
{
    int e,k,i,c[1115]={0};
    if(a[d][1]=='m')
    {
        k=1;
        return;
    }
    for(e=0;e<i;e++)
    {
        if(a[d][1]==a[e][0]&&c[e]==0)
        {
            c[e]=1;
            dfs(e);
            c[e]=0;
        }
    }
}
int main ()
{
    while(1)
    {
        char b;
        int i=0,flag=0,j,k=0;
        scanf("%c",&a[0][0]);
        while(a[i][0]!='0')
        {
            while(1)
            {
                scanf("%c",&b);
                if(b!='\n')
                    a[i][1]=b;
                else
                    break;
            }
            if(a[i][1]=='m')
                flag=1;
            i++;
            scanf("%c",&a[i][0]);
        }
        if(!flag)
            printf("No.\n");
        else
        {
            for(j=0;j<i;j++)
            {
                if(a[j][0]=='b')
                    dfs(j);
            }
            if(k)
                printf("Yes.\n");
            else
                printf("No.\n");
        }

    }
    return 0;
}
