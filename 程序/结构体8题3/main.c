#include <stdio.h>
#include <stdlib.h>
struct memb_type
{
    long int num;
    char name[50];
    int age;
    union
    {
        int score;
        char level;
    }category;
};

int main()
{
    int i,n,t=0,a=0,s;
    printf("������μӼ�������Ե�ְ��������\n");
    scanf("%d",&n);
    struct memb_type person[n];
    for (i=0;i<n;i++)
    {
        printf("������׼��֤�� ���� ����\n");
        scanf("%ld %s %d",&person[i].num,person[i].name,&person[i].age);
        if (person[i].age<30)
        {
            printf("��������Գɼ���\n");
            scanf("%d",&person[i].category.score);
            if (person[i].category.score>60)
               {
                   t++;
               }
        }
        else if (person[i].age>=30)
        {
            printf("����������ɼ���\n");
            scanf("%s",&person[i].category.level);
            if (person[i].category.level<'C')
               {
                   a++;
               }
        }
    }
    s=a+t;
    printf("��������%d\n",s);
    printf("׼��֤��    ����    ����    �ɼ�\n");
    for (i=0;i<n;i++)
    {
        if (person[i].age<30)
            printf("%-5ld %8s%8d%8d\n",person[i].num,person[i].name,person[i].age,person[i].category.score);
        else
            printf("%-5ld %8s%8d%8c\n",person[i].num,person[i].name,person[i].age,person[i].category.level);
    }
    return 0;
}
