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
	printf("请输入要添加的学生个数：\n");
	scanf("%d",&all);
	for(i = 0;i < all ;i++)
	{
		printf("请输入学生的姓名 学号 性别：");
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
	printf("请输入要删除的学生个数：\n");
	scanf("%d",&all);
	for(i = 0;i < all ;i++)
	{
		printf("请输入学生的姓名 学号 性别：");
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
	printf("请输入要查找的学生个数：\n");
	scanf("%d",&all);
	for(i = 0;i < all ;i++)
	{
		printf("请输入学生的姓名：");
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
	printf("请输入要查看的学生个数：\n");
	scanf("%d",&all);
	for(i = 0;i < all ;i++)
	{
		printf("请输入学生的学号：");
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
	printf("所有学生的信息如下：\n");
	for(i = 0;i < all ;i++)
	{
		printf("%s %d %c\n",stu[i].name,stu[i].num,stu[i].sex);
	}
}

int main()
{
	int choice;
	printf("欢迎进入学籍管理系统！\n");
	printf("\n");
	do{
		printf("*******1.添加学生*********\n");
		printf("*******2.删除学生*********\n");
		printf("*******3.查找学生*********\n");
		printf("*******4.排序学生*********\n");
		printf("*******5.查看学生*********\n");
		printf("*******0.退出程序*********\n");
		printf("请选择你要进行的操作：\n");
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

