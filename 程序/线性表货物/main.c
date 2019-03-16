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
	printf("1.创建tree\n");
	printf("2.先序遍历tree\n");
	printf("3.统计叶子节点\n");
	printf("4.中序遍历\n");
	printf("5.后序遍历\n");
	printf("0.退出\n");
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
		printf("请输入左孩子结点\n");
		Createb(&(*p)->lchild);
        printf("请输入右孩子结点\n");
		Createb(&(*p)->rchild);
	}
	else
		*p=NULL;
}
void preorder(BSTree *p)                  //先序遍历
{
	if(p!=NULL)
	{
		printf("%3c",p->data);
		preorder(p->lchild);
	    preorder(p->rchild);
	}
}
void preorderi(BSTree *p)                  //中序遍历
{
	if(p!=NULL)
	{

		preorder(p->lchild);
		printf("%3c",p->data);
	    preorder(p->rchild);
	}
}
void preorderb(BSTree *p)                  //后序遍历
{
	if(p!=NULL)
	{

		preorder(p->lchild);

	    preorder(p->rchild);
	    printf("%3c",p->data);
	}
}

int Countleaf(BSTree *p) //叶子结点数
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
		printf("请输入你的选择：");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			Createb(&root);
			printf("建立成功\n");
			break;
		case 2:
            preorder(root);printf("\n");
			break;
		case 3:
            n1=Countleaf(root);
	        printf("叶子结点个数为：%d\n",n1);
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
