#include <stdio.h>
#include <stdlib.h>
struct stud_type
{
    char name[50];
    int number;
    int score[4];
    int ave;
};
void sort(struct stud_type stu[]);
int main()
{
    struct stud_type stu[11];
    int i,j,ave;
    printf("������ʮ��ѧ������Ϣ��\n���� ѧ�� ���� Ӣ�� c���Գɼ���\n");
    for (i=0;i<10;i++)
    {
        scanf("%c %d",&stu[i].name[50],&stu[i].number);
        for (j=0;j<3;j++)
        {
            scanf("%d",&stu[i].score[j]);
        }
        ave=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3;
    }
    sort(stu);

    return 0;
}

void sort(struct stud_type stu[])
{
    int i,t;
    for (i=0;i<10;i++)
    {
        if (stu[i];ave<stu[i+1];ave)
        {
            t=i;
            i=i+1;
            i+1=t;
        }
    }
    printf("����    ѧ��    ����   Ӣ��    c����     ƽ����\n");
    for (i=0;i<10;i++)
    {
        printf("%c %5d",stu[i].name[50],stu[i].number);
        for (j=0;j<3;j++)
        {
            printf("%5d",stu[i].score[j]);
        }
        printf("\n");
    }

}


