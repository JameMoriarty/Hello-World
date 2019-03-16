/*学籍管理系统包括了学生的基本信息与各科目成绩。学生以班级为单位，
每个学生是一个纪录，包括学院、班级、学号、姓名、性别、出生年月、家庭住址、
C语言成绩、高数成绩、英语成绩等。系统登录后可计算平均分，可按学号或成绩 排序，
可统计 90 分、80 分、70 分、60 分以及不及格的学生名单。能查询 单个学生的信息。
要求： 能够添加一个班的必要信息，能进行补充、修订、删除，并能进行统计计算。
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
struct student
{
    char school[100];         //学院
    char cla[100];            //班级
    char num[100];            //学号
    char name[100];           //姓名
    char sex[10];             //性别
    char born[100];           //出生日期
    char address[100];        //家庭地址
    int cs;                   //c语言成绩
    int ms;                   //高数成绩
    int es;                   //英语成绩
    int ave;                  //平均成绩
};
void caidan();           //打印菜单
int input (struct student stu[]);            //输入信息
void output (struct student stu[],int p);    //输出
void sort(struct student stu[],int p);       //排序
void statistics(struct student stu[],int p);  //统计
void search(struct student stu[],int p);      //查询
void change(struct student stu[],int p);      //修改
void sdelete(struct student stu[],int p);     //删除
int main()
{
    struct student stu[1000];
    int a=1;

    while (a!=0)
    {
        int p=0;

        system("cls");
        caidan();

        scanf("%d",&a);
        FILE *fp1;
        fp1=fopen("e:\\学籍表.txt","r");
        while (!feof(fp1))                 //判断文件内学生人数
        {
            fscanf(fp1,"%s %s %s %s %s %s %s %d %d %d %d\n",stu[p].school,stu[p].cla,stu[p].num,stu[p].name,stu[p].sex,stu[p].born,stu[p].address,&stu[p].cs,&stu[p].ms,&stu[p].es,&stu[p].ave);
            p++;
        }
        fclose(fp1);
        switch(a)
        {
            case 1: input (stu);  break;               //输入
            case 2: sort(stu,p); break;                //排序
            case 3: statistics(stu,p); break;          //统计
            case 4: search(stu,p); break;              //查询
            case 5: change(stu,p); break;              //修改
            case 6: sdelete(stu,p); break;              //删除
            case 7: output (stu,p); break;             //查看

        }
    }


    return 0;
}
void caidan()
{
    HANDLE hOut;
    COORD pos= {20,3}; // 光标的起始位（第11列，第8行） 0是第1列 2是第3行//
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
    printf("*******欢迎使用西安理工学籍管理系统*******");
    COORD pos1= {29,5}; // 光标的起始位（第11列，第8行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, pos1);
    printf("1  输入学生信息");
    COORD pos2= {29,7}; // 光标的起始位（第11列，第8行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, pos2);
    printf("2  排序学生信息");
    COORD pos3= {29,9}; // 光标的起始位（第11列，第8行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, pos3);
    printf("3  按分数统计学生名单");
    COORD pos4= {29,11}; // 光标的起始位（第11列，第8行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, pos4);
    printf("4  查询学生信息");
    COORD pos5= {29,13}; // 光标的起始位（第11列，第8行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, pos5);
    printf("5  修改学生信息");
    COORD pos6= {29,15}; // 光标的起始位（第11列，第8行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, pos6);
    printf("6  删除学生信息");
    COORD pos8= {29,17}; // 光标的起始位（第11列，第8行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, pos8);
    printf("7  查看学生信息");
    COORD pos7= {20,19}; // 光标的起始位（第11列，第8行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, pos7);
    printf("*******输入对应序号选择功能(输入0退出系统)*******\n");
}
int input (struct student stu[])               //输入信息
{
    system("cls");
    FILE *fp;
    int i=0,b=1;
    fp=fopen("e:\\学籍表.txt","a");
    printf("\n             请输入学生信息(输入-1结束输入)\n");
    while (1)
    {
        printf("             序号：");
        scanf("%d",&b);
        if (b==-1)
            break;
        printf("             学院：");
        scanf("%s",stu[i].school);
        printf("             班级：");
        scanf("%s",stu[i].cla);
        printf("             学号：");
        scanf("%s",stu[i].num);
        printf("             姓名：");
        scanf("%s",stu[i].name);
        printf("             性别：");
        scanf("%s",stu[i].sex);
        printf("             出生日期：");
        scanf("%s",stu[i].born);
        printf("             家庭地址：");
        scanf("%s",stu[i].address);
        printf("             c语言成绩：");
        scanf("%d",&stu[i].cs);
        printf("             高数成绩：");
        scanf("%d",&stu[i].ms);
        printf("             英语成绩：");
        scanf ("%d",&stu[i].es);
        stu[i].ave=(stu[i].cs+stu[i].ms+stu[i].es)/3;
   //     FILE=fopen("e:\\学籍表.txt","w");
        fprintf(fp ,"\n%s %s %s %s %s %s %s %d %d %d %d",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
        i++;
    }
    fclose(fp);
    return i;
}
void output (struct student stu[],int p)          //输出函数
{
    system("cls");
    FILE *fp;
    int i=0;
    fp=fopen("e:\\学籍表.txt","r");
    printf("     ******学籍表******\n");
    printf("学院 班级 学号 姓名 性别 出生日期 家庭住址 c语言成绩 高数成绩 英语成绩 平均成绩\n");
    for (i=0;i<p;i++)
    {
        fscanf(fp,"%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,&stu[i].cs,&stu[i].ms,&stu[i].es,&stu[i].ave);

    }
    for (i=0;i<p;i++)
    {
        printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);

    }
    fclose(fp);
    system("pause");
}
void sort(struct student stu[],int p)
{
    system("cls");
    FILE *fp;
    int i=0;
    fp=fopen("e:\\学籍表.txt","r");
    for (i=0;i<=p;i++)
    {
        fscanf(fp,"%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,&stu[i].cs,&stu[i].ms,&stu[i].es,&stu[i].ave);
    }
    printf("\n\t按成绩排序请输入 1\n\n\t按学号排序请输入 2\n\t");
    int b;
    scanf("%d",&b);
    switch (b)
    {
        case 1:
        {
            for (i=0;i<p;i++)
            {
                int j=0;
                struct student t;
                for (j=0;j<p;j++)
                {
                    if (stu[i].ave<stu[j].ave)
                    {
                        t=stu[i];
                        stu[i]=stu[j];
                        stu[j]=t;
                    }
                }
            }
            for (i=0;i<p;i++)
            {
                printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
            }
            fclose(fp);
        }
        case 2:
        {
                for (i=0;i<p;i++)
            {
                int j=0;
                struct student t;
                for (j=0;j<p;j++)
                {
                    if (stu[i].num<stu[j].num)
                    {
                        t=stu[i];
                        stu[i]=stu[j];
                        stu[j]=t;
                    }
                }
            }
            for (i=0;i<p;i++)
            {
                printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
            }
            fclose(fp);

            }

    }
    system("pause");

}
void statistics(struct student stu[],int p)        //统计
{
    system("cls");
    FILE *fp;
    int i=0;
    fp=fopen("e:\\学籍表.txt","r");
    for (i=0;i<=p;i++)
    {
        fscanf(fp,"%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,&stu[i].cs,&stu[i].ms,&stu[i].es,&stu[i].ave);
    }int b=9;
    while (b!=0)
    {
        printf("\n\t**1 按c语言成绩统计**\n\t**2 按高数成绩统计**\n\t**3 按英语成绩统计**\n\t**0 返回上一级菜单**\n");

        scanf("%d",&b);

             switch (b)
        {
        case 1:
            {
                int c=0;
                printf("请输入要统计的分数：\t");
                scanf("%d",&c);
                for (i=0;i<p;i++)
                {
                    if (stu[i].cs==c)
                        printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
                }
                fclose(fp);
                break;
            }
        case 2:
            {
                int c=0;
                 printf("请输入要统计的分数：\t");
                scanf("%d",&c);
                for (i=0;i<p;i++)
                {
                    if (stu[i].ms==c)
                        printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
                }
                fclose(fp);
                break;
            }
        case 3:
            {
                int c=0;
                printf("请输入要统计的分数：\t");
                scanf("%d",&c);
                for (i=0;i<p;i++)
                {
                    if (stu[i].cs==c)
                        printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
                }
                fclose(fp);
                break;
            }

        }
    }

    system("pause");
}
void search(struct student stu[],int p)                 //查询    //有错！！！
{
    system("cls");
    FILE *fp;
    int i=0;
    fp=fopen("e:\\学籍表.txt","r");
    for (i=0;i<=p;i++)
    {
        fscanf(fp,"%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,&stu[i].cs,&stu[i].ms,&stu[i].es,&stu[i].ave);
    }int b=9;
    while (b!=0)
    {
        printf("\n\t**1 按姓名查询**\n\t**2 按学号查询**\n\t**0 返回上一级菜单**\n\t");

        scanf("%d",&b);

        switch (b)
        {
            case 1:
            {
                char ch[100];
                printf("\t输入要查询的姓名:");
                scanf("%s",ch);
                for (i=0;i<p;i++)
                {
                    if (strcmp (stu[i].name,ch)==0)
                        printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
                }
                fclose(fp);
                break;
            }
            case 2:
                {
                    char ch[100];
                    printf("\t输入要查询的学号:");
                    scanf("%s",ch);
                    for (i=0;i<p;i++)
                    {
                        if (strcmp(stu[i].num,ch)==0)
                            printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
                    }
                    fclose(fp);
                    break;

                }
        }
    }

    system("pause");
}
void change(struct student stu[],int p)             //修改
{
    system("cls");
    FILE *fp;
    int i=0;
    fp=fopen("e:\\学籍表.txt","r");
    for (i=0;i<=p;i++)
    {
        fscanf(fp,"%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,&stu[i].cs,&stu[i].ms,&stu[i].es,&stu[i].ave);
    }
    fclose(fp);
    int b=9;
    while (b!=0)
    {
        printf("\n\t**1 按姓名查询要修改的学生信息**\n\t**2 按学号查询要修改的学生信息**\n\t**0 返回上一级菜单**\n\t");

        scanf("%d",&b);

        switch (b)
        {
            case 1:
            {
                char ch[100];
                printf("\t输入要查询的姓名:");
                scanf("%s",ch);
                fp=fopen("e:\\学籍表.txt","w");
                for (i=0;i<p;i++)
                {
                   // printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
                    if (strcmp (stu[i].name,ch)==0)
                    {
                        printf("\t输入要修改的信息：\n");
                        printf("             学院：");
                        scanf("%s",stu[i].school);
                        printf("             班级：");
                        scanf("%s",stu[i].cla);
                        printf("             学号：");
                        scanf("%s",stu[i].num);
                        printf("             姓名：");
                        scanf("%s",stu[i].name);
                        printf("             性别：");
                        scanf("%s",stu[i].sex);
                        printf("             出生日期：");
                        scanf("%s",stu[i].born);
                        printf("             家庭地址：");
                        scanf("%s",stu[i].address);
                        printf("             c语言成绩：");
                        scanf("%d",&stu[i].cs);
                        printf("             高数成绩：");
                        scanf("%d",&stu[i].ms);
                        printf("             英语成绩：");
                        scanf ("%d",&stu[i].es);
                        stu[i].ave=(stu[i].cs+stu[i].ms+stu[i].es)/3;
                   //     FILE=fopen("e:\\学籍表.txt","w");

                    }
                    fprintf(fp ,"\n%s %s %s %s %s %s %s %d %d %d %d",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);


                }
                fclose(fp);
                break;
            }
            case 2:
                {
                    char ch[100];
                    printf("\t输入要查询的学号:");
                    scanf("%s",ch);
                    fp=fopen("e:\\学籍表.txt","w");
                    for (i=0;i<p;i++)
                    {
                        if (strcmp(stu[i].num,ch)==0)
                        {
                            printf("\t输入要修改的信息：\n");
                            printf("             学院：");
                            scanf("%s",stu[i].school);
                            printf("             班级：");
                            scanf("%s",stu[i].cla);
                            printf("             学号：");
                            scanf("%s",stu[i].num);
                            printf("             姓名：");
                            scanf("%s",stu[i].name);
                            printf("             性别：");
                            scanf("%s",stu[i].sex);
                            printf("             出生日期：");
                            scanf("%s",stu[i].born);
                            printf("             家庭地址：");
                            scanf("%s",stu[i].address);
                            printf("             c语言成绩：");
                            scanf("%d",&stu[i].cs);
                            printf("             高数成绩：");
                            scanf("%d",&stu[i].ms);
                            printf("             英语成绩：");
                            scanf ("%d",&stu[i].es);
                            stu[i].ave=(stu[i].cs+stu[i].ms+stu[i].es)/3;
                       //     FILE=fopen("e:\\学籍表.txt","w");

                        }
                         fprintf(fp ,"\n%s %s %s %s %s %s %s %d %d %d %d",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);

                    }
                    fclose(fp);
                    break;

                }
        }
    }

    system("pause");
}
void sdelete(struct student stu[],int p)
{
    system("cls");
    FILE *fp;
    int i=0;
    fp=fopen("e:\\学籍表.txt","r");
    for (i=0;i<=p;i++)
    {
        fscanf(fp,"%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,&stu[i].cs,&stu[i].ms,&stu[i].es,&stu[i].ave);
    }
    fclose(fp);
    int b=9;
    while (b!=0)
    {
        printf("\n\t**1 按姓名查询要删除的学生信息**\n\t**2 按学号查询要删除的学生信息**\n\t**0 返回上一级菜单**\n\t");

        scanf("%d",&b);

        switch (b)
        {
            case 1:
            {
                char ch[100];
                printf("\t输入要删除的姓名:");
                scanf("%s",ch);
                fp=fopen("e:\\学籍表.txt","w");
                int n=0;
                for (i=0;i<p;i++)
                {
                   // printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
                    if (strcmp (stu[i].name,ch)==0)
                    {
                        n=i;
                    }
                }
                for (i=0;i<p;i++)
                {
                    if (i>=n)
                    {
                        stu[i]=stu[i+1];
                    }
                    fprintf(fp ,"\n%s %s %s %s %s %s %s %d %d %d %d",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);

                }
                fclose(fp);
                printf("\n\t删除成功！\n");
                break;
            }
            case 2:
                {
                    char ch[100];
                    printf("\t输入要删除的学号:");
                    scanf("%s",ch);
                    fp=fopen("e:\\学籍表.txt","w");
                    int n=0;
                    for (i=0;i<p;i++)
                    {
                       // printf("%s %s %s %s %s %s %s %d %d %d %d\n",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);
                        if (strcmp (stu[i].name,ch)==0)
                        {
                            n=i;
                        }
                    }
                    for (i=0;i<p;i++)
                    {
                        if (i>=n)
                        {
                            stu[i]=stu[i+1];
                        }
                        fprintf(fp ,"\n%s %s %s %s %s %s %s %d %d %d %d",stu[i].school,stu[i].cla,stu[i].num,stu[i].name,stu[i].sex,stu[i].born,stu[i].address,stu[i].cs,stu[i].ms,stu[i].es,stu[i].ave);

                    }
                    fclose(fp);
                    printf("\n\t删除成功！\n");
                    break;
                }
        }
    }
}
