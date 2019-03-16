/*#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    int a[100],i=0,n;
        n=i;
    for (i=0;i<=10;i++)
    {
        scanf("%d",a[i]);
    }
}*/
  /*  void merge_sort (指针,开始的角标s,结束的脚标e)
    {
        if (e==s) return ;   //边界条件
        int m=(s+e)/2;
        merge_sort (指针,s,e);
        merge_sort (指针,s+1,e);
        int p=s,q=m+1;
        int i=s;
        while (p<=s||q<=e)
        {
            if ((q>e)||(p<=m&&num[p]<=num[q]))     //归并
            t[i++]=num[p++];
            else
                p[i++]=num[q++];
        }
        for (i=s;i<=e;i++)
            num[i]=t[i];

    }
    return 0;
}
*/


#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#include <iostream>

using namespace std;

int num[1000000];
int t[1000000];
/*
5
1 2 3 4 5
 */
void merge_sort(int *num,int s,int e)
{
    if(e-s<=0)  return ;
//    int m=s+(e-s)/2;
    int m=(s+e)/2;
    merge_sort(num,s,m);
    merge_sort(num,m+1,e);
    ////////////////

    int p=s,q=m+1;
    int i=s;
    while(p<=m||q<=e)
    {
        if(q>e||(p<=m&&num[p]<=num[q])) t[i++]=num[p++];
        else                            t[i++]=num[q++];
    }
    for(i=s;i<=e;i++)   num[i]=t[i];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)   scanf("%d",&num[i]);
        merge_sort(num,1,n);
        for(int i=1;i<=n;i++)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
    }
    return 0;
}
