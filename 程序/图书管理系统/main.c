//图书信息表：（图书编号 、名称、存量、单价、借出本数，能借本数，总价）
//按书号有序输入图书信息
//进书管理：任意输入一个图书信息，在表中查找该书，若存在则将
//其数量加到表中图书数量中；若不存在，则将该图书按照货号有序插入到表中
//图书信息输出
//总价的计算
#define MAXSIZE 80
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char name[9],no[11];       //图书名称、编号
	int count,money,sent,nosent,total;          //图书存量、单价、借出本数，能借本数，总价
}datatype;
 typedef struct
 {
	 datatype data[MAXSIZE+1];
	 int len;
 }SeqList;
void menu()
{
	printf("1.录入图书编号、图书名称，馆内藏此书数，此书单价\n\n");
	printf("2.给定图书编号，还书\n\n");
	printf("3.给定图书编号，查找其它信息\n\n");
	printf("4.给定图书编号，借阅图书\n\n");
	printf("5.给定图书编号，插入该图书信息\n\n");
	printf("6.浏览全部图书信息\n\n");
	printf("7.清图书库存\n\n");
	printf("0.退出\n\n");
}
//录入图书信息
void inp(SeqList *L)
{
	int i;
	printf("输入要录入的图书种类数\n");
	scanf("%d",&L->len);
	printf("输入 图书编号、图书名称、馆内藏此书数、此书单价\n");
	for(i=1;i<=L->len;i++)
	{
		scanf("%s %s %d %d",L->data[i].no,L->data[i].name,&L->data[i].count,&L->data[i].money);
		L->data[i].sent=0;
	}
}
//输出图书信息
void out(SeqList *L)
{
	int i,all=0;
	printf("图书编号、图书名称、馆内藏此书数、借出本数、馆内现有可借出本数、此书单价、馆藏此书总价值\n");
	for(i=1;i<=L->len;i++)
    {
        L->data[i].total=L->data[i].money*L->data[i].count;
        L->data[i].nosent=L->data[i].count-L->data[i].sent;
        all+=L->data[i].total;
        printf("%10s%12s%5d%10d%15d%15d%13d\n",L->data[i].no,L->data[i].name,L->data[i].count,L->data[i].sent,L->data[i].nosent,L->data[i].money,L->data[i].total);
    }
    printf("图书馆馆藏书籍总价值：%d\n\n",all);
}

//查找
int search(SeqList *L,datatype x)
{
	int i=1;
	while(i<=L->len&&strcmp(L->data[i].no,x.no)!=0)
	  i++;
	if(i>L->len)
		return(0);
	else	return(i);
}

//还书
void inp_book(SeqList *L,datatype x)
{
	int i=0,b=0;
	i=search(L,x);
	printf("请输入要还的本数\n");
	scanf("%d",&b);
	L->data[i].sent-=b;
	printf("还书成功！\n\n");
}


//插入图书信息
void ins(SeqList *L,datatype x)
{
	int i=1,j,k=0,f;
	f=search(L,x);
    if (f!=0)
    {
        printf("请输入图书数量\n");
        scanf("%d",&x.count);
        L->data[f].count+=x.count;
        k=-1;
        return;
    }
    printf("请输入图书名称、数量、单价\n");
    scanf("%s %d %d",x.name,&x.count,&x.money);
    x.sent=0;
	while(i<=L->len&&strcmp(L->data[i].no,x.no)<0)
		i++;
	if(L->len==MAXSIZE)
		printf("表已经满了\n");
	else if (k!=-1)
	{
		for(j=L->len;j>=i;j--)
        {
            L->data[j+1]=L->data[j];
        }

   	    L->data[i]=x;
	    L->len++;
	    printf("插入成功！\n\n");
	}
}

//借书
void del(SeqList *L,datatype x)
{
	int i,j,n;
	i=search(L,x);
    if(i==0)
		printf("元素不存在\n");
	else
	{
	    printf("请输入要借的图书数量\n");
	    scanf("%d",&n);
	    L->data[i].sent=n;          //把要借的书的数量赋给了data[i].sent;后面当要借的书的本数小于书的总数时不用处理
	    if (n<=L->data[i].count)
	    {
	        printf("借书成功！\n\n");
        }
        else if (n>L->data[i].count)
        {
            printf("图书数不够\n\n");
        }

	  }
}

void clean(SeqList *L,datatype x)
{
    int i,j;
    i=search(L,x);
    if (i==0)
        printf("该图书不存在\n");
    else
    {
        for (j=i;j<=L->len;j++)
        {
            L->data[j]=L->data[j+1];
        }
        L->len--;
        printf("清该图书库存成功！\n\n");
    }
}

//主函数
int main()
{

	SeqList *stu;
	int sel,k;
	datatype x;
	stu=(SeqList*)malloc(sizeof(SeqList));//初始化
	stu->len=0;
	do
	{
		menu();
		printf("输入你的选择\n");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1:inp(stu);break;
		case 2:printf("输入要还的图书编号\n");
               scanf("%s",x.no);
               inp_book(stu,x);
               break;
		case 3:printf("输入所查找的图书编号\n");
               scanf("%s",x.no);
			   k=search(stu,x);
               if(k==0)
				   printf("元素不存在\n");
			   else
				   printf("图书编号: %s,图书名称: %s,馆内藏此书数:  %d、借出本数:  %d、馆内现有可借出本数;  %d、此书单价;  %d、馆藏此书总价值:  %d\n",stu->data[k].no,stu->data[k].name,stu->data[k].count,stu->data[k].sent,stu->data[k].nosent,stu->data[k].money,stu->data[k].total);
			   break;
		case 4:printf("输入要借阅的图书编号\n");
               scanf("%s",x.no);
			   del(stu,x);
			   break;
		case 5:printf("输入图书编号\n");
			   scanf("%s",x.no);
			   ins(stu,x);
			   break;
		case 6:out(stu);break;
		case 7:printf("请输入要清库存的图书编号：\n");
               scanf("%s",x.no);
               clean(stu,x);
		}
	}while(sel!=0);
	return 0;
}


