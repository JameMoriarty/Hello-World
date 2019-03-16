#include<stdio.h>

int main()
{
    char a[100];
    int n,i;
    gets(a);
    n=strlen(a);
    for (i=0;i<n;i++)
    {
        if (a[i]>=96&&a[i]<=122)
            a[i]=a[i]-32;
    }
    for (i=0;i<=n;i++)
    {
        printf("%c",a[i]);
    }
    return 0;
}
