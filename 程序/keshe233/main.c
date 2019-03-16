#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void caidan( );
int caidan1( );
void caidan2 ();
int secret(int p,int q);
struct yezhu_type
{
	int number;        //业主编号
	char name[20];     //业主姓名
	char phone[50];   //业主电话
	int home;       //业主房号
	char unite[100];     //业主工作单位
	int ele;        //用电量
	int water;     //用水量
	int hfee;     //物业费
	int wfee;      //水电费

};
int  funprint(struct yezhu_type yz[5000],int *p);
int seqsearch2(struct yezhu_type yz[],int n,int knum);
int seqsearch1(struct yezhu_type yz[],int n,char kname[20]);
int search(struct yezhu_type yz[],int n);
void sort(struct yezhu_type yz[],int n);
void output(struct yezhu_type yz[],int n);
void output1(struct yezhu_type yz[],int n);
void revise(struct yezhu_type yz[],int n);
int seqdelete(struct yezhu_type yz[],int n);
int main()
{
    system("mode con cols=48 lines=30");
// system("color 3C");
    int i=0,n=0,k=0,j,p=0,q=888888,g=0,w=0,c=0;
	struct yezhu_type yz[5000];

    while (k!=-1)
{
      caidan2();
      scanf("%d",&k);
      if (k==1)
      {
          p=secret(p,q);

          if (p==q)
          {
                while (i!=-1)
                {
                   caidan( );
                   scanf("%d",&i);
                        if (i==1)
                        {
                             funprint(yz,&n);
                        }

                         else if (i==6)
                         {
                            w=search(yz,n);
   //                         printf("                           请输入-1完成搜索 \n");
   //                         scanf("%d",&w);

                         }

                         else if (i==4)
                         {
                             sort(yz,n);
                         }

                         else if (i==5)
                         {
                             output(yz,n);
                         }

                         else if (i==2)
                          {
                             revise(yz,n);
                          }

                        else if (i==3)
                         {
                             c=seqdelete(yz,n);
                             if (c==0)
                                continue;
                         }
                          else if (i==7)
                          {
  //
                             output1(yz,n);
                          }
                      }
             }
             else
            {
                 printf("密码输入错误\n");
            }
    }
    else if (k==2)
    {

        while (i!=-1)
        {
           g= caidan1( );

            if (g==0)
           {
               break;
           }
          w=search(yz,n);
          if (w==6)
            break;
        }
  //      break;

      }
    }
//	printf("\n-----运行完毕----\n");
	return 0;
}

