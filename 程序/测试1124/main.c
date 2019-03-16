#include<stdio.h>
int mfun(int m);
int nfun(int n);
int mnfun(int mn);
int main()
{
    int m,n,mn,x,y,z;
    double s;
    printf("input two intgers m n :\n");
    scanf("%d%d",&m,&n);
    mn=m-n;
    x=mfun(m);
    y=nfun(n);
    z=mnfun(mn);
    s=x/(y*z);
    printf("%lf",s);
    return 0;
}

int mfun(int m)
{
    int x1;
    if (m==1)
    {
        x1=1;
    }
    else
    {
        x1=mfun(m-1)*m;
    }
    return x1;
}

int nfun(int n)
{
    int y1;
    if (n==1)
    {
        y1=1;
    }
    else
    {
        y1=nfun(n-1)*n;
    }
    return y1;
}

int mnfun(int mn)
{
    int z1;
    if (mn==1)
    {
        z1=1;
    }
    else
    {
        z1=mnfun(mn-1)*(mn);
    }
    return z1;
}
