/*3：公园的导游图 给出一张某公园的导游图，游客通过终端询问可知：
从某一景点到另一景点的最短路径。游客从公园大门进入，选一条最佳路线，
使游客可以不 重复地游览各景点，最后回到出口（出口就在入口旁边）,只求有五个景点的即可。
 提示：利用二维数组存储景点之间的距离，景点用 1,2 来表示，
 例如 1 与 2 之间距离为 5， 那么二维数组（0,1）的值可以为 5，
*/

#include <stdio.h>
#include <stdlib.h>
struct M
{
    int num1;
    int num2;
    int map;
}maps[10][10];
int main()
{
    int i=0,j=0;
    maps[1][1].map=9;
    maps[1][2].map=2;
    maps[1][3].map=5;
    maps[1][4].map=4;
    maps[1][5].map=3;
    maps[2][1].map=2;
    maps[2][2].map=9;
    maps[2][3].map=3;
    maps[2][4].map=2;
    maps[2][5].map=4;
    maps[3][1].map=5;
    maps[3][2].map=4;
    maps[3][3].map=9;
    maps[3][4].map=2;
    maps[3][5].map=3;
    maps[4][1].map=4;
    maps[4][2].map=3;
    maps[4][3].map=2;
    maps[4][4].map=9;
    maps[4][5].map=1;
    maps[5][1].map=3;
    maps[5][2].map=2;
    maps[5][3].map=1;
    maps[5][4].map=5;
    maps[5][5].map=9;
    printf("公园游览地图：（1、2、3、4、5为景点）\n");
    printf("  1 2 3 4 5\n");
    for (i=1;i<=5;i++)
    {
        printf("%d ",i);
        for (j=1;j<=5;j++)
        {
            maps[i][j].num1=i;
            maps[i][j].num2=j;
            printf("%d ",maps[i][j].map);
        }
        if (i/5==0)
            printf("\n");
    }
    int b=9;

    while (b!=0)
    {
        printf("\n  ********1 查询景点距离********\n  ********2 查看最短游览路线********\n  ********0 退出系统********\n");
        scanf("%d",&b);
        switch (b)
        {
            case 1:
            {
                printf("\n\n\t输入要查询距离的两个景点(用两景点中间用空格隔开,输入0 0返回上一菜单):");
                int a1=0,a2=0;
                scanf("%d%d",&a1,&a2);
                for (i=1;i<=5;i++)
                {
                    for (j=1;j<=5;j++)
                    {
                        if (i==a1&&j==a2)
                        {
                            printf("两景点距离： ");
                            printf("%d",maps[a1][a2].map);
                        }
                        else if (a1>5||a1<0||a2>5||a2<0)
                            printf("输入的景点无效\n");
                        else if (a1==0&&a2==0)
                        break;


                    }
                }
                break;
            }
            case 2:
                {
                    printf("\t游览最短路线：\n");
                    int c=1,d=0;
                 //   int d[7];
                //    printf("1 \n");
                    for (i=c;i<=5;i++)
                    {
                        struct M k;
                        int l=0;
                        for (j=1;j<=5;j++)
                        {
                            for(l=j+1;l<=5;l++)
                            if (maps[i][j].map>maps[i][l].map)
                            {
                                k=maps[i][j];
                                maps[i][j]=maps[i][l];
                                maps[i][l]=k;
                            }
                        }
                        for (j=1;j<=5;j++)
                        {
                            printf("%d ",maps[i][j].map);

                        }
                        printf("\n");
                      //  d[i]=c;
                      d=c;
                        c=maps[i][1].num2;
                        ///////
                        if (c!=d)
                            printf("%d ",c);
                        else if (maps[i][2].num2!=d)
                            printf("%d ",maps[i][2].num2);
                        else if (maps[i][3].num2!=d)
                            printf("%d ",maps[i][3].num2);
                        else if (maps[i][4].num2!=d)
                            printf("%d ",maps[i][4].num2);
                        else if (maps[i][5].num2!=d)
                            printf("%d ",maps[i][5].num2);
                   /*     int n=0,g=0,pas=0;
                        n=i;
                        for (g=1;g<=n;g++)
                        {
                            if (c==d[g])
                            {
                                pas=1;
                                break;

                            }
                            if (g==n)
                            printf("%d ",c);
                        }
                        if (pas==1)
                        {
                                for (g=1;g<=n;g++)
                            {
                                if (maps[i][2].num2==d[g])
                                {
                                    pas=2;
                                    break;
                                }
                                if (g==n)
                                printf("%d ",maps[i][2].num2);
                            }
                        }
                        if (pas==2)
                        {
                            for (g=1;g<=n;g++)
                            {
                                if (maps[i][3].num2==d[g])
                                {
                                    pas=3;
                                    break;
                                }
                                if (g==n)
                                printf("%d ",maps[i][3].num2);
                            }
                        }
                        if (pas==3)
                        {
                            for (g=1;g<=n;g++)
                            {
                                if (maps[i][4].num2==d[g])
                                {
                                    pas=4;
                                    break;
                                }
                                if (g==n)
                                    printf("%d ",maps[i][4].num2);
                            }
                        }
                        if (pas==4)
                        {
                            for (g=1;g<=n;g++)
                            {
                                if (maps[i][5].num2==d[g])
                                {

                                    break;
                                }
                                if (g==n)
                                    printf("%d ",maps[i][5].num2);
                            }
                        }      */
                    }
                }
                break;
        }

    }



    return 0;
}
