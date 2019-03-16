#include<stdio.h>
#include<math.h>
int main()
{
    int a[100];
    int m,i,j,n;
    double s[100],x=0,z=0,k,y;
    scanf("%d",&m);
    for (j=1;j<=m;j++)
    {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        x+=a[i];


    }
    y=x/n;
    for (i=1;i<=n;i++)
    {

        z+=pow((a[i]-y),2);
    }
    k=z/n;
    s[j]=sqrt(k);

    }
    for (j=1;j<=m;j++)
    {
        printf("%.5lf\n",s[j]);
    }
    return 0;

}
