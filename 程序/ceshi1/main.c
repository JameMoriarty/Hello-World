#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100],b[100];
    int i=0;
    gets(a);
    gets(b);
    if (strcmp(a,b)==1)
        printf("y\n");

    return 0;
}
