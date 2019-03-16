//A
/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    while (scanf("%d %d",&m,&n)==2)
    {
        int a[200][200],i,j,b[200]={0};
        for (i=0;i<m;i++)
        {
            for (j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j])
                {
                    b[j]++;
                }
            }
        }
        printf("%d",b[0]);
        for (i=1;i<n;i++)
        {
            printf(" %d",b[i]);
        }
        printf("\n");


    }
    return 0;
}
*/


//B
/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int i,a[600],m1=0,m2=0,m3=0,j=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            if (a[i])
            {
                m1+=10;
            }
            else {
                m1-=5;
            }

            if (m1==100)
            {
                if (a[i]+a[i+1]>1)
                {
                    m3++;
                    m1=0;
                    i=i+2;
                }
                else if (a[i]+a[i+1]==1&&a[i+2]==1)
                {
                    m3++;
                    m1=0;
                    i=i+3;
                }
                else if (a[i]+a[i+2]+a[i+1]<2)
                    m1=60;
            }

        }

        if (m3==1)
        {
            printf("C\n");
        }
        else if (m3==0)
        {
            printf("D\n");
        }
        else if (m3==2)
        {
            printf("B\n");
        }
        else if (m3==3)
        {
            printf("A\n");
        }
        else if (m3==4)
        {
            printf("S\n");
        }
    }
    return 0;
}
*/

//D×éºÏÊý
