#include <stdio.h>
#include <string.h>
#define N 100
int all;
struct stu
{
    char nam [10];
    int num;
    int score[4];
};
struct stu s[N];
int add(int all)
{
    printf("请输入学生信息（姓名，学号，科目成绩1，2，3）：");
    scanf("%s %d%d%d%d",s[all].nam,&s[all].num,&s[all].score[1],&s[all].score[2],&s[all].score[3]);
    all++;
    return all;
}
int sort()
{
    int i,j,k,l;
    for (i=0;i<all;i++)
    {
        s[i].score[0]=s[i].score[2]+s[i].score[1]+s[i].score[3];
    }
    for(l=0;l<all;l++)
    {
        for(k=0;k<all;k++)
        {
           if(s[k].score[0]<s[k+1].score[0])
           {
               j=s[k].score[0];
               s[k].score[0]=s[k+1].score[0];
               s[k+1].score[0]=j;
           }
        }
    }
    for (i=0;i<all;i++)
    {
        printf("排名：%d 姓名：%s 学号：%d 科目一：%d 科目二：%d 科目三:%d 总成绩：%d\n",i+1,s[i].nam,s[i].num,s[i].score[1],s[i].score[2],s[i].score[3],s[i].score[0]);
    }
    return 0;
}
void search()
{
    int i,j=0;
    scanf("%d",&i);
    while (i!=s[j].num&&j<all)
        {
            j++;
        }
    printf("姓名：%s 学号：%d科目一：%d 科目二：%d 科目三：%d 总分：%d\n",s[i].nam,s[i].num,s[i].score[1],s[i].score[2],s[i].score[3],s[i].score[0]);
}
void no()
{
    int i,j=0;
    for(i=0;i<all;i++)
    {
        if(s[i].score[0]>180)
        j++;
    }
    printf("%d\n",j-1);
}
int  main()
{
    int choice,i;
        printf("请添加学生信息，学生的数量为：");
        scanf("%d",&all);
        printf("请输入学生信息（姓名，学号，科目成绩1，2，3）：\n");
        for(i=0;i<all;i++)
        {
            scanf("%s%d%d%d%d",s[i].nam,&s[i].num,&s[i].score[1],&s[i].score[2],&s[i].score[3]);
        }

    do
    {
        printf("                        欢迎进入学生信息管理系统\n");
        printf("     1 请添加学生信息\n");
        printf("     2 按成绩排序   \n");
        printf("     3 按学号查找   \n");
        printf("     4 统计不及格人数    \n");
        printf("     你选择的操作是：    \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:all=add(all);
                  break;
            case 2:sort();
                    break;
            case 3:search();
                    break;
            case 4:no();
                    break;
            case 0:choice=0;
                break;
        }
    }
    while(choice);
    return 0;
}
