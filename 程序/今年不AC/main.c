#include <stdio.h>
#include <stdlib.h>
struct time
{
    int a;
    int b;
    int c;
}t[150];
int main()
{
    int n=0,q=0,j;;
    scanf("%d",&n);
        int i=0;
        struct time k;
        for (i=0;i<n;i++)
        {
             scanf("%d %d",&t[i].a,&t[i].b);
             t[i].c=t[i].b-t[i].a;
        }
        for (i=0;i<n;i++)
        {
            if (t[i].a>t[i+1].a)
            {
                k=t[i];
                t[i]=t[i+1];
                t[i+1]=k;
            }
        }

        for (i=0;i<n;i++)
        {
            for (j=i+1;i<n;j++)
            {
                if (t[i].b<=t[j].a)
                q++;
            }

        }
    printf("%d",q);
    return 0;
}
