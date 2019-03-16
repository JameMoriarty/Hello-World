#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int judje(int bnum,int wnum,char a[10][10])
{
    bnum=0;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (a[i][j]=='b')
            {
                bnum++;
            }
            if (a[i][j]=='w')
            {
                wnum++;
            }
        }
    }
    printf("bnum=%d wnum=%d\n",bnum,wnum);
    if (bnum==16||wnum==16)
        return 0;
    else
        return 1;

}
int main()
{
    char a[10][10];
    int wnum=0,bnum=0;
    //input
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            scanf("%c",&a[i][j]);
        }
        getchar();
    }
  //  printf("scanf is finished.");
    //Ã¶¾Ù
    int num=0;
    num=judje(bnum,wnum,a);
    if (num==0)
        printf("%d\n",num);
    else
        for (int i=0;i<4;i++)
        {

        }



    return 0;
}
