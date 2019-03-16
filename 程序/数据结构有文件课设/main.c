/*商店存货管理系统
功能：建立一商店存货管理系统，要求每次出货时取进货时间最早且最接近保质期中止时间的货物。

分步实施：
1．	初步完成总体设计，搭好框架，确定人机对话的界面，确定函数个数；
2．	完成最低要求：建立一个文件，包括5个种类的货物情况，能对商品信息进行扩充（追加），修改和删除以及简单的排序；
3．	进一步要求：扩充商品数量，以及完成系统查询功能。有兴趣的同学可以自己扩充系统功能。

要求：1）界面友好，函数功能要划分好
2）总体设计应画一流程图
3）程序要加必要的注释
4）要提供程序测试方案
5）程序一定要经得起测试，宁可功能少一些，也要能运行起来，不能运行的程序是没有价值的。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct
{
	char name[11];
	int num,no;
	float price;
	int intime;   //进货时间
	int deadtime;  //可使用的最后日期
}datatype;
typedef struct node
{
   datatype data;
   struct node *next;
}nodetype;
//输入
void input(nodetype *head)
{
	int n,i;
	datatype x;
    nodetype *s,*tail=head;
	printf("输入货物个数\n");
	scanf("%d",&n);
	printf("输入货物的名称、编号(按编号从小到大输入)、数量、单价、进货时间（例如：20180104）、可使用的最后日期（例如：20190104）\n");
	for(i=1;i<=n;i++)
	{
		scanf("%s%d%d%f%d%d",x.name,&x.no,&x.num,&x.price,&x.intime,&x.deadtime);
		s=(nodetype*)malloc(sizeof(nodetype));
		s->data=x;
		tail->next=s;
		tail=s;
	}
	tail->next=NULL;
}

//输出
void output(nodetype *head)
{
	nodetype *s;
	s=head->next;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);   //字体设置成黄色
	printf(" 编号     名称     数量  单价    进货时间   可使用的最后日期\n");
	while(s!=NULL)
	{
		printf("%5d%9s%8d %7.2f%12d%12d\n",s->data.no,s->data.name,s->data.num,s->data.price,s->data.intime,s->data.deadtime);
		s=s->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);   //字体设置成白色
}

//读文件信息放进单链表
void readfile(nodetype *head)
{
   nodetype *s,*tail=head;
   datatype s1;
   FILE * fp2;
	fp2=fopen("E:\\信息表.txt","r"); /*打开已有信息表*/
	if(fp2==NULL)
	{
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //字体设置成红色
		printf("未找到该文件！请在d盘根目录下建立一个名为“信息表”的文件\n");
	}
	else
	{
		while(! feof(fp2))
		{
			fscanf(fp2,"%5d%9s%6d %6f%12d%12d\n",&s1.no,s1.name,&s1.num,&s1.price,&s1.intime,&s1.deadtime);
		    s=(nodetype*)malloc(sizeof(nodetype));
			s->data=s1;
			tail->next=s;
			tail=s;
		}
		tail->next=NULL;
		fclose(fp2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //字体设置成红色
		printf("载入成功!\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);   //字体设置成白色
	}
}
//菜单
void menu()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	printf("****** 1------键盘录入货物信息\n");
	printf("****** 2------浏览 \n");
	printf("****** 3------查找\n");
	printf("****** 4------入库\n");
	printf("****** 5------出库\n");
	printf("****** 6------统计库存货物总量\n");
//	printf("7------保存信息进文件\n");
	printf("****** 0------退出\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//在其他函数里使用的查找
nodetype* search(nodetype*head,datatype x)
{
	nodetype*p=head->next;
	while(p!=NULL&&p->data.no!=x.no)
	{
		p=p->next;
	}
	return p;
}
//查找到编号相同进货日期不同的商品
void searchti(nodetype *head,datatype x)
{
	nodetype*p=head->next;
	int m=0;
	while(p!=NULL)
    {
        if(p->data.no==x.no)
        {
            m++;
            printf("名称：%s，数量：%d，单价：%.2f，进货时间：%d，可使用的最后时间：%d\n",p->data.name,p->data.num,p->data.price,p->data.intime,p->data.deadtime);
        }
        p=p->next;
    }
	if(p==NULL&&m==0)
        printf("没找到！\n");
}
//用编号和进货日期的查找
nodetype* search1(nodetype*head,datatype x)
{
	nodetype*p=head->next;
	while(p!=NULL&&(p->data.no!=x.no||p->data.intime!=x.intime))
	{
		 p=p->next;
	}
	return p;
}

//插入
void ins(nodetype*head,datatype x)
{
	   nodetype*p=head,*s,*y;
	   y=search1(p,x);
	  if (y!=NULL)
	  {
		   printf("输入该商品要入库的数量：\n");
		   scanf("%d",&x.num);
		   y->data.num+=x.num;
	  }
	  else
	  {
			printf("输入该商品的名称、数量、单价、可使用的最后日期\n");
			scanf("%s%d%f%d",x.name,&x.num,&x.price,&x.deadtime);
			while (p->next!=NULL&&p->next->data.no<x.no)
			{
				p=p->next;
			}
			s=(nodetype*)malloc(sizeof(nodetype));
			s->data=x;
			s->next=p->next;
			p->next=s;
	  }

}
//删除
void del(nodetype*head,datatype x)
{
	nodetype*p,*q,*s,*y=NULL;
	int m=0,num1,tonum=0;//tonum 编号相同的货物的总量
	p=search(head,x);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //字体设置成红色
	if(p==NULL) {printf("没找到！\n");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}   //字体设置成白色
	else
	{
	    s=p;
	    while(s!=NULL)
        {
            if(s->data.no==x.no)
            {
                m++;
                tonum+=s->data.num;
                y=s;
            //    printf("名称：%s，数量：%d，单价：%.2f，进货时间：%d，可使用的最后时间：%d\n",p->data.name,p->data.num,p->data.price,p->data.intime,p->data.deadtime);
            }
            s=s->next;
        }

		printf("请输入要出库的数量：\n");
		scanf("%d",&num1);

		if (num1==tonum)
		{
			q=head;
			while(q->next!=NULL&& q->next!=p)
				q=q->next;
			 q->next=y->next;
			 printf("出库成功！\n");
			 while(p!=y->next)
             {
                free(p);
                p=p->next;
             }
		}
		else if (num1<tonum)
		{
		    while(p!=y->next)
            {
                if(num1<p->data.num)
                {
                    p->data.num-=num1;
                    break;
                }
                else if(num1>=p->data.num)
                {
                    q=head;
                    while(q->next!=NULL&& q->next!=p)
                            q=q->next;
                    q->next=p->next;
                    free(p);
                    num1-=p->data.num;
                }
                p=p->next;
            }
			printf("出库成功！\n");
		}
		else if(num1>tonum)
		{
			printf("库存不够！\n");
		}

	}
}
//交换节点位置的冒泡排序（按编号排序）
void bubbledortno(nodetype *head)
{
	nodetype *p,*prep,*temp,*tail;
	tail=NULL;
	while(head->next!=tail)
	{
		prep=head;
		p=head->next;
		while(p->next!=tail)
		{
			if(p->data.no>p->next->data.no)
			{
				temp=p->next;
				prep->next=p->next;
				p->next=p->next->next;
				prep->next->next=p;
				p=temp;
			}
			p=p->next;
			prep=prep->next;
		}
		tail=p;
	}
}

//交换节点位置的冒泡排序（按进货日期排序）
void bubbledortintime(nodetype *head)
{
	nodetype *p,*prep,*temp,*tail;
	tail=NULL;
	while(head->next!=tail)
	{
		prep=head;
		p=head->next;
		while(p->next!=tail)
		{
			if(p->data.intime>p->next->data.intime)
			{
				temp=p->next;
				prep->next=p->next;
				p->next=p->next->next;
				prep->next->next=p;
				p=temp;
			}
			p=p->next;
			prep=prep->next;
		}
		tail=p;
	}
}

//统计货物库存总量
void printtotalnum(nodetype *head)
{
	nodetype *p;
	p=head->next;
	int thnum=0;
	while(p!=NULL)
	{
		thnum+=p->data.num;
		p=p->next;
	}
	printf("仓库货物库存总量为：%d\n",thnum);
}

//保存进文件
void openfile(nodetype *head)
{
	FILE * fp2;
	fp2=fopen("E:\\信息表.txt","a+"); /*打开已有信息表*/
	if(fp2==NULL)
	{
		printf("未找到该文件！请在E盘根目录下建立一个名为“信息表”的文件\n");
	}
	else
	{
		nodetype *s=head->next;
//	    fprintf(fp2," 编号     名称     数量  单价  进货时间   可使用的最后日期\n");
	    while(s!=NULL)
		{
		   fprintf(fp2,"%5d%9s%6d %6.2f%12d%12d\n",s->data.no,s->data.name,s->data.num,s->data.price,s->data.intime,s->data.deadtime);
		   s=s->next;
		}
		fclose(fp2);
		printf("载入成功\n");
	}
}
//打开文件
void openfile1(nodetype *head)
{
	FILE * fp2;
	fp2=fopen("E:\\信息表.txt","w"); /*打开已有信息表*/
	if(fp2==NULL)
	{
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //字体设置成红色
		printf("未找到该文件！请在E盘根目录下建立一个名为“信息表”的文件\n");
	}
	else
	{
		nodetype *s=head->next;
//	    fprintf(fp2," 编号     名称     数量  单价  进货时间   可使用的最后日期\n");
	    while(s!=NULL)
		{
		   fprintf(fp2,"%5d%9s%6d %6.2f%12d%12d\n",s->data.no,s->data.name,s->data.num,s->data.price,s->data.intime,s->data.deadtime);
		   s=s->next;
		}
		fclose(fp2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //字体设置成红色
		printf("载入成功\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

int main()
{
	nodetype *L,*p,*q;
	datatype x;
	int sel,password,pa;
	L=(nodetype*)malloc(sizeof(nodetype));
	L->next=NULL;
	password=1234;
	printf("请输入登录密码\n");
	scanf("%d",&pa);
	if (pa==password)
	do
	{
		menu();
		printf("输入你的选择\n");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1:input(L);
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //字体设置成红色
			   printf("录入成功！\n");
			   openfile(L);
			   break;
		case 2:readfile(L);
			   bubbledortintime(L);
			   bubbledortno(L);
			   output(L);
			   break;
		case 3:readfile(L);
			   printf("输入所查找的编号\n");
	           scanf("%d",&x.no);
			   searchti(L,x);
			   break;
        case 4:printf("输入元素编号和进货日期\n");
			   scanf("%d%d",&x.no,&x.intime);
			   ins(L,x);
			   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //字体设置成红色
			   printf("插入成功！\n");
			   openfile1(L);
			   break;
		case 5:bubbledortintime(L);
			   bubbledortno(L);
			   printf("输入要出库的编号\n");
	           scanf("%d",&x.no);
			   del(L,x);
			   openfile1(L);
			   break;
		case 6:readfile(L);
			   printtotalnum(L);
			   break;
//		case 7:openfile(L);
//			   break;

		}
	}while(sel!=0);
	else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //字体设置成红色
		printf("密码错误！无法进入程序！\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);   //字体设置成白色
    }
    return 0;
}

