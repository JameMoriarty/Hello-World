#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x=0,y=0,i,s[500][500],j,k=0,p=0;
    long int a[500];
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        a[y-x]=y;
        a[0]=x;
        for (p=0;p<y-x;p++)
        {
            for (j=0;j<y-x;j++)
            {
                s[p][j]=a[p]|a[j];
            }
        }
        for (p=0;p<y-x;p++)
        {
            for (j=0;j<y-x;j++)
            {
              if (s[p][j]<s[p][j+1])
              {
                  k=s[p][j];
                  s[p][j]=s[p][j+1];
                  s[p][j+1]=k;
              }
            }
        }
        for (p=0;p<y-x;p++)
        {
            if (s[p][0]<s[p+1][0])
            {
                k=s[p][0];
                s[p][0]=s[p+1][0];
                s[p+1][0]=k;
            }
        }
        printf("%d\n",s[0][0]);

    }
    return 0;
}
