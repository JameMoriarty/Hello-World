#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],t,n,i,q,s=0,j,m;
    scanf("%d",&t);
    for (q=1;q<=t;q++)
    {
       s=0;
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            for (m=0;m<n;m++)
            {
                for (j=i+m;j<n;j++)
                {
                    s+=a[i];
                }

            }
     //       m+=a[i]*i;

      //      for (j=i;j<n;j++)
        //    {
          //       s+=a[i];
            //}


//      for (i=2;i<n;i++)
  //      {
    //        x+=(pow(2,i-2)+2)a[i];
      //  }
   //     m=s+a[0];
        }
        printf("case #%d: %d",q,s);

    }
    return 0;
}
