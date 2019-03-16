#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,x=0,a[150],b[150],y=0;
    while (scanf("%d",&n)!=EOF)
    {
        int i=0,j=0,k=0;
       while (i<n)// for (i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            if (x==1)
            {
                a[j]=y;
                j++;
            }
            else if (x==2)
            {
                b[k]=y;
                k++;
            }
            i++;
        }
        int c[150],l=0;
        for (i=0;i<j-1;i++)
        {
            c[i]=a[i];
        }
        for (i=0;i<j-1;i++)
        {
            if (c[i]<c[i+1])
            {
                l=c[i];
                c[i]=c[i+1];
                c[i+1]=l;
            }
        }
        int m1=0;
        for (i=0;i<j-1;i++)
        {
                if (a[i]==b[i])
                    m1++;
                else
                    m1=0;

        }
        int q=0,m2=0;
        for (i=0;i<j;i++)
        {
            for (q=k-1;q>=0;q--)
            {
                if (a[i]==b[q])
                    m2++;
                else
                    m2=0;
            }
        }
        int m3=0;
        for (i=0;i<k-1;i++)
        {
                if (b[i]==c[i])
                    m3++;
                else
                    m3=0;

        }
        if (m1==j-1)
            printf("queue\n");
        else if (m2==j-1)
            printf("stack\n");
            else if (m3==k-1)
                printf("priority queue\n");
            else
                printf("impossible\n");

    }
    return 0;
}
