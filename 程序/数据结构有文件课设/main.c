/*�̵�������ϵͳ
���ܣ�����һ�̵�������ϵͳ��Ҫ��ÿ�γ���ʱȡ����ʱ����������ӽ���������ֹʱ��Ļ��

�ֲ�ʵʩ��
1��	�������������ƣ���ÿ�ܣ�ȷ���˻��Ի��Ľ��棬ȷ������������
2��	������Ҫ�󣺽���һ���ļ�������5������Ļ���������ܶ���Ʒ��Ϣ�������䣨׷�ӣ����޸ĺ�ɾ���Լ��򵥵�����
3��	��һ��Ҫ��������Ʒ�������Լ����ϵͳ��ѯ���ܡ�����Ȥ��ͬѧ�����Լ�����ϵͳ���ܡ�

Ҫ��1�������Ѻã���������Ҫ���ֺ�
2���������Ӧ��һ����ͼ
3������Ҫ�ӱ�Ҫ��ע��
4��Ҫ�ṩ������Է���
5������һ��Ҫ��������ԣ����ɹ�����һЩ��ҲҪ�������������������еĳ�����û�м�ֵ�ġ�
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
	int intime;   //����ʱ��
	int deadtime;  //��ʹ�õ��������
}datatype;
typedef struct node
{
   datatype data;
   struct node *next;
}nodetype;
//����
void input(nodetype *head)
{
	int n,i;
	datatype x;
    nodetype *s,*tail=head;
	printf("����������\n");
	scanf("%d",&n);
	printf("�����������ơ����(����Ŵ�С��������)�����������ۡ�����ʱ�䣨���磺20180104������ʹ�õ�������ڣ����磺20190104��\n");
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

//���
void output(nodetype *head)
{
	nodetype *s;
	s=head->next;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);   //�������óɻ�ɫ
	printf(" ���     ����     ����  ����    ����ʱ��   ��ʹ�õ��������\n");
	while(s!=NULL)
	{
		printf("%5d%9s%8d %7.2f%12d%12d\n",s->data.no,s->data.name,s->data.num,s->data.price,s->data.intime,s->data.deadtime);
		s=s->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);   //�������óɰ�ɫ
}

//���ļ���Ϣ�Ž�������
void readfile(nodetype *head)
{
   nodetype *s,*tail=head;
   datatype s1;
   FILE * fp2;
	fp2=fopen("E:\\��Ϣ��.txt","r"); /*��������Ϣ��*/
	if(fp2==NULL)
	{
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //�������óɺ�ɫ
		printf("δ�ҵ����ļ�������d�̸�Ŀ¼�½���һ����Ϊ����Ϣ�����ļ�\n");
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //�������óɺ�ɫ
		printf("����ɹ�!\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);   //�������óɰ�ɫ
	}
}
//�˵�
void menu()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	printf("****** 1------����¼�������Ϣ\n");
	printf("****** 2------��� \n");
	printf("****** 3------����\n");
	printf("****** 4------���\n");
	printf("****** 5------����\n");
	printf("****** 6------ͳ�ƿ���������\n");
