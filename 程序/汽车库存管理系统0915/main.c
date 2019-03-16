//��Ʒ��Ϣ������Ʒ��� ����Ʒ���ơ���Ʒ���������Ʒ���ۣ�
//�������������������Ϣ
//����������������һ��������Ϣ���ڱ��в��Ҹû�Ʒ����������
//�������ӵ����л��������У��������ڣ��򽫸û��ﰴ�ջ���������뵽����
//������Ϣ���
#define MAXSIZE 80
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char name[9],no[11];       //��Ʒ���ơ����
	int count,maney;          //��Ʒ�����������
}datatype;
 typedef struct
 {
	 datatype data[MAXSIZE+1];
	 int len;
 }SeqList;
void menu()
{
	printf("1.¼����Ʒ��š���Ʒ����\n\n");
	printf("2.¼����Ʒ���������Ʒ����\n\n");
	printf("3.������Ʒ��ţ�����������Ϣ\n\n");
	printf("4.������Ʒ��ţ�ɾ������Ʒ��Ϣ\n\n");
	printf("5.������Ʒ��ţ��������Ʒ��Ϣ\n\n");
	printf("6.���ȫ����Ʒ��Ϣ\n\n");
	printf("0.�˳�\n\n");
}
//¼����Ʒ��ţ���Ʒ����
void inp(SeqList *L)
{
	int i;
	printf("����Ҫ¼�����Ʒ������\n");
	scanf("%d",&L->len);
	printf("���� ��Ʒ��š���Ʒ����\n");
	for(i=1;i<=L->len;i++)
	{
		scanf("%s %s",L->data[i].no,L->data[i].name);
	}
}
//�����Ʒ��Ϣ
void out(SeqList *L)
{
	int i;
	printf("��Ʒ��š���Ʒ���ơ���Ʒ���������Ʒ����\n");
	for(i=1;i<=L->len;i++)
		printf("%10s%12s%5d%5d\n",L->data[i].no,L->data[i].name,L->data[i].count,L->data[i].maney);
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

//¼��Ʒ���������Ʒ����
void inp_score(SeqList *L)
{
	int i;
	printf("¼����Ʒ���������Ʒ����\n");
        for(i=1;i<=L->len;i++)
		  scanf("%d %d",&(L->data[i].count),&(L->data[i].maney));



}

//������Ʒ��Ϣ
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
		printf("���Ѿ�����\n");
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

//ɾ��
void del(SeqList *L,datatype x)
{
	int i,j;
	i=search(L,x);
    if(i==0)
		printf("Ԫ�ز�����\n");
	else
	{
	    printf("������Ҫɾ������Ʒ����\n");
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
            printf("��Ʒ������\n\n");
        }

	  }
}

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
		case 2:inp_score(stu);break;
		case 3:printf("���������ҵ���Ʒ���\n");
               scanf("%s",x.no);
			   k=search(stu,x);
               if(k==0)
				   printf("Ԫ�ز�����\n");
			   else
				   printf("��Ʒ���: %s,��Ʒ����: %s,����: %d,����: %d\n",stu->data[k].no,stu->data[k].name,stu->data[k].count,stu->data[k].maney);
			   break;
		case 4:printf("������ɾ������Ʒ���\n");
               scanf("%s",x.no);
			   del(stu,x);
			   break;
		case 5:printf("������Ʒ��ţ����ƣ�����������\n");
			   scanf("%s%s%d%d",x.no,x.name,&x.count,&x.maney);
			   ins(stu,x);
			   break;
		case 6:out(stu);break;
		}
	}while(sel!=0);
	return 0;
}


