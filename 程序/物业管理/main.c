#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
# define MAXLEN 5000
typedef struct yezhu_stype       // ������
{
	int num;
	char name[20];
	char phone[20];
	int home;
	char unite[20];
	int ele;
	int water;
	int hfee;
	int wfee;
}yezhu;
int input(yezhu yz[]);
int openfile(yezhu yz[]);
void output(yezhu yz[],int n);
int seqsearch1(yezhu yz[],int n,int search_num);
int seqsearch2(yezhu yz[],int n,char search_name[]);
void seqdelete(yezhu yz[],int * len);
void revise(yezhu yz[],int n);
void sort(yezhu yz[],int n);
void save(yezhu yz[],int n);
void seqinsert(yezhu yz[],int * len);
void frist();
int main()            //  ������
{
    frist();
	yezhu yz[MAXLEN];
	int sel,choice,sel1,sel2,password,key;
	int n,* len=&n,i;
	int search_num;
	char search_name[20];
	char message[]={"\n""\n""\n""                       **********************************\n""\n""                              ��ӭʹ����ҵ����ϵͳ                              \n""\n""                       **********************************\n"};
	char menu[]={"                       *****************************\n""\n""                             *1.�����û���Ϣ                              \n""\n""                             *2.����û���Ϣ                              \n""\n""                             *3.�����û���Ϣ                              \n""\n""                             *4.�����û���Ϣ                              \n""\n""                             *5.ɾ���û���Ϣ                              \n""\n""                             *6.�޸��û���Ϣ                              \n""\n""                             *7.�û���Ϣ����                              \n""\n""                             *8.����                                  \n""\n""                             *0.�˳�                                  \n""\n""                       *****************************\n"};
	while(1)
    {
	system("color 30");
	printf("%s",message);
	printf("\n");
	printf("\n");
	printf("                                 1.������Ա��¼\n");
	printf("\n");
	printf("                                 2.��ͨҵ����ѯ\n");
	printf("\n");
	printf("                                 0.�˳�\n");
	printf("\n");
	printf("                                 ����������ѡ��");
	scanf("%d",&sel1);
        switch(sel1)
	{
   case 1:
    {
        system("cls");
        printf("\n\n\n\n                      �������¼���룺");
        scanf(" %d",&password);
        if(password!=123)
        {
            for(key=4;key>0;key--)
            {
                system("cls");
                printf("\n\n         ������󣡣�������%d�λ��ᣩ���ٴ����룺",key-1);
                scanf("%d",&password);
                if(password==123)
                   {
                    	do
	{
		printf("%s",menu);
		printf("\n");
		printf("                             ����0-8��ѡ��");
		scanf("%d",&sel);
		system("cls");
		switch(sel)
		{
		case 1:
		    printf("                       **********************************\n");
		    printf("\n");
			printf("                            1-------------��������\n");
			printf("\n");
			printf("                            2-------------�ļ�¼��\n");
			printf("\n");
			printf("                       **********************************\n");
			printf("\n");
			printf("                                ��ѡ��1��2��");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				n=input(yz);
				break;
			case 2:
			    system("cls");
				n=openfile(yz);
				break;
			}
			break;
			case 2:
			    system("cls");
				output(yz,n);
				break;
			case 3:
			    system("cls");
				do
				{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************��ҵ����Ų���*************************\n");
                     printf("\n");
                    printf("                   2***********************��ҵ����������*************************\n");
                     printf("\n");
			        printf("                   0***********************����ǰһ���˵�*************************\n");
			         printf("\n");
			        printf("                                          ����������ѡ��");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				printf("���������ҵ����ҵ����ţ�");
				scanf("%d",&search_num);
				i=seqsearch1(yz,n,search_num);
				if(i==-1)
					printf("���޴��ˣ�\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("�����û�Ϊ��\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 2:
			    system("cls");
				printf("���������ҵ����ҵ��������");
				scanf("%s",search_name);
				i=seqsearch2(yz,n,search_name);
				if(i==-1)
					printf("���޴��ˣ�\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("�����û�Ϊ��\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 0:
			    system("cls");
				break;
			}
				}while(choice!=0);
				break;
			case 4:
			    system("cls");
				seqinsert(yz,len);
				break;
			case 5:
			    system("cls");
				seqdelete(yz,len);
				break;
			case 6:
			    system("cls");
				revise(yz,n);
				break;
			case 7:
			    system("cls");
				sort(yz,n);
				break;
			case 8:
			    system("cls");
				save(yz,n);
				break;
			case 0:break;
		}
	}while(sel!=0);
	break;
}

                while(key==2)
                {
                    system("cls");
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("                         �Բ���������̫�࣡���˳����ԣ�\n");
                    printf("\n");
                    exit(1);
                }
            }



        }
        else
        {
          	do
	{
		printf("%s",menu);
		printf("\n");
		printf("                             ����0-8��ѡ��");
		scanf("%d",&sel);
		system("cls");
		switch(sel)
		{
		case 1:
		    printf("                       **********************************\n");
		    printf("\n");
			printf("                            1-------------��������\n");
			printf("\n");
			printf("                            2-------------�ļ�¼��\n");
			printf("\n");
			printf("                       **********************************\n");
			printf("\n");
			printf("                                ��ѡ��1��2��");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				n=input(yz);
				break;
			case 2:
			    system("cls");
				n=openfile(yz);
				break;
			}
			break;
			case 2:
			    system("cls");
				output(yz,n);
				break;
			case 3:
			    system("cls");
				do
				{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************��ҵ����Ų���*************************\n");
                     printf("\n");
                    printf("                   2***********************��ҵ����������*************************\n");
                     printf("\n");
			        printf("                   0***********************����ǰһ���˵�*************************\n");
			         printf("\n");
			        printf("                                          ����������ѡ��");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				printf("���������ҵ����ҵ����ţ�");
				scanf("%d",&search_num);
				i=seqsearch1(yz,n,search_num);
				if(i==-1)
					printf("���޴��ˣ�\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("�����û�Ϊ��\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 2:
			    system("cls");
				printf("���������ҵ����ҵ��������");
				scanf("%s",search_name);
				i=seqsearch2(yz,n,search_name);
				if(i==-1)
					printf("���޴��ˣ�\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("�����û�Ϊ��\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 0:
			    system("cls");
				break;
			}
				}while(choice!=0);
				break;
			case 4:
			    system("cls");
				seqinsert(yz,len);
				break;
			case 5:
			    system("cls");
				seqdelete(yz,len);
				break;
			case 6:
			    system("cls");
				revise(yz,n);
				break;
			case 7:
			    system("cls");
				sort(yz,n);
				break;
			case 8:
			    system("cls");
				save(yz,n);
				break;
			case 0:break;
		}
	}while(sel!=0);
	return 0;
}


    };
    break;
   case 2:
    {
        system("cls");
        int i=0;
        FILE * fp2;
	    fp2=fopen("e:\\��Ϣ��.txt","r");
	    		while(! feof(fp2))
		{
			fscanf(fp2,"%d%s%s%d%s%d%d%d%d",&yz[i].num,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
			i++;
		}
		fclose(fp2);
		printf("\n");
		printf("\n");
		printf("                       **********************************\n");
		printf("\n");
        printf("                               1.����ҵ����Ϣ\n");
        printf("\n");
        printf("                               0.�˳�\n");
        printf("\n");
        printf("                       **********************************\n");
        printf("\n");
        printf("                                ����������ѡ��");
        scanf("%d",&sel2);
        switch(sel2)
    {case 1:
        			    system("cls");
				do
				{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************��ҵ����Ų���*************************\n");
                     printf("\n");
                    printf("                   2***********************��ҵ����������*************************\n");
                     printf("\n");
			        printf("                   0***********************����ǰһ���˵�*************************\n");
			         printf("\n");
			        printf("                                          ����������ѡ��");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			    system("cls");
				printf("���������ҵ����ҵ�����ţ�");
				scanf("%d",&search_num);
				n=openfile(yz);
				i=seqsearch1(yz,n,search_num);
				if(i==-1)
					printf("���޴��ˣ�\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("�����û�Ϊ��\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 2:
			    system("cls");
				printf("���������ҵ����ҵ��������");
				scanf("%s",search_name);
				i=seqsearch2(yz,n,search_name);
				if(i==-1)
					printf("���޴��ˣ�\n");
				else
				{
					printf("-------------------------------------------------\n");
					printf("�����û�Ϊ��\n");
					printf("%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
					printf("-------------------------------------------------\n");
				}
				break;
			case 0:
			    system("cls");
				break;
			}
				}while(choice!=0);
				break;
            case 0:
                exit(1);}
    };
    break;
   case 0:
       system("cls");
        printf("\n");
         printf("\n");
          printf("\n");
       printf("\n");
       printf("                                                    лл����ʹ�ã�\n");
       printf("\n");
       printf("\n");
    exit(1);
	}
    }
}
int input(yezhu yz[])             // ������
{                                              // ���뺯��
	int i=0,n=0;
	printf("����������ҵ����Ϣ\n");
	printf("ҵ����ţ����Ϊ-1�������룩��\n");
	scanf("%d",&yz[i].num);
	while(yz[i].num!=-1)
	{
		printf("ҵ��������");
		scanf("%s",yz[i].name);
		printf("ҵ���绰��");
		scanf("%s",yz[i].phone);
		printf("ҵ�����ţ�");
		scanf("%d",&yz[i].home);
		printf("ҵ��������λ��");
		scanf("%s",yz[i].unite);
		printf("�õ�����");
		scanf("%d",&yz[i].ele);
		printf("��ˮ����");
		scanf("%d",&yz[i].water);
		printf("��ҵ�ѣ�");
		scanf("%d",&yz[i].hfee);
		printf("ˮ��ѣ�");
		scanf("%d",&yz[i].wfee);
		i++;
		n++;
		printf("ҵ����ţ����Ϊ-1�������룩��\n");
		scanf("%d",&yz[i].num);
	}
	return n;
}
int openfile(yezhu yz[])             // ������
{                                                // ���ļ���ȡ����
	int i=0;
	FILE * fp2;
	fp2=fopen("e:\\��Ϣ��.txt","r"); /*��������Ϣ��*/
	if(fp2==NULL)
	{
		printf("δ�ҵ����ļ���\n");
		return 0;
	}
	else
	{
		while(! feof(fp2))
		{
			fscanf(fp2,"%d%s%s%d%s%d%d%d%d",&yz[i].num,yz[i].name,yz[i].phone,&yz[i].home,yz[i].unite,&yz[i].ele,&yz[i].water,&yz[i].hfee,&yz[i].wfee);
			i++;
		}
		fclose(fp2);
		printf("����ɹ�\n");
		return i;
	}
}
void output(yezhu yz[],int n)                      // ������
{                                                           //�������
    system("mode con cols=90 lines=60");
	int i;
	printf("----------------------------------------------------------------------\n");
	printf("                              ��ҵ������Ϣ��                           \n");
	printf("----------------------------------------------------------------------\n");
	printf("��� ����    �绰    ���� ������λ �õ��� ��ˮ�� ��ҵ�� ˮ���\n");
	for(i=0;i<n;i++)
		printf("%2d %6s%12s%4d%8s%5d%8d%7d%8d\n",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
	printf("----------------------------------------------------------------------\n");
}
int seqsearch1(yezhu yz[],int n,int search_num)             // ������
{                                                                       // ���Ų��Һ���
	int i=n-1;
	while(i>=0&&yz[i].home!=search_num)
		i--;
	return i;
}
int seqsearch2(yezhu yz[],int n,char search_name[])        // ������
{                                                                       // �������Һ���
	int i=n-1;
	while(i>=0&&(strcmp(yz[i].name,search_name)!=0))
		i--;
	return i;
}
void seqinsert(yezhu yz[],int * len)           // ������
{                                                          // ���뺯��
	int j,k,insert_num,choice;
	char insert_name[20];
	yezhu ins_yezhu;
	if(* len==MAXLEN-1)
		printf("�û�������");
	else
	{
		do
		{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************��ҵ����Ų���*************************\n");
                     printf("\n");
                    printf("                   2***********************��ҵ����������*************************\n");
                     printf("\n");
			        printf("                   0***********************����ǰһ���˵�*************************\n");
			         printf("\n");
			        printf("                                          ����������ѡ��");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				printf("���������λ�ã�����ĳҵ�����ǰ����\n");
				scanf("%d",&insert_num);
				k=seqsearch1(yz,* len,insert_num);
				if(k==-1)
					printf("��Ч�Ĳ���λ�ã�\n");
				else
				{
					printf("�����������Ϣ�����  ����     �绰     ����  ������λ  �õ���  ��ˮ��  ��ҵ��  ˮ���\n");
					scanf("%d%s%s%d%s%d%d%d%d",&ins_yezhu.num,ins_yezhu.name,ins_yezhu.phone,&ins_yezhu.home,ins_yezhu.unite,&ins_yezhu.ele,&ins_yezhu.water,&ins_yezhu.hfee,&ins_yezhu.wfee);
					for(j=* len-1;j>=k;j--)
						yz[j+1]=yz[j];
					yz[k]=ins_yezhu;
					(* len)++;
					printf("����ɹ���\n");
				}
				break;
			case 2:
				printf("���������λ�ã�����ĳҵ������֮ǰ����\n");
				scanf("%s",insert_name);
				k=seqsearch2(yz,* len,insert_name);
				if(k==-1)
					printf("��Ч�Ĳ���λ�ã�\n");
				else
				{
					printf("�����������Ϣ�����  ����     �绰     ����  ������λ  �õ���  ��ˮ��  ��ҵ��  ˮ���\n");
					scanf("%d%s%s%d%s%d%d%d%d",&ins_yezhu.num,ins_yezhu.name,ins_yezhu.phone,&ins_yezhu.home,ins_yezhu.unite,&ins_yezhu.ele,&ins_yezhu.water,&ins_yezhu.hfee,&ins_yezhu.wfee);
					for(j=* len-1;j>=k;j--)
						yz[j+1]=yz[j];
					yz[k]=ins_yezhu;
					(* len)++;
					printf("����ɹ���\n");
				}
				break;
			case 0:
				break;
			}
		}while(choice!=0);
	}
}
void seqdelete(yezhu yz[],int * len)           // ������
{                                                           // ɾ������
	int j,k,choice;
	char delete_name[20];
	int delete_num;
	if(* len==0)
		printf("�û��ѿգ�");
	else
	{
		do
		{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************��ҵ�����ɾ��*************************\n");
                     printf("\n");
                    printf("                   2***********************��ҵ������ɾ��*************************\n");
                     printf("\n");
			        printf("                   0***********************����ǰһ���˵�*************************\n");
			         printf("\n");
			        printf("                                          ����������ѡ��");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:printf("������ɾ��ҵ����ҵ����ţ�");
				   scanf("%d",&delete_num);
				   k=seqsearch1(yz,* len,delete_num);
				   if(k==-1)
					   printf("��Ч��ɾ��λ�ã�\n");
				   else
				   {
					   for(j=k+1;j<* len;j++)
						   yz[j-1]=yz[j];
					   (*len)--;
					   printf("ɾ���ɹ���\n");
				   }
				   break;
			case 2:printf("������ɾ��ҵ����ҵ��������");
				   scanf("%s",delete_name);
				   k=seqsearch2(yz,* len,delete_name);
				   if(k==-1)
					   printf("��Ч��ɾ��λ�ã�\n");
				   else
				   {
					   for(j=k+1;j<* len;j++)
						   yz[j-1]=yz[j];
					   (*len)--;
					   printf("ɾ���ɹ���\n");
				   }
				   break;
			case 0:break;
			}
		}while(choice!=0);
	}
}
void revise(yezhu yz[],int n)                // ������
{                                                         //�޸ĺ���
	int knum,k,choice;
	char kname[20];
	do
	{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************��ҵ������޸�*************************\n");
                     printf("\n");
                    printf("                   2***********************��ҵ�������޸�*************************\n");
                     printf("\n");
			        printf("                   0***********************����ǰһ���˵�*************************\n");
			         printf("\n");
			        printf("                                          ����������ѡ��");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:printf("�������޸�ҵ����ҵ����ţ�");
				   scanf("%d",&knum);
				   k=seqsearch1(yz,n,knum);
				   if(k==-1)
					   printf("���޴��ˣ�\n");
				   else
				   {
					printf("�������޸���Ϣ�����  ����     �绰     ����  ������λ  �õ���  ��ˮ��  ��ҵ��  ˮ���\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].num,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,&yz[k].water,&yz[k].hfee,&yz[k].wfee);
					   printf("�޸ĳɹ���\n");
				   }
				   break;
			case 2:printf("�������޸�ҵ����ҵ��������");
				   scanf("%s",kname);
				   k=seqsearch2(yz,n,kname);
				   if(k==-1)
					   printf("���޴��ˣ�\n");
				   else
				   {
					printf("�������޸���Ϣ�����  ����     �绰     ����  ������λ  �õ���  ��ˮ��  ��ҵ��  ˮ���\n");
					scanf("%d%s%s%d%s%d%d%d%d",&yz[k].num,yz[k].name,yz[k].phone,&yz[k].home,yz[k].unite,&yz[k].ele,&yz[k].water,&yz[k].hfee,&yz[k].wfee);
					printf("�޸ĳɹ���\n");
				   }
				   break;
			case 0:
			    system("cls");
				break;
			}
		}while(choice!=0);
	}


void sort(yezhu yz[],int n)           // ������
{                                                 // ������
	int i,j,k,choice;
	yezhu t;
	do
	{
				    printf("\n");
                    printf("\n");
                    printf("                   1***********************��ҵ����������*************************\n");
                     printf("\n");
                    printf("                   2***********************��ҵ����������*************************\n");
                     printf("\n");
			        printf("                   0***********************����ǰһ���˵�*************************\n");
			         printf("\n");
			        printf("                                          ����������ѡ��");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
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
			case 2:
				for(i=0;i<n-1;i++)
				{
					k=i;
					for(j=i+1;j<n;j++)
						if(strcmp(yz[k].name,yz[j].name)>0)
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
			    system("cls");
			    break;
			}
		}while(choice!=0);
	}



void save(yezhu yz[],int n)             // ������
{                                                  // ���溯��
	int i;
	FILE * fp1;
	fp1=fopen("e:\\��Ϣ��.txt","w+");
	if(fp1==NULL)
		printf("����ʧ��\n");
	else
	{
	    fprintf(fp1,"%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[0].num,yz[0].name,yz[0].phone,yz[0].home,yz[0].unite,yz[0].ele,yz[0].water,yz[0].hfee,yz[0].wfee);
		for(i=1;i<n;i++)
			fprintf(fp1,"\n%2d%6s%12s%4d%8s%5d%8d%7d%8d",yz[i].num,yz[i].name,yz[i].phone,yz[i].home,yz[i].unite,yz[i].ele,yz[i].water,yz[i].hfee,yz[i].wfee);
		fclose(fp1);
		printf("����ɹ�\n");
	}
}



void frist()              // ������
{                                    // ��ӭ���溯��
        int i,n=5,m=0;
        while (n)
        {
            if (m==0)
            {
                 printf("\n");
                  printf("\n\n\n");
    printf("                              ^_^ ��ӭ����ĳС����ҵ����ϵͳ����");
     printf("��");
            for(i=0;i<5;i++)
        system("color 0A");
            for(i=0;i<5;i++)
        system("color 0C");
            for(i=0;i<5;i++)
        system("color 0B");
            for(i=0;i<5;i++)
        system("color 0D");
            for(i=0;i<5;i++)
        system("color 0C");
        n--;
                 m=1;
            }
           else if (m==1)
           {
                m=0;
                 printf("\n");
                  printf("\n\n\n");
    printf("                              ^_^ ��ӭ����ĳС����ҵ����ϵͳ����");
                 printf("��");
            for(i=0;i<5;i++)
        system("color 0A");
            for(i=0;i<5;i++)
        system("color 3C");
            for(i=0;i<5;i++)
        system("color 1B");
            for(i=0;i<5;i++)
        system("color 7D");
            for(i=0;i<5;i++)
        system("color 2A");
        n--;
           }

        }
         system("cls");
}
