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
    printf("������ѧ����Ϣ��������ѧ�ţ���Ŀ�ɼ�1��2��3����");
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
        printf("������%d ������%s ѧ�ţ�%d ��Ŀһ��%d ��Ŀ����%d ��Ŀ��:%d �ܳɼ���%d\n",i+1,s[i].nam,s[i].num,s[i].score[1],s[i].score[2],s[i].score[3],s[i].score[0]);
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
    printf("������%s ѧ�ţ�%d��Ŀһ��%d ��Ŀ����%d ��Ŀ����%d �ܷ֣�%d\n",s[i].nam,s[i].num,s[i].score[1],s[i].score[2],s[i].score[3],s[i].score[0]);
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
        printf("�����ѧ����Ϣ��ѧ��������Ϊ��");
        scanf("%d",&all);
        printf("������ѧ����Ϣ��������ѧ�ţ���Ŀ�ɼ�1��2��3����\n");
        for(i=0;i<all;i++)
        {
            scanf("%s%d%d%d%d",s[i].nam,&s[i].num,&s[i].score[1],&s[i].score[2],&s[i].score[3]);
        }

    do
    {
        printf("                        ��ӭ����ѧ����Ϣ����ϵͳ\n");
        printf("     1 �����ѧ����Ϣ\n");
        printf("     2 ���ɼ�����   \n");
        printf("     3 ��ѧ�Ų���   \n");
        printf("     4 ͳ�Ʋ���������    \n");
        printf("     ��ѡ��Ĳ����ǣ�    \n");
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
