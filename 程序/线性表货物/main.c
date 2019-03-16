#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}BSTree;

void menu()
{
	printf("1.����tree\n");
	printf("2.�������tree\n");
	printf("3.ͳ��Ҷ�ӽڵ�\n");
	printf("4.�������\n");
	printf("5.�������\n");
	printf("0.�˳�\n");
}

void Createb(BSTree **p)
{
	printf("input a number\n");
	char ch;
	scanf("%s",&ch);
	if(ch!='.')
	{
	    *p=(BSTree*)malloc(sizeof(BSTree));
        (*p)->data=ch;
		printf("���������ӽ��\n");
		Createb(&(*p)->lchild);
        printf("�������Һ��ӽ��\n");
		Createb(&(*p)->rchild);
	}
	else
		*p=NULL;
}
void preorder(BSTree *p)                  //�������
{
	if(p!=NULL)
	{
		printf("%3c",p->data);
		preorder(p->lchild);
	    preorder(p->rchild);
	}
}
void preorderi(BSTree *p)                  //�������
{
	if(p!=NULL)
	{

		preorder(p->lchild);
		printf("%3c",p->data);
	    preorder(p->rchild);
	}
}
void preorderb(BSTree *p)                  //�������
{
	if(p!=NULL)
	{

		preorder(p->lchild);

	    preorder(p->rchild);
	    printf("%3c",p->data);
	}
}

int Countleaf(BSTree *p) //Ҷ�ӽ����
{
	if(p==NULL)
		return 0;
	if(p->rchild==NULL&&p->lchild==NULL)
		return 1;
	return(Countleaf(p->lchild)+Countleaf(p->rchild));
}


void main()
{
	BSTree *root;
	int a=1,n,n1;
	do
	{
		menu();
		printf("���������ѡ��");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			Createb(&root);
			printf("�����ɹ�\n");
			break;
		case 2:
            preorder(root);printf("\n");
			break;
		case 3:
            n1=Countleaf(root);
	        printf("Ҷ�ӽ�����Ϊ��%d\n",n1);
			break;
        case 4:
            preorderi(root);printf("\n");
			break;
        case 5:
            preorderb(root);printf("\n");
			break;
        case 0:
			a=0;
			break;
		}
	}while(a!=0);
}
