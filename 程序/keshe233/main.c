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
	int number;        //ҵ�����
	char name[20];     //ҵ������
	char phone[50];   //ҵ���绰
	int home;       //ҵ������
	char unite[100];     //ҵ��������λ
	int ele;        //�õ���
	int water;     //��ˮ��
	int hfee;     //��ҵ��
	int wfee;      //ˮ���

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
   //                         printf("                           ������-1������� \n");
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
                 printf("�����������\n");
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
//	printf("\n-----�������----\n");
	return 0;
}

////////////////////�˵�///
void caidan( )
{
    system("cls");
    system("mode con cols=48 lines=30");
    system("color 1C");
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
    printf ("            -1 �˳�ϵͳ\n\n");
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
    printf("������Ҫ¼���ҵ������:\n");
      scanf("%d",&n);
      *p=n;



	puts ("������ҵ����Ϣ��\n���  ����  �绰     ����  ������λ  �õ���  ��ˮ��  ��ҵ��  ˮ���\n");
	for (i=0;i<n;i++)
    {
        scanf("%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);

    }
     if ((fp=fopen("E:\\ҵ����Ϣ.txt","a"))==NULL)
      {
          printf("Cannot open file strike any key exit!");
          getchar ();
          return 1;
      }
//      fputc('\n',fp);
      //  ��ͷ//////
//	fprintf(fp,"%8s %8s %10s %4s %8s %4s %4s %4s %4s","ҵ�����","ҵ������","ҵ���绰","ҵ������","ҵ��������λ","�õ���","��ˮ��","��ҵ��","ˮ���");
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
    printf("*********************��ѡ���ѯ��ʽ*********************\n");
    printf("�������������� 1��ҵ������\n");
    printf("               2  ҵ������\n");
    scanf("%d",&i);
    if (i==1)
    {
		printf("������Ҫ���ҵ�ҵ��������\n");
		scanf("%s",&kname[20]);
		printf("ҵ����� ҵ������ ҵ���绰  ҵ������ ҵ����λ  �õ��� ��ˮ�� ��ҵ�� ˮ���\n");

        seqsearch1(yz,n,kname);
		printf("�Ƿ�Ҫ������ѯ\n\n");
      printf("*******1   �� *******\n\n");
       printf("*******2   �� *******\n\n");
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
		printf("������Ҫ���ҵ�ҵ�����ţ�\n");
		scanf("%d",&knum);
		printf("ҵ����� ҵ������ ҵ���绰  ҵ������ ҵ����λ  �õ��� ��ˮ�� ��ҵ�� ˮ���\n");

        seqsearch2(yz,n,knum);
        printf("�Ƿ�Ҫ������ѯ\n\n");
      printf("*******1   �� *******\n\n");
       printf("*******2   �� *******\n\n");
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


int seqsearch1(struct yezhu_type yz[],int n,char kname[])/*��ҵ�����Ʋ���*/
{
 //   system("cls");
 //   system("color 1A");
  //  system("mode con cols=100 lines=30");

 //  char a[20];
   int i=0,z=0,j=0;
   FILE *fp;
   fp=fopen("E:\\ҵ����Ϣ.txt","r");
   while(!feof(fp))
       // for (i=0;i<n+9;i++)
   {
       fscanf(fp,"%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
   i++;
   }
    fclose(fp);

  // printf("������Ҫ���ҵ�ҵ��������\n");
  // scanf("%s",a);
  for (j=0;j<i;j++)
   {
       if (strcmp(kname,yz[j].name)==0)
       {
  //         printf("ҵ����� ҵ������ ҵ���绰  ҵ������ ҵ����λ  �õ��� ��ˮ�� ��ҵ�� ˮ���\n");
           printf("%03d %11s %14s %5d %10s %8d %5d %5d %5d",yz[j].number,yz[j].name,yz[j].phone,yz[j].home,yz[j].unite,yz[j].ele,yz[j].water,yz[j].hfee,yz[j].wfee);

       }
       else
       {
           printf("error\n");
  //         return -1;
           break;
       }
  }
  //    printf("�Ƿ�Ҫ������ѯ\n\n");
  //    printf("*******1   �� *******\n\n");
  //     printf("*******2   �� *******\n\n");
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

int seqsearch2(struct yezhu_type yz[],int n,int knum)/*��ҵ�����Ų���*/
{
    system("cls");
   int m,i=0,z=0,j=0;
   FILE *fp;
   fp=fopen("E:\\ҵ����Ϣ.txt","r");
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
 //  printf("������Ҫ���ҵ�ҵ�����ţ�\n");

 //  scanf("%d",&m);
 //  printf("ҵ����� ҵ������ ҵ���绰  ҵ������ ҵ����λ  �õ��� ��ˮ�� ��ҵ�� ˮ���\n");
 //  while (m==yz[i].home)
 //  {
 for (j=0;j<i;j++)
   {
       if (knum==yz[j].home)
       {
  //         printf("ҵ����� ҵ������ ҵ���绰  ҵ������ ҵ����λ  �õ��� ��ˮ�� ��ҵ�� ˮ���\n");
           printf("%03d %11s %14s %5d %10s %8d %5d %5d %5d",yz[j].number,yz[j].name,yz[j].phone,yz[j].home,yz[j].unite,yz[j].ele,yz[j].water,yz[j].hfee,yz[j].wfee);

       }
       else
       {
           printf("error\n");
  //         return -1;
           break;
       }
  }
  //  printf("�Ƿ�Ҫ������ѯ\n\n");
  //     printf("*******1   �� *******\n\n");
  //     printf("*******2   �� *******\n\n");
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
//���������������������������������ҡ�����������������������������������


void sort(struct yezhu_type yz[],int n)
{
    system("cls");
    system("color 1C");
	int i,j,k,choice;
	struct yezhu_type t;
	FILE *fp;
	fp=fopen("E:\\ҵ����Ϣ.txt","r");
	do
	{
		printf("1**********��ҵ���������*****\n");
		printf("2**********��ҵ����������*****\n");
		printf("0**********�����ϼ��˵�*****\n");
		printf("������ѡ��\n");
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
	fp=fopen("E:\\ҵ����Ϣ.txt","r");

      while (!feof(fp))
       // for (i=0;i<n+9;i++)
     {
       fscanf(fp,"%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
         i++;
     }
    fclose(fp);

    printf("ҵ����� ҵ������ ҵ���绰  ҵ������ ҵ����λ  �õ��� ��ˮ�� ��ҵ�� ˮ���\n");
    for (j=0;j<i;j++)
    {
        printf("%03d %11s %14s %5d %10s %8d %5d %5d %5d\n",yz[j].number,yz[j].name,yz[j].phone,yz[j].home,yz[j].unite,yz[j].ele,yz[j].water,yz[j].hfee,yz[j].wfee);

    }

        printf("������-1�������\n");
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
			printf("1***********************��ҵ�������޸�*************************\n");
			printf("2***********************��ҵ�������޸�*************************\n");
			printf("0***********************����ǰһ���˵�*************************\n");
			printf("����������ѡ��\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:printf("�������޸�ҵ����ҵ�����ţ�");
				   scanf("%d",&knum);
				   k=seqsearch2(yz,n,knum);
				   if(k==-1)
					   printf("���޴��ˣ�\n");
				   else
				   {
					printf("�������޸���Ϣ��ҵ�����  ҵ������  ҵ���绰  ҵ������  ҵ��������λ  �õ���  ��ˮ��  ��ҵ��  ˮ���\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].number,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,&yz[k].water,&yz[k].hfee,&yz[k].wfee);
					   printf("�޸ĳɹ���\n");
				   }
				   break;
			case 2:printf("�������޸�ҵ����ҵ��������");
				   scanf("%s",kname);
				   k=seqsearch1(yz,n,kname);
				   if(k==-1)
					   printf("���޴��ˣ�\n");
				   else
				   {
					printf("�������޸���Ϣ��ҵ�����  ҵ������  ҵ���绰  ҵ������  ҵ��������λ  �õ���  ��ˮ��  ��ҵ��  ˮ���\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].number,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,&yz[k].water,&yz[k].hfee,&yz[k].wfee);
					printf("�޸ĳɹ���\n");
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
    printf("***************ĳС����ҵ����ϵͳ***************\n");
    printf("\n");
    printf("************************************************\n\n");
    printf ("            \n");
    printf ("            \n");
    printf ("            \n");
    printf ("            \n");
    printf ("            \n");
    printf ("          \n\n");
    printf ("              �鿴ҵ���ɷ��嵥\n\n");
    printf ("           \n\n");
    printf ("            \n");
    printf ("            \n");
    printf ("            \n");
    printf ("             ����1������һ��\n\n" );
    printf ("             ����0����\n\n");
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
        printf("\t\t�����Ա����6λ��¼���룺\n\n\n");

            scanf("%d",&p);
            return p;
}

void caidan2()
{
     printf("\n\n");

    printf("***************ĳС����ҵ����ϵͳ***************\n");
    printf("\n");
    printf("*********��ѡ�������Ӧ���ѡ���������*********\n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            1  ��ҵ����Ա\n\n");
    printf ("            2  С��ҵ��\n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            \n\n");
    printf ("            -1 �˳�ϵͳ\n\n");
    printf("************************************************\n\n");


}


int seqdelete(struct yezhu_type yz[],int n)
{
    int j,k,choice,x,i;
  //   FILE *fp;
//	fp=fopen("C:\\Users\\gwq12\\Desktop\\����\\ҵ����Ϣ.txt","r");
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
        printf("               �û��ѿգ�\n\n");
        printf("               ����0����\n\n");
		scanf("%d",&x);
		return x;
    }

	else
	{
		do
		{
			printf("1***********************��ҵ�����ɾ��*************************\n");
			printf("2***********************��ҵ������ɾ��*************************\n");
			printf("0***********************����ǰһ���˵�*************************\n");
			printf("����������ѡ��\n");
			scanf("%d",&choice);
			system("cls");
			switch(choice)
			{
			case 1:printf("������ɾ��ҵ����ҵ����ţ�");
				   scanf("%d",&delete_num);
				   k=seqsearch2(yz,n,delete_num);
				   if(k==-1)
					   printf("��Ч��ɾ��λ�ã�\n");
				   else
				   {
					   for(j=k+1;j<n;j++)
						   yz[j-1]=yz[j];
					   (n)--;
					   printf("ɾ���ɹ���\n");
				   }
				   break;
			case 2:printf("������ɾ��ҵ����ҵ��������");
				   scanf("%s",delete_name);
				   k=seqsearch1(yz,n,delete_name);
				   if(k==-1)
					   printf("��Ч��ɾ��λ�ã�\n");
				   else
				   {
					   for(j=k+1;j<n;j++)
						   yz[j-1]=yz[j];
					   n--;
					   printf("ɾ���ɹ���\n");
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
	fp=fopen("E:\\ҵ����Ϣ.txt","r");

	while (!feof(fp))
       // for (i=0;i<n+9;i++)
     {
       fscanf(fp,"%d %s %s %d %s %d %d %d %d",&yz[i].number,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
         i++;
     }
    fclose(fp);
    printf("\n\n\n");
     printf("*****************************************************************************\n\n\n");
     printf("                             ҵ���ɷ��嵥\n\n\n");
     printf("******************************************************************************\n\n");

    printf("ҵ����� ҵ������ ҵ���绰  ҵ������ ҵ����λ  �õ��� ��ˮ�� ��ҵ�� ˮ���\n");
    for (j=0;j<i;j++)
    {
        printf("%03d %11s %14s %5d %10s %8d %5d %5d %5d\n",yz[j].number,yz[j].name,yz[j].phone,yz[j].home,yz[j].unite,yz[j].ele,yz[j].water,yz[j].hfee,yz[j].wfee);

    }
        printf("������-1�������\n");
        scanf("%d",&k);
}
