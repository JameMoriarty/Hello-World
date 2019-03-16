#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char sa[100],sb[100];
    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s %s",&sa,&sb);
        if (strcmp(sa,sb)>0)
            printf("player1\n");
            else
                printf("player2\n");

    }
    return 0;

}
