#include<stdio.h>
int main()
{
    long int x[600050],m,a,b,i=1,j=1,k,y[600050],n,suma=0,sumb=0;
    scanf("%ld",&m);
    for (k=0;k<m;k++)
    {
        scanf("%ld%ld",&a,&b);
        while (i<a)
        {
            if (a%i==0)
            {
                x[i]=i;
            }
            else
                x[i]=0;
            i++;
        }
        while (j<b)
        {
            if (b%j==0)
            {
                y[j]=j;
            }
            else
                y[j]=0;
            j++;
        }
        for (n=1;n<a;n++)
        {
            suma+=x[n];
        }
        for (n=1;n<b;n++)
        {
            sumb+=y[n];
        }
        if ((suma==b)&&(sumb==a))
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
