#include<stdio.h>
#include<malloc.h>
#define PEOPLE 3
//���� 1st



//����3rd
typedef struct student
{
    int ID;
    int name[20];
    int score;

} stu;  //��Ӧmain��������stu ���������ɶ��塣


//�ṹ��Ķ��塣�ѻ��������������ۺ������ã�����һ���ṹ��ɱ�����ֶ�����ݡ�
int main()
{
    int i,ave;
    stu student[PEOPLE]; //������������Ҫstruct �ӽṹ�����Ƽ�stu��
    //�ṹ������.�ṹ��������
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
