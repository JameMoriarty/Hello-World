#include<stdio.h>

#define N 50
int all = 0;
struct student
{
	char name[15];
	int num;
	char sex;
	float scord[3];
	float ave;
	int sort;
};

struct student stu[N];

void  add()
{
	int i;
	printf("������Ҫ��ӵ�ѧ��������\n");
	scanf("%d",&all);
	for(i = 0;i < all ;i++)
	{
		printf("������ѧ�������� ѧ�� �Ա�");
		scanf("%s %d %c",stu[i].name,&stu[i].num,&stu[i].sex);
	}
	for(i = 0;i < all ;i++)
	{
		printf("%s %d %c\n",stu[i].name,stu[i].num,stu[i].sex);
	}
}
void del()
{
    int i;
	printf("������Ҫɾ����ѧ��������\n");
	scanf("%d",&all);
	for(i = 0;i < all ;i++)
	{
		printf("������ѧ�������� ѧ�� �Ա�");
		scanf("%s %d %c",stu[i].name,&stu[i].num,&stu[i].sex);
	}
	for(i = 0;i < all ;i++)
	{
		printf("%s %d %c\n",stu[i-1].name,stu[i-1].num,stu[i-1].sex);
	}

}
void search()
{
    int i;
	printf("������Ҫ���ҵ�ѧ��������\n");
	scanf("%d",&all);
	for(i = 0;i < all ;i++)
	{
		printf("������ѧ����������");
		scanf("%s ",stu[i].name);
	}
	for(i = 0;i < all ;i++)
	{
		printf("%s %d %c\n",stu[i].name,stu[i].num,stu[i].sex);
	}

}
void sort_()
{
    int i;
	printf("������Ҫ�鿴��ѧ��������\n");
	scanf("%d",&all);
	for(i = 0;i < all ;i++)
	{
		printf("������ѧ����ѧ�ţ�");
		scanf("%d",&stu[i].num);
	}
	for(i = 0;i < all ;i++)
	{
		printf("%s %d %c\n",stu[i].name,stu[i].num,stu[i].sex);
	}

}
void print()
{
	int i;
	printf("����ѧ������Ϣ���£�\n");
	for(i = 0;i < all ;i++)
	{
		printf("%s %d %c\n",stu[i].name,stu[i].num,stu[i].sex);
	}
}

int main()
{
	int choice;
	printf("��ӭ����ѧ������ϵͳ��\n");
	printf("\n");
	do{
		printf("*******1.���ѧ��*********\n");
		printf("*******2.ɾ��ѧ��*********\n");
		printf("*******3.����ѧ��*********\n");
		printf("*******4.����ѧ��*********\n");
		printf("*******5.�鿴ѧ��*********\n");
		printf("*******0.�˳�����*********\n");
		printf("��ѡ����Ҫ���еĲ�����\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:add();
			break;
		case 2:del();
			break;
		case 3:search();
			break;
		case 4: sort_();
			break;
		case 5: print();
			break;
		case 0: choice = 0;
			break;
		}
	}while(choice);
	return 0;
}

