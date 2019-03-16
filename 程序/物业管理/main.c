#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
# define MAXLEN 5000
typedef struct yezhu_stype       // 龚文青
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
void frist();
int main()            //  龚文青
{
    frist();
	yezhu yz[MAXLEN];
	int sel,choice,sel1,sel2,password,key;
	int n,* len=&n,i;
	int search_num;
	char search_name[20];
	char message[]={"\n""\n""\n""                       **********************************\n""\n""                              欢迎使用物业管理系统                              \n""\n""                       **********************************\n"};
	char menu[]={"                       *****************************\n""\n""                             *1.输入用户信息                              \n""\n""                             *2.输出用户信息                              \n""\n""                             *3.查找用户信息                              \n""\n""                             *4.插入用户信息                              \n""\n""                             *5.删除用户信息                              \n""\n""                             *6.修改用户信息                              \n""\n""                             *7.用户信息排序                              \n""\n""                             *8.存盘                                  \n""\n""                             *0.退出                                  \n""\n""                       *****************************\n"};
	while(1)
    {
	system("color 30");
	printf("%s",message);
	printf("\n");
	printf("\n");
	printf("                                 1.管理人员登录\n");
	printf("\n");
	printf("                                 2.普通业主查询\n");
	printf("\n");
	printf("                                 0.退出\n");
	printf("\n");
	printf("                                 请输入您的选择：");
	scanf("%d",&sel1);
        switch(sel1)
	{
   case 1:
    {
        system("cls");
        printf("\n\n\n\n                      请输入登录密码：");
        scanf(" %d",&password);
        if(password!=123)
        {
            for(key=4;key>0;key--)
            {
                system("cls");
                printf("\n\n         密码错误！（您还有%d次机会）请再次输入：",key-1);
                scanf("%d",&password);
                if(password==123)
                   {
                    	do
	{
		printf("%s",menu);
		printf("\n");
		printf("                             请在0-8中选择");
		scanf("%d",&sel);
		system("cls");
		switch(sel)
		{
		case 1:
		    printf("                       **********************************\n");
		    printf("\n");
			printf("                            1-------------键盘输入\n");
			printf("\n");
			printf("                            2-------------文件录入\n");
			printf("\n");
			printf("                       **********************************\n");
			printf("\n");
			printf("                                请选择1或2：");
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
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************按业主编号查找*************************\n");
                     printf("\n");
                    printf("                   2***********************按业主姓名查找*************************\n");
                     printf("\n");
			        printf("                   0***********************返回前一级菜单*************************\n");
			         printf("\n");
			        printf("                                          请输入您的选择：");
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
					printf("查找用户为：\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
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
					printf("查找用户为：\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
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
			case 0:break;
		}
	}while(sel!=0);
	break;
}

                while(key==2)
                {
                    system("cls");
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("                         对不起！您错误太多！请退出重试！\n");
                    printf("\n");
                    exit(1);
                }
            }



        }
        else
        {
          	do
	{
		printf("%s",menu);
		printf("\n");
		printf("                             请在0-8中选择");
		scanf("%d",&sel);
		system("cls");
		switch(sel)
		{
		case 1:
		    printf("                       **********************************\n");
		    printf("\n");
			printf("                            1-------------键盘输入\n");
			printf("\n");
			printf("                            2-------------文件录入\n");
			printf("\n");
			printf("                       **********************************\n");
			printf("\n");
			printf("                                请选择1或2：");
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
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************按业主编号查找*************************\n");
                     printf("\n");
                    printf("                   2***********************按业主姓名查找*************************\n");
                     printf("\n");
			        printf("                   0***********************返回前一级菜单*************************\n");
			         printf("\n");
			        printf("                                          请输入您的选择：");
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
					printf("查找用户为：\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
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
					printf("查找用户为：\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
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
			case 0:break;
		}
	}while(sel!=0);
	return 0;
}


    };
    break;
   case 2:
    {
        system("cls");
        int i=0;
        FILE * fp2;
	    fp2=fopen("e:\\信息表.txt","r");
	    		while(! feof(fp2))
		{
			fscanf(fp2,"%d%s%s%d%s%d%d%d%d",&yz[i].num,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
			i++;
		}
		fclose(fp2);
		printf("\n");
		printf("\n");
		printf("                       **********************************\n");
		printf("\n");
        printf("                               1.查找业主信息\n");
        printf("\n");
        printf("                               0.退出\n");
        printf("\n");
        printf("                       **********************************\n");
        printf("\n");
        printf("                                请输入您的选择：");
        scanf("%d",&sel2);
        switch(sel2)
    {case 1:
        			    system("cls");
				do
				{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************按业主编号查找*************************\n");
                     printf("\n");
                    printf("                   2***********************按业主姓名查找*************************\n");
                     printf("\n");
			        printf("                   0***********************返回前一级菜单*************************\n");
			         printf("\n");
			        printf("                                          请输入您的选择：");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				printf("请输入查找业主的业主房号：");
				scanf("%d",&search_num);
				n=openfile(yz);
				i=seqsearch1(yz,n,search_num);
				if(i==-1)
					printf("查无此人！\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("查找用户为：\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
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
					printf("查找用户为：\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 0:
			    system("cls");
				break;
			}
				}while(choice!=0);
				break;
            case 0:
                exit(1);}
    };
    break;
   case 0:
       system("cls");
        printf("\n");
         printf("\n");
          printf("\n");
       printf("\n");
       printf("                                                    谢谢您的使用！\n");
       printf("\n");
       printf("\n");
    exit(1);
	}
    }
}
int input(yezhu yz[])             // 许宇翔
{                                              // 输入函数
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
int openfile(yezhu yz[])             // 许宇翔
{                                                // 从文件读取函数
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
void output(yezhu yz[],int n)                      // 许宇翔
{                                                           //输出函数
    system("mode con cols=90 lines=60");
	int i;
	printf("----------------------------------------------------------------------\n");
	printf("                              物业管理信息表                           \n");
	printf("----------------------------------------------------------------------\n");
	printf("编号 姓名    电话    房号 工作单位 用电量 用水量 物业费 水电费\n");
	for(i=0;i<n;i++)
		printf("%2d %6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
	printf("----------------------------------------------------------------------\n");
}
int seqsearch1(yezhu yz[],int n,int search_num)             // 宋雯婷
{                                                                       // 房号查找函数
	int i=n-1;
	while(i>=0&&yz[i].home!=search_num)
		i--;
	return i;
}
int seqsearch2(yezhu yz[],int n,char search_name[])        // 宋雯婷
{                                                                       // 姓名查找函数
	int i=n-1;
	while(i>=0&&(strcmp(yz[i].name,search_name)!=0))
		i--;
	return i;
}
void seqinsert(yezhu yz[],int * len)           // 许宇翔
{                                                          // 插入函数
	int j,k,insert_num,choice;
	char insert_name[20];
	yezhu ins_yezhu;
	if(* len==MAXLEN-1)
		printf("用户已满！");
	else
	{
		do
		{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************按业主编号插入*************************\n");
                     printf("\n");
                    printf("                   2***********************按业主姓名插入*************************\n");
                     printf("\n");
			        printf("                   0***********************返回前一级菜单*************************\n");
			         printf("\n");
			        printf("                                          请输入您的选择：");
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
					printf("请输入插入信息：编号  姓名     电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
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
					printf("请输入插入信息：编号  姓名     电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
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
		}while(choice!=0);
	}
}
void seqdelete(yezhu yz[],int * len)           // 许宇翔
{                                                           // 删除函数
	int j,k,choice;
	char delete_name[20];
	int delete_num;
	if(* len==0)
		printf("用户已空！");
	else
	{
		do
		{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************按业主编号删除*************************\n");
                     printf("\n");
                    printf("                   2***********************按业主姓名删除*************************\n");
                     printf("\n");
			        printf("                   0***********************返回前一级菜单*************************\n");
			         printf("\n");
			        printf("                                          请输入您的选择：");
			scanf("%d",&choice);
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
void revise(yezhu yz[],int n)                // 许宇翔
{                                                         //修改函数
	int knum,k,choice;
	char kname[20];
	do
	{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************按业主编号修改*************************\n");
                     printf("\n");
                    printf("                   2***********************按业主姓名修改*************************\n");
                     printf("\n");
			        printf("                   0***********************返回前一级菜单*************************\n");
			         printf("\n");
			        printf("                                          请输入您的选择：");
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
					printf("请输入修改信息：编号  姓名     电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].num,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,&yz[k].water,&yz[k].hfee,&yz[k].wfee);
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
					printf("请输入修改信息：编号  姓名     电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].num,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,&yz[k].water,&yz[k].hfee,&yz[k].wfee);
					printf("修改成功！\n");
				   }
				   break;
			case 0:
			    system("cls");
				break;
			}
		}while(choice!=0);
	}


void sort(yezhu yz[],int n)           // 宋雯婷
{                                                 // 排序函数
	int i,j,k,choice;
	yezhu t;
	do
	{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************按业主房号排序*************************\n");
                     printf("\n");
                    printf("                   2***********************按业主姓名排序*************************\n");
                     printf("\n");
			        printf("                   0***********************返回前一级菜单*************************\n");
			         printf("\n");
			        printf("                                          请输入您的选择：");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				for(i=0;i<n-1;i++)
				{
					k=i;
					for(j=i+1;j<n;j++)
						if(yz[k].home>yz[j].home)
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
				for(i=0;i<n-1;i++)
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
			case 0:
			    system("cls");
			    break;
			}
		}while(choice!=0);
	}



void save(yezhu yz[],int n)             // 许宇翔
{                                                  // 保存函数
	int i;
	FILE * fp1;
	fp1=fopen("e:\\信息表.txt","w+");
	if(fp1==NULL)
		printf("保存失败\n");
	else
	{
	    fprintf(fp1,"%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[0].num,yz[0].name,yz[0].phone,yz[0].home,yz[0].unite,yz[0].ele,yz[0].water,yz[0].hfee,yz[0].wfee);
		for(i=1;i<n;i++)
			fprintf(fp1,"\n%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
		fclose(fp1);
		printf("保存成功\n");
	}
}



void frist()              // 龚文青
{                                    // 欢迎界面函数
        int i,n=5,m=0;
        while (n)
        {
            if (m==0)
            {
                 printf("\n");
                  printf("\n\n\n");
    printf("                              ^_^ 欢迎进入某小区物业管理系统。。");
     printf("。");
            for(i=0;i<5;i++)
        system("color 0A");
            for(i=0;i<5;i++)
        system("color 0C");
            for(i=0;i<5;i++)
        system("color 0B");
            for(i=0;i<5;i++)
        system("color 0D");
            for(i=0;i<5;i++)
        system("color 0C");
        n--;
                 m=1;
            }
           else if (m==1)
           {
                m=0;
                 printf("\n");
                  printf("\n\n\n");
    printf("                              ^_^ 欢迎进入某小区物业管理系统。。");
                 printf("。");
            for(i=0;i<5;i++)
        system("color 0A");
            for(i=0;i<5;i++)
        system("color 3C");
            for(i=0;i<5;i++)
        system("color 1B");
            for(i=0;i<5;i++)
        system("color 7D");
            for(i=0;i<5;i++)
        system("color 2A");
        n--;
           }

        }
         system("cls");
}
