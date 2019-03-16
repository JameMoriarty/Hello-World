//商品信息表：（商品编号 、商品名称、商品库存量、商品单价）
//按货号有序输入货物信息
//进货管理：任意输入一个货物信息，在表中查找该货品，若存在则将
//其数量加到表中货物数量中；若不存在，则将该货物按照货号有序插入到表中
//货物信息输出
#define MAXSIZE 80
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char name[9],no[11];       //商品名称、编号
	int count,maney;          //商品入库量、单价
}datatype;
 typedef struct
 {
	 datatype data[MAXSIZE+1];
	 int len;
 }SeqList;
void menu()
{
	printf("1.录入商品编号、商品名称\n\n");
	printf("2.录入商品入库量、商品单价\n\n");
	printf("3.给定商品编号，查找其它信息\n\n");
	printf("4.给定商品编号，删除该商品信息\n\n");
	printf("5.给定商品编号，插入该商品信息\n\n");
	printf("6.浏览全部商品信息\n\n");
	printf("0.退出\n\n");
}
//录入商品编号，商品名称
void inp(SeqList *L)
{
	int i;
	printf("输入要录入的商品种类数\n");
	scanf("%d",&L->len);
	printf("输入 商品编号、商品名称\n");
	for(i=1;i<=L->len;i++)
	{
		scanf("%s %s",L->data[i].no,L->data[i].name);
	}
}
//输出商品信息
void out(SeqList *L)
{
	int i;
	printf("商品编号、商品名称、商品入库量、商品单价\n");
	for(i=1;i<=L->len;i++)
		printf("%10s%12s%5d%5d\n",L->data[i].no,L->data[i].name,L->data[i].count,L->data[i].maney);
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

//录商品入库量、商品单价
void inp_score(SeqList *L)
{
	int i;
	printf("录入商品入库量、商品单价\n");
        for(i=1;i<=L->len;i++)
		  scanf("%d %d",&(L->data[i].count),&(L->data[i].maney));



}

//插入商品信息
void ins(SeqList *L,datatype x)
{
	int i=1,j,k=0;
	for (i=1;i<=L->len;i++)
    {
        if (strcmp(L->data[i].no,x.no)==0)
        {
            L->data[i].count+=x.count;
            k=-1;
            break;
        }

    }

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
	}
}

//删除
void del(SeqList *L,datatype x)
{
	int i,j;
	i=search(L,x);
    if(i==0)
		printf("元素不存在\n");
	else
	{
	    printf("请输入要删除的商品数量\n");
	    int n;
	    scanf("%d",&n);
	    if (n==L->data[i].count)
	    {
            for(j=i+1;j<=L->len;j++)
               L->data[j-1]=L->data[j];
            L->len--;
	    }
	    else if (n<L->data[i].count)
        {
            L->data[i].count-=n;
        }
        else if (n>L->data[i].count)
        {
            printf("商品数不够\n\n");
        }

	  }
}

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
		case 2:inp_score(stu);break;
		case 3:printf("输入所查找的商品编号\n");
               scanf("%s",x.no);
			   k=search(stu,x);
               if(k==0)
				   printf("元素不存在\n");
			   else
				   printf("商品编号: %s,商品名称: %s,数量: %d,单价: %d\n",stu->data[k].no,stu->data[k].name,stu->data[k].count,stu->data[k].maney);
			   break;
		case 4:printf("输入所删除的商品编号\n");
               scanf("%s",x.no);
			   del(stu,x);
			   break;
		case 5:printf("输入商品编号，名称，数量，单价\n");
			   scanf("%s%s%d%d",x.no,x.name,&x.count,&x.maney);
			   ins(stu,x);
			   break;
		case 6:out(stu);break;
		}
	}while(sel!=0);
	return 0;
}