////////////////////菜单///
void caidan( )
{
    system("cls");
    system("mode con cols=48 lines=30");
    system("color 1C");
    printf("\n\n");

    printf("***************某小区物业管理系统***************\n");
    printf("\n");
    printf("*********请选择输入对应序号选择所需功能*********\n\n");
    printf ("            1  录入业主信息\n\n");
    printf ("            2  修改业主信息\n\n");
    printf ("            3  删除业主信息\n\n");
    printf ("            4  业主信息排序\n\n");
    printf ("            5  浏览业主信息\n\n");
    printf ("            6  查询业主信息\n\n");
    printf ("            7  查看业主缴费清单\n\n");
    printf ("            -1 退出系统\n\n");
    printf("************************************************\n\n");




}
/////////////////////////
int  funprint(struct yezhu_type yz[5000],int *p)
{
    system("cls");
    system("mode con cols=80 lines=40");
    system("color 4A");
    int i,n,m;
    FILE *fp;
    printf("请输入要录入的业主人数:\n");
      scanf("%d",&n);
      *p=n;



	puts ("请输入业主信息：\n编号  姓名  电话     房号  工作单位  用电量  用水量  物业费  水电费\n");
	for (i=0;i<n;i++)
    {
        scanf("%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);

    }
     if ((fp=fopen("E:\\业主信息.txt","a"))==NULL)
      {
          printf("Cannot open file strike any key exit!");
          getchar ();
          return 1;
      }
//      fputc('\n',fp);
      //  表头//////
//	fprintf(fp,"%8s %8s %10s %4s %8s %4s %4s %4s %4s","业主编号","业主姓名","业主电话","业主房号","业主工作单位","用电量","用水量","物业费","水电费");
//	fputc('\n',fp);

    for(i=0;i<n;i++)
    {
        fputc('\n',fp);
        fprintf(fp,"%03d %11s %14s %5d %10s %8d %5d %5d %5d",yz[i].number,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);

    }
    fclose(fp);
    return n;

}

int search(struct yezhu_type yz[],int n)
{
    system("cls");
    system("color 3B");
    int i,knum,k=0;
	char kname[20];
    printf("*********************请选择查询方式*********************\n");
    printf("　　　　　　　 1　业主名称\n");
    printf("               2  业主房号\n");
    scanf("%d",&i);
    if (i==1)
    {
		printf("请输入要查找的业主姓名：\n");
		scanf("%s",&kname[20]);
		printf("业主编号 业主名称 业主电话  业主房号 业主单位  用电量 用水量 物业费 水电费\n");

        seqsearch1(yz,n,kname);
		printf("是否还要继续查询\n\n");
      printf("*******1   是 *******\n\n");
       printf("*******2   否 *******\n\n");
       scanf("%d",&k);
        if (k==1)
        {
            seqsearch1(yz,n,kname);
        }
		else
			return 0;
    }

    else if (i==2)
    {
		printf("请输入要查找的业主房号：\n");
		scanf("%d",&knum);
		printf("业主编号 业主名称 业主电话  业主房号 业主单位  用电量 用水量 物业费 水电费\n");

        seqsearch2(yz,n,knum);
        printf("是否还要继续查询\n\n");
      printf("*******1   是 *******\n\n");
       printf("*******2   否 *******\n\n");
       scanf("%d",&k);
        if (k==1)
        {
            seqsearch1(yz,n,kname);
        }
		else
			return 0;
    }


    else
    {
        printf("error\n");
        return 0;
    }
    return 0;

}


int seqsearch1(struct yezhu_type yz[],int n,char kname[])/*按业主名称查找*/
{
 //   system("cls");
 //   system("color 1A");
  //  system("mode con cols=100 lines=30");

 //  char a[20];
   int i=0,z=0,j=0;
   FILE *fp;
   fp=fopen("E:\\业主信息.txt","r");
   while(!feof(fp))
       // for (i=0;i<n+9;i++)
   {
       fscanf(fp,"%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
   i++;
   }
    fclose(fp);

  // printf("请输入要查找的业主姓名：\n");
  // scanf("%s",a);
  for (j=0;j<i;j++)
   {
       if (strcmp(kname,yz[j].name)==0)
       {
  //         printf("业主编号 业主名称 业主电话  业主房号 业主单位  用电量 用水量 物业费 水电费\n");
           printf("%03d %11s %14s %5d %10s %8d %5d %5d %5d",yz[j].number,yz[j].name,yz[j].phone,yz[j].home,yz[j].unite,yz[j].ele,yz[j].water,yz[j].hfee,yz[j].wfee);

       }
       else
       {
           printf("error\n");
  //         return -1;
           break;
       }
  }
  //    printf("是否还要继续查询\n\n");
  //    printf("*******1   是 *******\n\n");
  //     printf("*******2   否 *******\n\n");
 //      scanf("%d",&z);
  //     if (z==1)
 //      {
 //           search(yz,n);
  //     }
 //      else if (z==2)
 //      {
 //          return -1;
 //      }


 //  }
 //  fclose(fp);
	   return 0;
}

int seqsearch2(struct yezhu_type yz[],int n,int knum)/*按业主房号查找*/
{
    system("cls");
   int m,i=0,z=0,j=0;
   FILE *fp;
   fp=fopen("E:\\业主信息.txt","r");
 //  for (i=0;i<(n+9);i++)
 //  {
 //      fread(&yz[i],sizeof(struct yezhu_type),1,fp);
 //  }
   while(!feof(fp))
       // for (i=0;i<n+9;i++)
   {
       fscanf(fp,"%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
   i++;
   }
    fclose(fp);
 //  printf("请输入要查找的业主房号：\n");

 //  scanf("%d",&m);
 //  printf("业主编号 业主名称 业主电话  业主房号 业主单位  用电量 用水量 物业费 水电费\n");
 //  while (m==yz[i].home)
 //  {
 for (j=0;j<i;j++)
   {
       if (knum==yz[j].home)
       {
  //         printf("业主编号 业主名称 业主电话  业主房号 业主单位  用电量 用水量 物业费 水电费\n");
           printf("%03d %11s %14s %5d %10s %8d %5d %5d %5d",yz[j].number,yz[j].name,yz[j].phone,yz[j].home,yz[j].unite,yz[j].ele,yz[j].water,yz[j].hfee,yz[j].wfee);

       }
       else
       {
           printf("error\n");
  //         return -1;
           break;
       }
  }
  //  printf("是否还要继续查询\n\n");
  //     printf("*******1   是 *******\n\n");
  //     printf("*******2   否 *******\n\n");
  //     scanf("%d",&z);
  //  if (z==1)
  //     {
  //          search(yz,n);
 //      }
 //      else if (z==2)
 //      {
 //          return -1;
 //      }
   return 0;

}
//···············查找··················


void sort(struct yezhu_type yz[],int n)
{
    system("cls");
    system("color 1C");
	int i,j,k,choice;
	struct yezhu_type t;
	FILE *fp;
	fp=fopen("E:\\业主信息.txt","r");
	do
	{
		printf("1**********按业主编号排序*****\n");
		printf("2**********按业主房号排序*****\n");
		printf("0**********返回上级菜单*****\n");
		printf("请输入选择\n");
		scanf("%d",&choice);
		for (i=0;i<n+9;i++)
   {
       fscanf(fp,"%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
   }
		switch(choice)
		{
			case 1:
				for(i=0;i<n-1;i++)
				{
					k=i;
					for(j=i+1;j<n;j++)
						if(yz[k].number>yz[j].number)
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
			case 0:
				break;
		}
	}while(choice!=0);
}

void output(struct yezhu_type yz[],int n)
{
    system("cls");
	system("mode con cols=100 lines=30");

    int i=0,k=0,j=0;
    FILE *fp;
	fp=fopen("E:\\业主信息.txt","r");

      while (!feof(fp))
       // for (i=0;i<n+9;i++)
     {
       fscanf(fp,"%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
         i++;
     }
    fclose(fp);

    printf("业主编号 业主名称 业主电话  业主房号 业主单位  用电量 用水量 物业费 水电费\n");
    for (j=0;j<i;j++)
    {
        printf("%03d %11s %14s %5d %10s %8d %5d %5d %5d\n",yz[j].number,yz[j].name,yz[j].phone,yz[j].home,yz[j].unite,yz[j].ele,yz[j].water,yz[j].hfee,yz[j].wfee);

    }

        printf("请输入-1结束浏览\n");
        scanf("%d",&k);

}


void revise(struct yezhu_type yz[],int n)
{
    system("cls");
    system("color 4A");
	int knum,k,choice;
	char kname[20];
	do
	{
			printf("1***********************按业主房号修改*************************\n");
			printf("2***********************按业主姓名修改*************************\n");
			printf("0***********************返回前一级菜单*************************\n");
			printf("请输入您的选择：\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:printf("请输入修改业主的业主房号：");
				   scanf("%d",&knum);
				   k=seqsearch2(yz,n,knum);
				   if(k==-1)
					   printf("查无此人！\n");
				   else
				   {
					printf("请输入修改信息：业主编号  业主姓名  业主电话  业主房号  业主工作单位  用电量  用水量  物业费  水电费\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].number,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,&yz[k].water,&yz[k].hfee,&yz[k].wfee);
					   printf("修改成功！\n");
				   }
				   break;
			case 2:printf("请输入修改业主的业主姓名：");
				   scanf("%s",kname);
				   k=seqsearch1(yz,n,kname);
				   if(k==-1)
					   printf("查无此人！\n");
				   else
				   {
					printf("请输入修改信息：业主编号  业主姓名  业主电话  业主房号  业主工作单位  用电量  用水量  物业费  水电费\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].number,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,&yz[k].water,&yz[k].hfee,&yz[k].wfee);
					printf("修改成功！\n");
				   }
				   break;
			case 0:
				break;
			}
		}while(choice!=0);
	}

int caidan1( )
{
    int d;
    system("cls");
    printf("***************某小区物业管理系统***************\n");
    printf("\n");
    printf("************************************************\n\n");
    printf ("            \n");
    printf ("            \n");
    printf ("            \n");
    printf ("            \n");
    printf ("            \n");
    printf ("          \n\n");
    printf ("              查看业主缴费清单\n\n");
    printf ("           \n\n");
    printf ("            \n");
    printf ("            \n");
    printf ("            \n");
    printf ("             输入1进入下一步\n\n" );
    printf ("             输入0返回\n\n");
    printf ("************************************************\n\n");
    scanf("%d",&d);
    return d;


}
int secret(int p,int q)
{
    system("cls");
    system("color 2B");
    printf("\n\n\n\n");
    printf("************************************************\n\n\n\n\n\n");
        printf("\t\t请管理员输入6位登录密码：\n\n\n");

            scanf("%d",&p);
            return p;
}

void caidan2()
{
     printf("\n\n");

    printf("***************某小区物业管理系统***************\n");
    printf("\n");
    printf("*********请选择输入对应序号选择您的身份*********\n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            1  物业管理员\n\n");
    printf ("            2  小区业主\n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            -1 退出系统\n\n");
    printf("************************************************\n\n");


}


int seqdelete(struct yezhu_type yz[],int n)
{
    int j,k,choice,x,i;
  //   FILE *fp;
//	fp=fopen("C:\\Users\\gwq12\\Desktop\\课设\\业主信息.txt","r");
//	for (i=0;i<n+9;i++)
  // {
  //     fscanf(fp,"%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
  // }
    system("cls");
//	int j,k,choice,x,i;
	char delete_name[20];
	int delete_num;
	if(n==0)
    {
        printf("****************************************\n\n\n");
        printf("               用户已空！\n\n");
        printf("               输入0返回\n\n");
		scanf("%d",&x);
		return x;
    }

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
				   k=seqsearch2(yz,n,delete_num);
				   if(k==-1)
					   printf("无效的删除位置！\n");
				   else
				   {
					   for(j=k+1;j<n;j++)
						   yz[j-1]=yz[j];
					   (n)--;
					   printf("删除成功！\n");
				   }
				   break;
			case 2:printf("请输入删除业主的业主姓名：");
				   scanf("%s",delete_name);
				   k=seqsearch1(yz,n,delete_name);
				   if(k==-1)
					   printf("无效的删除位置！\n");
				   else
				   {
					   for(j=k+1;j<n;j++)
						   yz[j-1]=yz[j];
					   n--;
					   printf("删除成功！\n");
				   }
				   break;
			case 0:break;
			}

		}while(choice!=0);
		return 0;
	}
//	scanf("%d",&x);
}


void output1(struct yezhu_type yz[],int n)
{
    system("cls");
    system("mode con cols=80 lines=30");
    system("color 2B");
    int i=0,k=0,j;
    FILE *fp;
	fp=fopen("E:\\业主信息.txt","r");

	while (!feof(fp))
       // for (i=0;i<n+9;i++)
     {
       fscanf(fp,"%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
         i++;
     }
    fclose(fp);
    printf("\n\n\n");
     printf("*****************************************************************************\n\n\n");
     printf("                             业主缴费清单\n\n\n");
     printf("******************************************************************************\n\n");

    printf("业主编号 业主名称 业主电话  业主房号 业主单位  用电量 用水量 物业费 水电费\n");
    for (j=0;j<i;j++)
    {
        printf("%03d %11s %14s %5d %10s %8d %5d %5d %5d\n",yz[j].number,yz[j].name,yz[j].phone,yz[j].home,yz[j].unite,yz[j].ele,yz[j].water,yz[j].hfee,yz[j].wfee);

    }
        printf("请输入-1结束浏览\n");
        scanf("%d",&k);
}
