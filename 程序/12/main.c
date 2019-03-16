/*#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,a[100],i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",a[i]);
    }

    for (i=0;i<n;i++)
    {
        if (a[i]==4)
      {
          k++;
      }
      else if (a[i]==3)
      {
          b++;
      }
      else if (a[i]==2)
      {

      }
    }

    return 0;
}



#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <iostream>

#include <algorithm>



using namespace std;



int main()

{

    int n;

    while(scanf("%d",&n)!=EOF)

    {

        int cnt[5]={0,0,0,0,0};

        for(int I=1;i<=n;i++)

        {

            int memo;

            scanf("%d",&memo);

            cnt[memo]++;

        }

        int ans=cnt[4]+cnt[3];

        cnt[1]=max(0,cnt[1]-cnt[3]);

        cnt[1]=max(0,cnt[1]-cnt[2]%2*2);

        ans+=(cnt[2]+1)/2;

        ans+=(cnt[1]+3)/4;

        printf("%d\n",ans);

    }

    return 0;

}*/


#include<stdio.h>
int main()
{
    int a[i],t,b[j],x;
    scanf("%d",&t);
    for (j=0;j<=t;j++)
    {
        scanf("%d",b[j]);
        for (i=0;i<=b[j];i++)
        {
            scanf("%d",a[i]);
            if (a[i]<a[i+1])
            {
                x=a[i];
                a[i]=a[i+1];
                a[i+1]=x;
            }
            if (a[i])
        }
    }
}





