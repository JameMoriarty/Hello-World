#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
char a[10000][10000];
int i,b[10000],num=0,w[10000],flag;

void dfs(char de)
{
    if (de=='m')
    {
        flag=1;
        return;
    }
    for (int s=0;s<num;s++)
    {
        if (w[s]==0&&a[s][0]==de)
        {
            w[s]=1;
            dfs(a[s][1]);
            w[s]=0;
        }
    }
}

int main()
{


    for (i=0;i<10000;i++)
    {
        for (int j=0;j<10000;j++)
        {
            scanf("%c",&a[i][j]);

            if (a[i][j]!='\n'&&a[i][j]!='0')
            {
                a[i][1]=a[i][j];
            }
            else
            {
                b[i]=j;
                break;
            }

        }
        if (a[i][0]=='0')
        {
            num=i;
            break;
        }
    }

    ////////////solve////
    flag=0;
    for (int i=0;i<num;i++)
    {
        memset(w,0,sizeof(w));
        if (a[i][0]=='b')
        {
            w[i]=1;
            dfs(a[i][1]);
        }
        if (flag)
        {
            break;
        }
    }
    if (flag==1)
    {
        printf("Yes.\n");
    }
    else
        printf("No.\n");



    ///////////////
    //  judge
    printf("num= %d\n",num);
    for (int p=0;p<num;p++)
    {
        printf("%d ",b[p]);
    }
    printf("\n");
    for (int k=0;k<num;k++)
    {
        for (int j=0;j<=1;j++)
        {
            printf("%c",a[k][j]);
        }
        printf("\n");
    }


    return 0;
}



//#include<stdio.h>
//#include<string.h>
//#define max 10000
//struct stu
//{
//    char head,end;
//}c[max];
//int w[max],flag,f;
//void dfs(char a)
//{
//    if(a=='m')
//    {
//        flag=1;
//        return ;
//    }
//    for(int i=0;i<f;i++)
//    {
//        if(w[i]==0&&c[i].head==a)
//        {
//            w[i]=1;
//            dfs(c[i].end);
//            w[i]=0;
//        }
//    }
//}
//int main()
//{
//    char s[max];
//    while(scanf("%s",&s)!=EOF)
//    {
//        if(!strcmp(s,"0"))
//          continue;
//        f=0;
//        c[f].head =s[0];
//        c[f].end =s[strlen(s)-1];
//        f++;
//        while(scanf("%s",&s),strcmp(s,"0"))
//        {
//            c[f].head =s[0];
//            c[f].end =s[strlen(s)-1];
//            f++;
//        }
//        flag=0;
//        for(int i=0;i<f;i++)
//        {
//            memset(w,0,sizeof(w));
//            if(c[i].head =='b')
//            {
//                w[i]=1;
//                dfs(c[i].end);
//            }
//            if(flag)
//               break;
//        }
//        if(flag)
//          printf("Yes.\n");
//        else
//          printf("No.\n");
//    }
//    return 0;
//}
