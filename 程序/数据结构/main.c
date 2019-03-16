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
        int c[150],m3=0;
        for (i=0;i<j-1;i++)
        {
            if (a[i]<a[i+1])
            {
                c[i]=a[i+1];
                c[i+1]=a[i];
            }
        }
        int m1=0,q=0,m2=0,m4=0,m5=0;
        if (j==k)
        {
            for (i=0;i<j;i++)
            {
                for (q=k-1;q>=0;q--)
                {
                    if (a[i]==b[i])
                        m1++;
                    else if (a[i]==b[q])
                        m2++;
                      //  else if (a[i]!=b[i]&&a[i]!=b[q])
                      //  {
                      //      m4=1;
                      //  }
                    else if (b[i]==c[i])
                        m3++;

                }

            }
        }
        else if (j!=k)
        {
            for (i=0;i<k;i++)
            {
                if (b[i]==c[i])
                    m5++;
            }
        }
        if (m1==j&&m2!=j&&m3!=j&&m5!=k)
            printf("queue\n");
        else if (m1!=j&&m2==j&&m3!=j&&m5!=k)
            printf("stack\n");
        else if (m1!=j&&m2!=j&&m3==j&&m5!=k)
            printf("priority queue\n");
     //   else if (m1!=j&&m2!=j&&m3!=j&&m4==1&&m5!=k)
     //       printf("impossible\n");
        else if (m1!=j&&m2!=j&&m3!=j&&m5==k)
            printf("priority queue\n");
        else if (m1!=j&&m2==j&&m3==j&&m5!=k||m1==j&&m2!=j&&m3==j&&m5!=k)
            printf("not sure\n");
            else
                printf("impossible\n");



    }
    return 0;
}
