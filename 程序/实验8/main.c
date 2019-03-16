#include <stdio.h>
#include <string.h>
struct stud_type
{
    char name[10];
    int num;
    int score[3];
    int sum;
};
int n;
void sort (struct stud_type stu[]);
void search (struct stud_type stu[]);
int over (struct stud_type stu[]);
int main()
{
    int i,t;
    printf("请输入n名学生的信息（姓名 学号 3门课成绩）\nn=");
    scanf("%d",&n);
    struct stud_type stu[n];
    for (i=0;i<n;i++)
    {
        scanf("%s%d%d%d%d",stu[i].name,&stu[i].num,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
    }
    sort(stu);
    printf("排序后：\n");
    for (i=0;i<n;i++)
        printf("%-8s%5d%5d%5d%5d%5d\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum);
    printf("请输入要查找学生的学号：\n");
    search(stu);
    t=over(stu);
    printf("不及格人数%d\n",t);
    return 0;
}

void sort(struct stud_type stu[])
{
    int i,k,j;
    struct stud_type t;
    for (i=0;i<n-1;i++)
    {
        k=i;
        for (j=i+1;j<n;j++)
            if (stu[k].sum<stu[j].sum)
            k=j;
        if (k!=j)
        {
            t=stu[i];
            stu[i]=stu[k];
            stu[k]=t;
        }
    }
}

void search(struct stud_type stu[])
{
    int a,i;
    scanf("%d",&a);
    for (i=0;i<n;i++)
    {
        if (stu[i].num==a)
            printf("%-8s%5d%5d%5d%5d%5d\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum);
    }

}

int over(struct stud_type stu[])
{
    int i,t=0;
    for (i=0;i<n;i++)
    {
        if (stu[i].score[0]<60||stu[i].score[1]<60||stu[i].score[2]<60)
            t++;
    }
    return t;
}
