#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
# define MAXLEN 5000
typedef struct yezhu_stype
{
	int num;
	char name[20];
	char phone[20];
	int home;
	char unite[20];
	int ele;
	int water;
	int hfee;
	int wfee;
}yezhu;
int input(yezhu yz[]);
int openfile(yezhu yz[]);
void output(yezhu yz[],int n);
int seqsearch1(yezhu yz[],int n,int search_num);
int seqsearch2(yezhu yz[],int n,char search_name[]);
void seqdelete(yezhu yz[],int * len);
void revise(yezhu yz[],int n);
void sort(yezhu yz[],int n);
void save(yezhu yz[],int n);
void seqinsert(yezhu yz[],int * len);
void main()
{
	yezhu yz[MAXLEN];
	int sel,choice,password,xz,xz1;
	int n,* len=&n,i;
	int search_num;
	char search_name[20];
	char message[]={"************************************************************\n""                              欢迎使用物业管理系统                              \n""************************************************************\n"};
	char menu[]={"************************************************************\n""                             *1.输入用户信息                              \n""                             *2.输出用户信息                              \n""                             *3.查找用户信息                              \n""                             *4.插入用户信息                              \n""                             *5.删除用户信息                              \n""                             *6.修改用户信息                              \n""                             *7.用户信息排序                              \n""                             *8.存盘                                  \n""                             *0.退出                                  \n""************************************************************\n"};
	char menu1[]={"************************************************************\n""                             *1.输出用户信息                              \n""                             *2.查找用户信息                              \n""                             *3.载入用户信息                              \n""                             *0.退出                                  \n""************************************************************\n"};
	char menu2[]={"----------------1.再次输入密码（再次错误会推出系统！）\n""----------------2.取消登陆\n"};
	char xuan[]={"************************************************************\n""                              *1.普通用户查看                              \n""                              *2.管理人员查看                              \n""************************************************************\n"};
	system("color 30");
	printf("%s",xuan);
	printf("请输入您的选择：\n");
	scanf("%d",&xz);
	switch(xz)
{
case 1:
    {
        system("cls");
        	    printf("%s",message);
		printf("%s",menu1);
		printf("请在0-3中选择\n");
		scanf("%d",&sel);
		system("cls");
		switch(sel)
		{
			case 1:
			    system("cls");
				output(yz,n);
				break;
			case 2:
			    system("cls");
				do
				{
			printf("1***********************按业主编号查找*************************\n");
			printf("2***********************按业主姓名查找*************************\n");
			printf("0***********************返回前一级菜单*************************\n");
			printf("请输入您的选择：\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				printf("请输入查找业主的业主编号：");
				scanf("%d",&search_num);
				i=seqsearch1(yz,n,search_num);
				if(i==-1)
					printf("查无此人！\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("编号 姓名    电话    房号 工作单位 用电量 用水量 物业费 水电费\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 2:
			    system("cls");
				printf("请输入查找业主的业主姓名：");
				scanf("%s",search_name);
				i=seqsearch2(yz,n,search_name);
				if(i==-1)
					printf("查无此人！\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("编号 姓名    电话    房号 工作单位 用电量 用水量 物业费 水电费\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
            case 3:
                {
                    system("cls");
                    n=openfile(yz);
                }
                break;


			case 0:
			    system("cls");
				exit(1);
			}
				}while(choice!=0);
				break;
			case 0:exit(1);
		}
		break;
	}



    case 2:
    {
        system("cls");
    printf("请输入操作密码：\n");
    scanf("%d",&password);
    	if(password!=123)
	{
	    system("cls");
	    printf("密码错误！\n");
	    printf("%s",menu2);
	    printf("请输入您的选择：\n");
	    scanf("%d",&xz1);
	    switch(xz1)
	    {
            case 1:
                system("cls");
                printf("password=\n");
                scanf("%d",&password);
                switch(password)
            {
                case 123:
                	{
	    printf("%s",message);
	do
	{
		printf("%s",menu);
		printf("请在0-8中选择\n");
		scanf("%d",&sel);
		system("cls");
		switch(sel)
		{
		case 1:
			printf("1-------------键盘输入\n");
			printf("2-------------文件录入\n");
			printf("请选择1或2：\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				n=input(yz);
				break;
			case 2:
			    system("cls");
				n=openfile(yz);
				break;
			}
			break;
			case 2:
			    system("cls");
				output(yz,n);
				break;
			case 3:
			    system("cls");
				do
				{
			printf("1***********************按业主编号查找*************************\n");
			printf("2***********************按业主姓名查找*************************\n");
			printf("0***********************返回前一级菜单*************************\n");
			printf("请输入您的选择：\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				printf("请输入查找业主的业主编号：");
				scanf("%d",&search_num);
				i=seqsearch1(yz,n,search_num);
				if(i==-1)
					printf("查无此人！\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("编号 姓名    电话    房号 工作单位 用电量 用水量 物业费 水电费\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 2:
			    system("cls");
				printf("请输入查找业主的业主姓名：");
				scanf("%s",search_name);
				i=seqsearch2(yz,n,search_name);
				if(i==-1)
					printf("查无此人！\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("编号 姓名    电话    房号 工作单位 用电量 用水量 物业费 水电费\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 0:
			    system("cls");
				break;
			}
				}while(choice!=0);
				break;
			case 4:
			    system("cls");
				seqinsert(yz,len);
				break;
			case 5:
			    system("cls");
				seqdelete(yz,len);
				break;
			case 6:
			    system("cls");
				revise(yz,n);
				break;
			case 7:
			    system("cls");
				sort(yz,n);
				break;
			case 8:
			    system("cls");
				save(yz,n);
				break;
			case 0:exit(1);
		}
	}while(sel!=0);
                	}
	;
                break;
                default:exit(1);
            }
                case 2:
                    system("cls");
                    exit(1);
	    }
	}
    do
	{
	    printf("%s",message);
	do
	{
		printf("%s",menu);
		printf("请在0-8中选择\n");
		scanf("%d",&sel);
		system("cls");
		switch(sel)
		{
		case 1:
			printf("1-------------键盘输入\n");
			printf("2-------------文件录入\n");
			printf("请选择1或2：\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				n=input(yz);
				break;
			case 2:
			    system("cls");
				n=openfile(yz);
				break;
			}
			break;
			case 2:
			    system("cls");
				output(yz,n);
				break;
			case 3:
			    system("cls");
				do
				{
			printf("1***********************按业主编号查找*************************\n");
			printf("2***********************按业主姓名查找*************************\n");
			printf("0***********************返回前一级菜单*************************\n");
			printf("请输入您的选择：\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				printf("请输入查找业主的业主编号：");
				scanf("%d",&search_num);
				i=seqsearch1(yz,n,search_num);
				if(i==-1)
					printf("查无此人！\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("编号 姓名    电话    房号 工作单位 用电量 用水量 物业费 水电费\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 2:
			    system("cls");
				printf("请输入查找业主的业主姓名：");
				scanf("%s",search_name);
				i=seqsearch2(yz,n,search_name);
				if(i==-1)
					printf("查无此人！\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("编号 姓名    电话    房号 工作单位 用电量 用水量 物业费 水电费\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 0:
			    system("cls");
				break;
			}
				}while(choice!=0);
				break;
			case 4:
			    system("cls");
				seqinsert(yz,len);
				break;
			case 5:
			    system("cls");
				seqdelete(yz,len);
				break;
			case 6:
			    system("cls");
				revise(yz,n);
				break;
			case 7:
			    system("cls");
				sort(yz,n);
				break;
			case 8:
			    system("cls");
				save(yz,n);
				break;
			case 0:exit(1);
		}
	}while(sel!=0);
	}while(password==123);
    break;
    };
}
}
int input(yezhu yz[])
{
	int i=0,n=0;
	printf("请依次输入业主信息\n");
	printf("业主编号（编号为-1结束输入）：\n");
	scanf("%d",&yz[i].num);
	while(yz[i].num!=-1)
	{
		printf("业主姓名：");
		scanf("%s",yz[i].name);
		printf("业主电话：");
		scanf("%s",yz[i].phone);
		printf("业主房号：");
		scanf("%d",&yz[i].home);
		printf("业主工作单位：");
		scanf("%s",yz[i].unite);
		printf("用电量：");
		scanf("%d",&yz[i].ele);
		printf("用水量：");
		scanf("%d",&yz[i].water);
		printf("物业费：");
		scanf("%d",&yz[i].hfee);
		printf("水电费：");
		scanf("%d",&yz[i].wfee);
		i++;
		n++;
		printf("业主编号（编号为-1结束输入）：\n");
		scanf("%d",&yz[i].num);
	}
	return n;
}
int openfile(yezhu yz[])
{
	int i=0;
	FILE * fp2;
	fp2=fopen("e:\\信息表.txt","r"); /*打开已有信息表*/
	if(fp2==NULL)
	{
		printf("未找到该文件！\n");
		return 0;
	}
	else
	{
		while(! feof(fp2))
		{
			fscanf(fp2,"%d%s%s%d%s%d%d%d%d",&yz[i].num,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
			i++;
		}
		fclose(fp2);
		printf("载入成功\n");
		return i;
	}
}
void output(yezhu yz[],int n)
{
	int i;
	printf("----------------------------------------------------------------------\n");
	printf("                              物业管理信息表                           \n");
	printf("----------------------------------------------------------------------\n");
	printf("编号 姓名    电话    房号 工作单位 用电量 用水量 物业费 水电费\n");
	for(i=0;i<n;i++)
		printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
	printf("----------------------------------------------------------------------\n");
}
int seqsearch1(yezhu yz[],int n,int search_num)
{
	int i=n-1;
	while(i>=0&&yz[i].num!=search_num)
		i--;
	return i;
}
int seqsearch2(yezhu yz[],int n,char search_name[])
{
	int i=n-1;
	while(i>=0&&(strcmp(yz[i].name,search_name)!=0))
		i--;
	return i;
}
void seqinsert(yezhu yz[],int * len)
{
	int j,k,insert_num,choice;
	char insert_name[20];
	yezhu ins_yezhu;
	if(* len==MAXLEN-1)
		printf("用户已满！");
	else
	{
		do
		{
			printf("1***********************按业主编号插入*************************\n");
			printf("2***********************按业主姓名插入*************************\n");
			printf("0***********************返回前一级菜单*************************\n");
			printf("请输入您的选择：\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				printf("请输入插入位置（插入某业主编号前）：\n");
				scanf("%d",&insert_num);
				k=seqsearch1(yz,* len,insert_num);
				if(k==-1)
					printf("无效的插入位置！\n");
				else
				{
                    printf("请输入插入信息：\n");
					printf("编号  姓名     电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
					scanf("%d%s%s%d%s%d%d%d%d",&ins_yezhu.num,ins_yezhu.name,ins_yezhu.phone,&ins_yezhu.home,ins_yezhu.unite,&ins_yezhu.ele,&ins_yezhu.water,&ins_yezhu.hfee,&ins_yezhu.wfee);
					for(j=* len-1;j>=k;j--)
						yz[j+1]=yz[j];
					yz[k]=ins_yezhu;
					(* len)++;
					printf("插入成功！\n");
				}
				break;
			case 2:
				printf("请输入插入位置（插入某业主姓名之前）：\n");
				scanf("%s",insert_name);
				k=seqsearch2(yz,* len,insert_name);
				if(k==-1)
					printf("无效的插入位置！\n");
				else
				{
                    printf("请输入插入信息：\n");
					printf("编号  姓名     电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
					scanf("%d%s%s%d%s%d%d%d%d",&ins_yezhu.num,ins_yezhu.name,ins_yezhu.phone,&ins_yezhu.home,ins_yezhu.unite,&ins_yezhu.ele,&ins_yezhu.water,&ins_yezhu.hfee,&ins_yezhu.wfee);
					for(j=* len-1;j>=k;j--)
						yz[j+1]=yz[j];
					yz[k]=ins_yezhu;
					(* len)++;
					printf("插入成功！\n");
				}
				break;
			case 0:
				break;
			}
		}while(choice=0);
	}
}
void seqdelete(yezhu yz[],int * len)
{
	int j,k,choice;
	char delete_name[20];
	int delete_num;
	if(* len==0)
		printf("用户已空！");
	else
	{
		do
		{
			printf("1***********************按业主编号删除*************************\n");
			printf("2***********************按业主姓名删除*************************\n");
			printf("0***********************返回前一级菜单*************************\n");
			printf("请输入您的选择：\n");
			scanf("%d",&choice);
			system("cls");
			switch(choice)
			{
			case 1:printf("请输入删除业主的业主编号：");
				   scanf("%d",&delete_num);
				   k=seqsearch1(yz,* len,delete_num);
				   if(k==-1)
					   printf("无效的删除位置！\n");
				   else
				   {
					   for(j=k+1;j<* len;j++)
						   yz[j-1]=yz[j];
					   (*len)--;
					   printf("删除成功！\n");
				   }
				   break;
			case 2:printf("请输入删除业主的业主姓名：");
				   scanf("%s",delete_name);
				   k=seqsearch2(yz,* len,delete_name);
				   if(k==-1)
					   printf("无效的删除位置！\n");
				   else
				   {
					   for(j=k+1;j<* len;j++)
						   yz[j-1]=yz[j];
					   (*len)--;
					   printf("删除成功！\n");
				   }
				   break;
			case 0:break;
			}
		}while(choice!=0);
	}
}
void revise(yezhu yz[],int n)
{
	int knum,k,choice;
	char kname[20];
	do
	{
			printf("1***********************按业主编号修改*************************\n");
			printf("2***********************按业主姓名修改*************************\n");
			printf("0***********************返回前一级菜单*************************\n");
			printf("请输入您的选择：\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:printf("请输入修改业主的业主编号：");
				   scanf("%d",&knum);
				   k=seqsearch1(yz,n,knum);
				   if(k==-1)
					   printf("查无此人！\n");
				   else
				   {
					printf("请输入修改信息：\n");
					printf("编号  姓名     电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].num,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,yz[k].water,&yz[k].hfee,&yz[k].wfee);
					   printf("修改成功！\n");
				   }
				   break;
			case 2:printf("请输入修改业主的业主姓名：");
				   scanf("%s",kname);
				   k=seqsearch2(yz,n,kname);
				   if(k==-1)
					   printf("查无此人！\n");
				   else
				   {
					printf("请输入修改信息：\n");
					printf("编号  姓名     电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].num,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,yz[k].water,&yz[k].hfee,&yz[k].wfee);
					printf("修改成功！\n");
				   }
				   break;
			case 0:
				break;
			}
		}while(choice!=0);
	}


void sort(yezhu yz[],int n)
{
	int i,j,k,choice;
	yezhu t;
	do
	{
			printf("1***********************按业主编号排序*************************\n");
			printf("2***********************按业主姓名排序*************************\n");
			printf("0***********************返回前一级菜单*************************\n");
			printf("请输入您的选择：\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				for(i=0;i<n-1;i++)
				{
					k=i;
					for(j=i+1;j<n;j++)
						if(yz[k].num>yz[j].num)
							k=j;
						if(i!=k)
						{
							t=yz[k];
							yz[k]=yz[i];
							yz[i]=t;
						}
				}
				output(yz,n);
				   break;
			case 2:
				for(i=0;j<n-1;i++)
				{
					k=i;
					for(j=i+1;j<n;j++)
						if(strcmp(yz[k].name,yz[j].name)>0)
							k=j;
						if(i!=k)
						{
							t=yz[k];
							yz[k]=yz[i];
							yz[i]=t;
						}
				}
				output(yz,n);
				   break;
			case 0:break;
			}
		}while(choice!=0);
	}



void save(yezhu yz[],int n)
{
	int i;
	FILE * fp1;
	fp1=fopen("e:\\信息表.txt","a+");
	if(fp1==NULL)
		printf("保存失败\n");
	else
	{
		for(i=0;i<n;i++)
			fprintf(fp1,"%2d%6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
		fclose(fp1);
		printf("保存成功\n");
	}
}