//	printf("7------������Ϣ���ļ�\n");
	printf("****** 0------�˳�\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//������������ʹ�õĲ���
nodetype* search(nodetype*head,datatype x)
{
	nodetype*p=head->next;
	while(p!=NULL&&p->data.no!=x.no)
	{
		p=p->next;
	}
	return p;
}
//���ҵ������ͬ�������ڲ�ͬ����Ʒ
void searchti(nodetype *head,datatype x)
{
	nodetype*p=head->next;
	int m=0;
	while(p!=NULL)
    {
        if(p->data.no==x.no)
        {
            m++;
            printf("���ƣ�%s��������%d�����ۣ�%.2f������ʱ�䣺%d����ʹ�õ����ʱ�䣺%d\n",p->data.name,p->data.num,p->data.price,p->data.intime,p->data.deadtime);
        }
        p=p->next;
    }
	if(p==NULL&&m==0)
        printf("û�ҵ���\n");
}
//�ñ�źͽ������ڵĲ���
nodetype* search1(nodetype*head,datatype x)
{
	nodetype*p=head->next;
	while(p!=NULL&&(p->data.no!=x.no||p->data.intime!=x.intime))
	{
		 p=p->next;
	}
	return p;
}

//����
void ins(nodetype*head,datatype x)
{
	   nodetype*p=head,*s,*y;
	   y=search1(p,x);
	  if (y!=NULL)
	  {
		   printf("�������ƷҪ����������\n");
		   scanf("%d",&x.num);
		   y->data.num+=x.num;
	  }
	  else
	  {
			printf("�������Ʒ�����ơ����������ۡ���ʹ�õ��������\n");
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
//ɾ��
void del(nodetype*head,datatype x)
{
	nodetype*p,*q,*s,*y=NULL;
	int m=0,num1,tonum=0;//tonum �����ͬ�Ļ��������
	p=search(head,x);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //�������óɺ�ɫ
	if(p==NULL) {printf("û�ҵ���\n");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}   //�������óɰ�ɫ
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
            //    printf("���ƣ�%s��������%d�����ۣ�%.2f������ʱ�䣺%d����ʹ�õ����ʱ�䣺%d\n",p->data.name,p->data.num,p->data.price,p->data.intime,p->data.deadtime);
            }
            s=s->next;
        }

		printf("������Ҫ�����������\n");
		scanf("%d",&num1);

		if (num1==tonum)
		{
			q=head;
			while(q->next!=NULL&& q->next!=p)
				q=q->next;
			 q->next=y->next;
			 printf("����ɹ���\n");
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
			printf("����ɹ���\n");
		}
		else if(num1>tonum)
		{
			printf("��治����\n");
		}

	}
}
//�����ڵ�λ�õ�ð�����򣨰��������
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

//�����ڵ�λ�õ�ð�����򣨰�������������
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

//ͳ�ƻ���������
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
	printf("�ֿ����������Ϊ��%d\n",thnum);
}

//������ļ�
void openfile(nodetype *head)
{
	FILE * fp2;
	fp2=fopen("E:\\��Ϣ��.txt","a+"); /*��������Ϣ��*/
	if(fp2==NULL)
	{
		printf("δ�ҵ����ļ�������E�̸�Ŀ¼�½���һ����Ϊ����Ϣ�����ļ�\n");
	}
	else
	{
		nodetype *s=head->next;
//	    fprintf(fp2," ���     ����     ����  ����  ����ʱ��   ��ʹ�õ��������\n");
	    while(s!=NULL)
		{
		   fprintf(fp2,"%5d%9s%6d %6.2f%12d%12d\n",s->data.no,s->data.name,s->data.num,s->data.price,s->data.intime,s->data.deadtime);
		   s=s->next;
		}
		fclose(fp2);
		printf("����ɹ�\n");
	}
}
//���ļ�
void openfile1(nodetype *head)
{
	FILE * fp2;
	fp2=fopen("E:\\��Ϣ��.txt","w"); /*��������Ϣ��*/
	if(fp2==NULL)
	{
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //�������óɺ�ɫ
		printf("δ�ҵ����ļ�������E�̸�Ŀ¼�½���һ����Ϊ����Ϣ�����ļ�\n");
	}
	else
	{
		nodetype *s=head->next;
//	    fprintf(fp2," ���     ����     ����  ����  ����ʱ��   ��ʹ�õ��������\n");
	    while(s!=NULL)
		{
		   fprintf(fp2,"%5d%9s%6d %6.2f%12d%12d\n",s->data.no,s->data.name,s->data.num,s->data.price,s->data.intime,s->data.deadtime);
		   s=s->next;
		}
		fclose(fp2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //�������óɺ�ɫ
		printf("����ɹ�\n");
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
	printf("�������¼����\n");
	scanf("%d",&pa);
	if (pa==password)
	do
	{
		menu();
		printf("�������ѡ��\n");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1:input(L);
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //�������óɺ�ɫ
			   printf("¼��ɹ���\n");
			   openfile(L);
			   break;
		case 2:readfile(L);
			   bubbledortintime(L);
			   bubbledortno(L);
			   output(L);
			   break;
		case 3:readfile(L);
			   printf("���������ҵı��\n");
	           scanf("%d",&x.no);
			   searchti(L,x);
			   break;
        case 4:printf("����Ԫ�ر�źͽ�������\n");
			   scanf("%d%d",&x.no,&x.intime);
			   ins(L,x);
			   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //�������óɺ�ɫ
			   printf("����ɹ���\n");
			   openfile1(L);
			   break;
		case 5:bubbledortintime(L);
			   bubbledortno(L);
			   printf("����Ҫ����ı��\n");
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //�������óɺ�ɫ
		printf("��������޷��������\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);   //�������óɰ�ɫ
    }
    return 0;
}

