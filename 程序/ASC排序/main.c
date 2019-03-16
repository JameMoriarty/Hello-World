#include<stdio.h>
#include <string.h>
int main()
{
    char a,b,c,k;
    while (scanf(" %c%c%c",&a,&b,&c)!=EOF)
    {
             if (a>b)
             {
                 k=a;
                 a=b;
                 b=k;
             }
             if (a>c)
             {
                 k=a;
                 a=c;
                 c=k;
             }
             if (b>c)
             {
                 k=b;
                 b=c;
                 c=k;
             }
         printf("%c %c %c\n",a,b,c);
    }
    return 0;
}
