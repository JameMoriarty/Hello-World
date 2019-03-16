//求256+32的最大值


#include <stdio.h>
#include <stdlib.h>
int ifun(int i);
int jfun(int j);
int a,b,c,d,i,j;
int main()
{
    int s;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    s=256*ifun(i)+32*jfun(j);
    printf("%d",s);
    return 0;
}

int ifun(int i)
{
    if (c>d&&a>d)
    {
        i=d;
    }
        else if (d>c&&a>c)
            i=c;
        else if (a<c||a<d)
            i=a;
            return i;
}

int jfun(int j)
{
    if (b>=i)
        j=a-i;
    else
        j=b;
    return j;
}

