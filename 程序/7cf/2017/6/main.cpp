#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
int a[300],b[300];

int main()
{
    int n,k;
    while (scanf("%d %d",&n,&k)==2)
    {
        int i,mark[300];
        for (i=0;i<n;i++)
        {
            int j=0;
            scanf("%d",&a[i]);
            if (a[i]==0)
            {
                mark[j]=i;
                j++;
            }
        }
        for (i=0;i<k;i++)
        {
            scanf("%d",&b[i]);
        }

        if (k==1)
        {
            int p;
            p=mark[0];
            if (p!=0&&p!=n-1&&(b[0]<a[p-1]||b[0]>a[p+1]))
            {
                printf("Yes\n");
            }
            else
            {
                int num=0;
                a[p]=b[0];
//                for (i=0;i<n;i++)
//                {
//                    printf("%d ",a[i]);
//                }
//                printf("\n");
                for (i=0;i<n-1;i++)
                {
                    if (a[i]>a[i+1])
                    {
                       // printf("Yes\n");
                        break;
                    }
                    else
                    {
                        num++;
                        continue;
                    }
                }
              //  printf("num=%d\n",num);
                if (num==n-1)
                    printf("No\n");
                else if (num<n-1)
                    printf("Yes\n");
            }


        }
        else if (k>1)
        {
            printf("Yes\n");

        }

    }
    return 0;
}
