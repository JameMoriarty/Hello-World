//http://www.ifrog.cc/acm/problem/1117
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100005];

int main()
{
    int m,j=0,k;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        int x,opt;
        scanf("%d %d",&opt,&x);
            if (opt==1)
                {
                    a[j]=x;
                    j++;
                }
//            if (opt==2)
//                {
                if (opt==2||opt==3)
                {
                    int p1=0;
                    for (k=0;k<j;k++)
                    {
                        if (opt==2&&a[k]<x)
                        {
                            a[k]=x;
                            p1++;
                        }
                        else if (opt==3&&a[k]>x)
                        {
                            a[k]=x;
                         //   p2++;
                        }
                    }
                }

//                }
//            if (opt==3)
//                {
//                    int p2=0;
//                    for (k=0;k<j;k++)
//                    {
//                        if (a[k]>x)
//                        {
//                            a[k]=x;
//                            p2++;
//                        }
//                    }
//                }
            if (opt==4||opt==5)
                {
                    int ans3=0;
                    sort(a,a+j);
                    if (opt==4)
                    {
                        ans3=a[x-1];
                        printf("%d\n",ans3);
                    }
                    if (opt==5)
                    {
                        int p1=0,l=j;
                        for (k=0;k<j;k++)
                        {
                            l=l/2;
                            if (a[l]<x)
                            {
                                l=j-l;
                                if (a[l]>=x)
                                {
                                    printf("%d\n",l);
                                }
                            }
                            else if (a[l]>x)
                            {
                                if (a[l]<=)
                            }
                        }

                    }

                }
            if (opt==5)
                {
                    int p1=0;
                    for (k=0;k<j;k++)
                    {
                        if (a[k]<x)
                        {
                            p1++;
                        }
                    }
                    printf("%d\n",p1);
                }
//                for (int m=0;m<j;m++)
//                {
//                    printf("%d ",a[m]);
//                }
    }
    return 0;
}


