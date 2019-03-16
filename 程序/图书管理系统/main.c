//ͼ����Ϣ����ͼ���� �����ơ����������ۡ�����������ܽ豾�����ܼۣ�
//�������������ͼ����Ϣ
//���������������һ��ͼ����Ϣ���ڱ��в��Ҹ��飬��������
//�������ӵ�����ͼ�������У��������ڣ��򽫸�ͼ�鰴�ջ���������뵽����
//ͼ����Ϣ���
//�ܼ۵ļ���
#define MAXSIZE 80
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char name[9],no[11];       //ͼ�����ơ����
	int count,money,sent,nosent,total;          //ͼ����������ۡ�����������ܽ豾�����ܼ�
}datatype;
 typedef struct
 {
	 datatype data[MAXSIZE+1];
	 int len;
 }SeqList;
void menu()
{
	printf("1.¼��ͼ���š�ͼ�����ƣ����ڲش����������鵥��\n\n");
	printf("2.����ͼ���ţ�����\n\n");
	printf("3.����ͼ���ţ�����������Ϣ\n\n");
	printf("4.����ͼ���ţ�����ͼ��\n\n");
	printf("5.����ͼ���ţ������ͼ����Ϣ\n\n");
	printf("6.���ȫ��ͼ����Ϣ\n\n");
	printf("7.��ͼ����\n\n");
	printf("0.�˳�\n\n");
}
//¼��ͼ����Ϣ
void inp(SeqList *L)
{
	int i;
	printf("����Ҫ¼���ͼ��������\n");
	scanf("%d",&L->len);
	printf("���� ͼ���š�ͼ�����ơ����ڲش����������鵥��\n");
	for(i=1;i<=L->len;i++)
	{
		scanf("%s %s %d %d",L->data[i].no,L->data[i].name,&L->data[i].count,&L->data[i].money);
		L->data[i].sent=0;
	}
}
//���ͼ����Ϣ
void out(SeqList *L)
{
	int i,all=0;
	printf("ͼ���š�ͼ�����ơ����ڲش�����������������������пɽ�����������鵥�ۡ��ݲش����ܼ�ֵ\n");
	for(i=1;i<=L->len;i++)
    {
        L->data[i].total=L->data[i].money*L->data[i].count;
        L->data[i].nosent=L->data[i].count-L->data[i].sent;
        all+=L->data[i].total;
        printf("%10s%12s%5d%10d%15d%15d%13d\n",L->data[i].no,L->data[i].name,L->data[i].count,L->data[i].sent,L->data[i].nosent,L->data[i].money,L->data[i].total);
    }
    printf("ͼ��ݹݲ��鼮�ܼ�ֵ��%d\n\n",all);
}

//����
int search(SeqList *L,datatype x)
{
	int i=1;
	while(i<=L->len&&strcmp(L->data[i].no,x.no)!=0)
	  i++;
	if(i>L->len)
		return(0);
	else	return(i);
}

//����
void inp_book(SeqList *L,datatype x)
{
	int i=0,b=0;
	i=search(L,x);
	printf("������Ҫ���ı���\n");
	scanf("%d",&b);
	L->data[i].sent-=b;
	printf("����ɹ���\n\n");
}


//����ͼ����Ϣ
void ins(SeqList *L,datatype x)
{
	int i=1,j,k=0,f;
	f=search(L,x);
    if (f!=0)
    {
        printf("������ͼ������\n");
        scanf("%d",&x.count);
        L->data[f].count+=x.count;
        k=-1;
        return;
    }
    printf("������ͼ�����ơ�����������\n");
    scanf("%s %d %d",x.name,&x.count,&x.money);
    x.sent=0;
	while(i<=L->len&&strcmp(L->data[i].no,x.no)<0)
		i++;
	if(L->len==MAXSIZE)
		printf("���Ѿ�����\n");
	else if (k!=-1)
	{
		for(j=L->len;j>=i;j--)
        {
            L->data[j+1]=L->data[j];
        }

   	    L->data[i]=x;
	    L->len++;
	    printf("����ɹ���\n\n");
	}
}

//����
void del(SeqList *L,datatype x)
{
	int i,j,n;
	i=search(L,x);
    if(i==0)
		printf("Ԫ�ز�����\n");
	else
	{
	    printf("������Ҫ���ͼ������\n");
	    scanf("%d",&n);
	    L->data[i].sent=n;          //��Ҫ����������������data[i].sent;���浱Ҫ�����ı���С���������ʱ���ô���
	    if (n<=L->data[i].count)
	    {
	        printf("����ɹ���\n\n");
        }
        else if (n>L->data[i].count)
        {
            printf("ͼ��������\n\n");
        }

	  }
}

void clean(SeqList *L,datatype x)
{
    int i,j;
    i=search(L,x);
    if (i==0)
        printf("��ͼ�鲻����\n");
    else
    {
        for (j=i;j<=L->len;j++)
        {
            L->data[j]=L->data[j+1];
        }
        L->len--;
        printf("���ͼ����ɹ���\n\n");
    }
}

//������
int main()
{

	SeqList *stu;
	int sel,k;
	datatype x;
	stu=(SeqList*)malloc(sizeof(SeqList));//��ʼ��
	stu->len=0;
	do
	{
		menu();
		printf("�������ѡ��\n");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1:inp(stu);break;
		case 2:printf("����Ҫ����ͼ����\n");
               scanf("%s",x.no);
               inp_book(stu,x);
               break;
		case 3:printf("���������ҵ�ͼ����\n");
               scanf("%s",x.no);
			   k=search(stu,x);
               if(k==0)
				   printf("Ԫ�ز�����\n");
			   else
				   printf("ͼ����: %s,ͼ������: %s,���ڲش�����:  %d���������:  %d���������пɽ������;  %d�����鵥��;  %d���ݲش����ܼ�ֵ:  %d\n",stu->data[k].no,stu->data[k].name,stu->data[k].count,stu->data[k].sent,stu->data[k].nosent,stu->data[k].money,stu->data[k].total);
			   break;
		case 4:printf("����Ҫ���ĵ�ͼ����\n");
               scanf("%s",x.no);
			   del(stu,x);
			   break;
		case 5:printf("����ͼ����\n");
			   scanf("%s",x.no);
			   ins(stu,x);
			   break;
		case 6:out(stu);break;
		case 7:printf("������Ҫ�����ͼ���ţ�\n");
               scanf("%s",x.no);
               clean(stu,x);
		}
	}while(sel!=0);
	return 0;
}


