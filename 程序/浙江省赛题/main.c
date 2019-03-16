
//  D
//#include <stdio.h>
//#include <stdlib.h>
//int fibo1(int i);
//int fibo0(int i);
//int main()
//{
//    int t,j;
//    scanf("%d",&t);
//    for (j=0;j<t;j++)
//    {
//        int i,a,b,va=0,mark,n;
//        double va1,num1=0,num0=0;
//        scanf("%d%d%d",&i,&a,&b);
//        num1=fibo1(i);
//        num0=fibo0(i);
//        // printf("%d %d\n",num0,num1);
//        va1=(a-num0)/num1;
//        printf("%lf\n",va1);
//        n=va1*10;
//        mark=n%10;
//        printf("pan duan yong de g1 shi bu shi xiao shu :%d\n",mark);
//        if (mark>0)
//        {
//            va=-1;
//        }
//        else if (mark<0)
//        {
//            va=-1;
//        }
//        else if (mark==0)
//        {
//            va=va1*fibo1(b)+fibo0(b);
//        }
//        if (va1<1)
//        {
//            va=-1;
//        }
//        printf("%d\n",va);
//    }
//    return 0;
//}
//
//int fibo1(int i)
//{
//    if (i==1)
//    {
//        return 1;
//    }
//    else if (i==0)
//    {
//        return 0;
//
//    }
//    else
//        return fibo1(i-1)+fibo1(i-2);
//}
//int fibo0(int i)
//{
//    if (i==1)
//    {
//        return 0;
//    }
//    else if (i==0)
//    {
//        return 1;
//    }
//    else
//        return fibo0(i-1)+fibo0(i-2);
//}


////////////////////////
//int main()
//{
//    while (1)
//    {
//        double a,b;
//        double n;
//        int c;
//        scanf("%lf %lf",&a,&b);
//        n=a/b;
//        c=n*10;
//        printf("%lf %d\n",n,c%10);
//
//    }
//    return 0;
//
//}
//
//
//#include <stdio.h>
//#include <stdlib.h>
//double num1[1000005],num0[1000005];
//int main()
//{
//    int t,i;
//   // double num0[50]={1.0,0.0,1.0,1.0,2.0,3.0,5.0,8.0,13.0,21.0,34.0,55.0,89.0,144.0,233.0,377.0,610.0,987.0,1597.0,2584.0,4181.0,6765.0,10946.0,17711.0,28657.0,46368.0};
//    scanf("%d",&t);
//    for (i=0;i<t;i++)
//    {
//        long long int j,a,b,k,va,mark1,d;
//        double mark;
//        scanf("%lld %lld %lld",&j,&a,&b);
//
//        num1[0]=0.0;
//        num1[1]=1.0;
//        num1[2]=1.0;
//        num0[0]=1.0;
//        num0[1]=0.0;
//        num0[2]=1.0;
//
//        if (j>b)
//            d=j;
//        else
//            d=b;
//        for (k=3;k<=d;k++)
//        {
//            num1[k]=num1[k-1]+num1[k-2];
//            num0[k]=num0[k-1]+num0[k-2];
//        }
//        //for (k=0;k<=d;k++)
//        //{
//        //     printf("%lf ",num1[k]);
//        //}
//       //printf("\n");
//       //printf("%lf\n",num0[j]);
//        mark=(a-num0[j])/num1[j];
//        mark1=mark;
//       // printf("mark d=%lf\n",mark);
//        if (j==1)
//        {
//            if (b==1)
//                va=a;
//            else
//                va=a*num1[b]+num0[b];
//        }
//        else
//        {
//            if (mark<1||mark!=mark1)
//            {
//                va=-1;
//            }
//            else if (mark>=1&&mark==mark1)
//            {
//
//                va=mark*num1[b]+num0[b];
//            }
//        }
//        //printf("num0=%lf num1=%lf\n",num0[b],num1[b]);
//
//       // printf("mark i=%d\n",mark1);
//        printf("%lld\n",va);
//
//    }
//    return 0;
//}


#include<stdio.h>
#include<math.h>
int main()
{
    int t,i,j;
    scanf("%d",&t);
    for (i=0;i<t;i++)
    {
        double n,m,a=1,p=0;
        scanf("%lf %lf",&n,&m);
        for (j=1;j<=n;j++)
        {
            a*=j;
            p+=(exp(-m))*(pow(m,j))/a;

        }
            p+=exp(-m);
        printf("%.3lf\n",p);
    }
    return 0;
}
