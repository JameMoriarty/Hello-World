#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[3],b;
    int x;
    while (a[0]!='\0')
    {
        for (x=0;x<3;x++)
        {
            scanf("%c ",&a[x]);
            if (a[x]>a[x+1])
            {
                b=a[x];
                a[x]=a[x+1];
                a[x+1]=b;
            }
            printf("%c ",a[x]);
        }
        getch('\0');
        printf("\n");

    }
    return 0;
}
