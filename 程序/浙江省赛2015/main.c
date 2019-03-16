
//A
#include <stdio.h>
#include <stdlib.h>
struct elect
{
    int mem;
    int num;
};
void sort (int a[],int m);
int main()
{
    int n;
    struct elect e[1050];
    scanf("%d",&n);
    while(n--)
    {
        int m,a[1050],i,j,b,s,str[1050]={0};
        scanf("%d",&m);
        for (i=0;i<m;i++)
        {

            scanf("%d",&s);
            a[i]=s;
            str[s]++;
        }
        sort(a,m);

        /////////////
//        for (i=0;i<m;i++)
//        {
//            printf("%d",a[i]);
//        }
        ///////////
        b=0;
        for (i=0;i<m;i++)
        {
                if (a[i]!=a[i+1])
                {
                    e[b].mem=a[i];
                    b++;
                }

        }
        for (j=0;j<m;j++)
        {
            for (i=0;i<1050;i++)
            {
                if (i==e[j].mem)
                {
                    e[j].num=str[i];
                }

            }
        }



        ///////////////
        for (i=0;i<m;i++)
        {
            printf("%d ",e[i].mem);
        }
        printf("\n");
        for (i=0;i<m;i++)
        {
            printf("%d ",e[i].num);
        }
        ////////////////


    for (i=0;i<m-1;i++)
    {
        for (j=i+1;j<m;j++)
        {
            struct elect q;
            if (e[i].num<e[j].num)
            {
                q=e[i];
                e[i]=e[j];
                e[j]=q;
            }
        }
    }

    //////////////
        for (i=0;i<m;i++)
        {
            printf("%d ",e[i].num);
        }
        printf("\n");
        /////////
if (e[0].mem!=e[1].mem)
{
    if (e[1].mem!=e[0].mem)
                printf("%d\n",e[0].mem);
    else if (e[0].num==e[1].num)
            {
                printf("Nobody\n");
            }

}
else if (m==1)
    printf("%d\n",e[0].mem);
    else if (e[0].mem==e[1].mem)

    }
    return 0;
}

void sort(int a[],int m)
{
    int i,j;
    for (i=0;i<m-1;i++)
    {
        for (j=i+1;j<m;j++)
        {
            int k=0;
            if (a[i]>a[j])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
}


//L
//#include <stdio.h>
//int main()
//{
//    int n,i;
//    scanf("%d",&n);
//    for (i=0;i<n;i++)
//    {
//        int t,j,mmr[50];
//        scanf("%d",&t);
//        for (j=0;j<t;j++)
//        {
//            scanf("%d",&mmr[j]);
//        }
//        int k=0;
//        for (j=0;j<t;j++)
//        {
//            if (mmr[j]>6000)
//            {
//                k++;
//            }
//        }
//        printf("%d\n",k);
//    }
//    return 0;
//}

//H
//#include<stdio.h>
//int judge(int x);
//int main()
//{
//    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//    int t,i;
//    scanf("%d",&t);
//    for (i=0;i<t;i++)
//    {
//        int x,y,j,d[1000]={0},date,k;
//        scanf("%d",&x);
//        if (x>2017)
//        {
//            y=0;
//            for (k=0;k<=x-2017;k++)
//            {
//                x--;
//                d[k]=judge(x);
//                y+=d[k];
//            }
//            date=y%7;
//            //////
//            for (j=0;j<=x-2017;j++)
//            {
//                printf("%d ",d[j]);
//            }
//            printf("\n");
//            printf("days=%d\n",y);
//            printf("date=%d\n",date);
//            //////
//
//        }
//        else if (x<2017)
//        {
//            y=0;
//            for (k=0;k<=2017-x;k++)
//            {
//                z=x+k;
//                printf("%d\n",z);
//                d[k]=judge(z);
//                y+=d[k];
//
//            }
//            date=(y)%7;
//            //////
//            for (j=0;j<=2017-x;j++)
//            {
//                printf("%d ",d[j]);
//            }
//            printf("\n");
//            printf("days=%d\n",y);
//            printf("date=%d\n",date);
//            //////
//        }
//        else if (x==2017)
//        {
//            printf("9\n");
//            y=0;
//
//        }
//
//
//    }
//    return 0;
//}
//
//int judge(int x)
//{
//    if (x%100==0&&x%400==0)
//            return 366;
//    else if (x%100==0&&x%400!=0)
//            return 365;
//    else if (x%100!=0&&x%4!=0)
//            return 365;
//    else if (x%100!=0&&x%4==0)
//            return 366;
//}
