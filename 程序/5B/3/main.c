#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[10000];
    while (scanf("%s",a)!=EOF)
    {
        int i=0;
        for (i=strlen(a)-1;i>=0;i--)
        {
            printf("%c",a[i]);
        }
  //      printf("%c\n",a[0]);
        printf("\n\n");
    }
    return 0;
}
