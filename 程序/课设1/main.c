#include<stdio.h>
#include<malloc.h>
void caidan(int i);
void funprint(struct yezhu_type *p,int len );
struct yezhu_type
{
	int number;        //ҵ�����
	char name[20];     //ҵ������
	long int phone;   //ҵ���绰
	int home;       //ҵ������
	char unite[100];     //ҵ��������λ
	int ele;        //�õ���
	int water;     //��ˮ��
	int hfee;     //��ҵ��
	int wfee;      //ˮ���

};


int main()
{
    int len,i;
	struct yezhu_type *p;
	/*���봢��ռ�*/
	caidan(i);

/*	p= (struct yezhu_type *) malloc (sizeof (struct yezhu_type));
	puts ("������ҵ����Ϣ��\n��� ���� �绰 ���� ������λ �õ��� ��ˮ�� ��ҵ�� ˮ���\n");
	scanf ("%d %s %ld %d %s %d %d %d %d",&p->number,p->name,&p->phone,&p->home,p->unite,&p->ele,&p->water,&p->hfee,&p->wfee);
	printf("��� ���� �绰 ���� ������λ �õ��� ��ˮ�� ��ҵ�� ˮ���\n");
	printf("%0d %s %ld %d %s %d %d %d %d",p->number,p->name,p->phone,p->home,p->unite,p->ele,p->water,p->hfee,p->wfee);
	*/
	free( p );

	printf("\n-----�������----\n");
	return 0;


}

void caidan(int i)
{
    struct yezhu_type *p;
    int len;
    printf("\n\n");

    printf("***************ĳС����ҵ����ϵͳ***************\n");
    printf("\n");
    printf("*********��ѡ�������Ӧ���ѡ�����蹦��*********\n\n");
    printf ("            1  ¼��ҵ����Ϣ\n\n");
    printf ("            2  �޸�ҵ����Ϣ\n\n");
    printf ("            3  ɾ��ҵ����Ϣ\n\n");
    printf ("            4  ҵ����Ϣ����\n\n");
    printf ("            5  ���ҵ����Ϣ\n\n");
    printf ("            6  ��ѯҵ����Ϣ\n\n");
    printf ("            7  �鿴ҵ���ɷ��嵥\n\n");
    printf("************************************************\n\n");

    switch (i)
    {
        case 1: funprint(p,len); break;
       // case 2: funchange( ); break;
      //  case 3: fundelete( ); break;
      //  case 4: funsort( ); break;
      //  case 5: funlook( ); break;
      //  case 6: funsearch( ); break;
      //  case 7: funfee( ); break;
        default :
            {
                printf("������˵��ж�Ӧ�����\n");
                caidan(i);
            }
    }


}
/////////////////////////
void funprint(struct yezhu_type *p,int len )
{
    printf("������Ҫ¼���ҵ������:\n");
      scanf("%d",&len);
  //  p= (struct yezhu_type *) malloc (sizeof (struct yezhu_type));
      p= (struct yezhu_type *) malloc (*len);

	puts ("������ҵ����Ϣ��\n���  ����  �绰     ����  ������λ  �õ���  ��ˮ��  ��ҵ��  ˮ���\n");
	for (i=0;i<len;i++)
    {
        scanf ("%d %s %ld %d %s %d %d %d %d",&p->number,p->name,&p->phone,&p->home,p->unite,&p->ele,&p->water,&p->hfee,&p->wfee);
//	    printf("��� ���� �绰 ���� ������λ �õ��� ��ˮ�� ��ҵ�� ˮ���\n");
 //       printf("%0d %s %ld %d %s %d %d %d %d",p->number,p->name,p->phone,p->home,p->unite,p->ele,p->water,p->hfee,p->wfee);
    }

    }

