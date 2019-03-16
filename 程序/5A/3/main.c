#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char a[200];
    int i=0;
    while (scanf("%s",a)!=EOF)
    {
        int sum=0;
        int n=0;
        n=strlen(a);
            int j=0;
            for (i=0;i<n;i++)
            {
                if (a[i]=='1')
                    j=1;
                else
                    j=0;
                sum+=j*(pow(-2,i));
            }
            printf("%d\n",sum);

    }
    return 0;
}
