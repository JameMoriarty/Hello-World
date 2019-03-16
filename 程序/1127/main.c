#include<stdio.h>
#include<malloc.h>
#define PEOPLE 3
//定义 1st



//定义3rd
typedef struct student
{
    int ID;
    int name[20];
    int score;

} stu;  //对应main函数里用stu 变量，即可定义。


//结构体的定义。把基础的数据类型综合起来用，定义一个结构体可保存多种多个数据。
int main()
{
    int i,ave;
    stu student[PEOPLE]; //主函数定义需要struct 加结构体名称加stu；
    //结构体名称.结构体数据名
    printf("Please input student's ID,Name and Score:");
    for (int i=0;i<PEOPLE;i++)
        scanf("%d %s %f",&student[i].ID,student[i].name,&student[i].score);
    ave=calc_score(student[PEOPLE]);
    printf("The ave is :");
    printf("**Id**name**score**\n");
    for (i=0;i<PEOPLE;i++)
        printf("%d %s %d",student[i].ID,student[i].name,student[i].score);
    return 0;
}
int calc_score(stu student[])
{
    int i,ave=0;
    for (i=0;i<PEOPLE;i++)
        sum+=student[i].score;
    ave=sum/PEOPLE;
    return ave;
}
