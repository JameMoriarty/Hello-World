#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    char a[100],b[10];
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int k=0;k<n;k++)
        {
            scanf("%s",&a);
            int j=0;
            for (int i=strlen(a);i>5;i--)
            {
                b[j]=a[i];
                j++;
            }
            b[j]='6';
            for (int i=j;i>0;i--)
            {
                printf("%c",b[i]);
            }
            printf("\n");

            }

    }
    return 0;
}
