#include <stdio.h>                     //ֱ�ӣ�ð���Ѻ�
#include <stdlib.h>
#include <time.h>
#define MAXNUM 1000
typedef struct
{
    int key;
}RecordType;

void D_Insert(RecordType RT[],int n)     //ֱ�Ӳ�������
{                                       //��n����¼ֱ�Ӳ�������
    int i,j,mov=0,com=0;
	RecordType R[110];
	for(i=0;i<100;i++)
	{
		R[i].key=RT[i].key;
	}
    for(i=1;i<n;i++)                   //����n-1������
        if(R[i].key<R[i-1].key)
    {
        R[101]=R[i];                      //���ò��Ҽ����ڲ�����������¼R[i]��ֵ
        j=i-1;
        while(R[j].key>R[101].key)
        {                              //���ؼ���ֵ����R[i].key������R˳�����һ����¼λ��
            R[j+1]=R[j];
            j--;
			mov++;
			com=mov;
        }
        R[j+1]=R[101];                     //����ֵ
    }
		printf("ֱ�Ӳ���������ƶ�����Ϊ%d��\n              �Ƚϴ���Ϊ%d��\n",mov,com);
}

void BubbleSort(RecordType R[],int n)         //ð������
{                                             //��n����¼����ð������
    int i,j,swap,mov=0,com=0;
    for(i=1;i<n;i++)                          //����n-1������
    {
        swap=0;                               //����δ������־
        for(j=0;j<n-i;j++)                   //���������Ƚ�
        {    com++;
			if(R[j].key>R[j+1].key)           //�����򽻻�
        {
            R[101]=R[j];
            R[j]=R[j+1];
            R[j+1]=R[101];
            swap=1;                           //�н�������
            mov++;
        }}
        if(swap==0)
            break;                            //δ���ֽ������������
    }
	printf("ð��������ƶ�����Ϊ%d��\n          �Ƚϴ���Ϊ%d��\n",mov,com);
	//for(j=0;j<n;j++){printf("%d\t",R[j].key);}
}

int Partition(RecordType R[],int i,int j)   //�����㷨
{                                           //��R[i]~R[j],��R[i]Ϊ��׼��¼���л��֣�������R[i]�ڻ��ֺ����ȷλ��
    R[101]=R[i];                              //�ݴ��׼��¼
    while(i<j)                              //�ӱ����˽������м����ɨ��
    {
        while(i<j&&R[j].key>=R[101].key)       //��������ɨ����ҵ�һ���ؼ���С��R[0].key�ļ�¼
            j--;
        if(i<j)                              //��i<jʱ����R[i].keyС��R[0].key,��R[j]���������
        {
            R[i]=R[j];
            i++;
        }
        while(i<j&&R[i].key<=R[101].key)       //��������ɨ����ҵ�һ���ؼ��ִ���R[0].key�ļ�¼R[i]
            i++;
        if(i<j)                              //��i<jʱ����R[i].key����R[0].key��ֵ������������ұ�
        {
            R[j]=R[i];
            j--;
        }
    }
    R[i]=R[101];                               //����׼��¼��������Ӧ�źõ�λ��
	return i;                                //���ػ�׼��¼R[0]���շ��õ�λ��
}
void QuickSort(RecordType R[],int s,int t)
{
    int i;
    if(s<t)
    {
        i=Partition(R,s,t);                    //iΪ��׼��¼��λ�ý����Ϊ������
        QuickSort(R,s,i-1);                    //�Ա�R[s]~R[i-1]���п�������
        QuickSort(R,i+1,t);                    //�Ա�R[i+1]~R[t]���п�������
    }
	//for(i=0;i<t;i++){printf("%d\t",R[i].key);}
	//printf("����������ƶ�����Ϊ%d��\n          �Ƚϴ���Ϊ%d��\n");
}

void HeapAdjust(RecordType R[],int s,int t,int *mov,int *com)       //���ڴ󶥶ѵĶ�����
{                                                 //ֻ��R[s]���е�����ʹ��Ϊ������ȫ��������Ϊһ����

    int i,j,com1=0,mov1=0;
    R[101]=R[s];                                    //R[a]�ݴ���R[0]
    i=s;
    for(j=2*i;j<=t;j=2*j)                         //�عؼ��ֽϴ�ĺ������µ������ȼٶ�Ϊ����
    {
//        com1++;
        if(j<t&&R[j].key<R[j+1].key)
        {j=j+1;com1++;}                                //�Һ��ӹؼ��ִ������Һ������µ���
        if(R[101].key>R[j].key)                     //������ѵĶ��壬�������µ���
           {com1++; break;}
        R[i]=R[j]; mov1++;                               //���ؼ��ִ�ĺ���R[j]������˫�׽��R[i]
        i=j;                                      //��λ�ں��ӽ��������µ���
    }
    R[i]=R[101];                                  //�ҵ�����Ѷ����R[0]����λ��i����R[s]�����ڴ�
    *com+=com1;
    *mov+=mov1;
}
void HeapSort(RecordType R[],int n)
{
    int i,mov=0,com=0;                                        //��N����¼���ж�����
    for(i=n/2;i>0;i--)
        HeapAdjust(R,i,n,&mov,&com);
        for(i=n;i>1;i--)                          //�Գ�ʼ�ѽ���n-1�˶�����
    {
        R[101]=R[1];                                //�Ѷ���R[1]��ѵ׵�R[i]���н���
        R[1]=R[i];
        R[i]=R[101];
        HeapAdjust(R,1,i-1,&mov,&com);                       //��δ�����ǰi-1��������µ���Ϊ��
    }
		printf("��������ƶ�����Ϊ%d��\n          �Ƚϴ���Ϊ%d��\n",mov,com);
	//	for(i=0;i<n;i++){printf("%d\t",R[i].key);}
}
/*void HeapAdjust(int *R,int s,int t)       //���ڴ󶥶ѵĶ�����
{                                                 //ֻ��R[s]���е�����ʹ��Ϊ������ȫ��������Ϊһ����

   int p=R[s];                                    //R[a]�ݴ���R[0]
    int i=2*s+1;
	while(i<=t)
                             //�عؼ��ֽϴ�ĺ������µ������ȼٶ�Ϊ����
    {
        if(i+1<=t&&R[i]<R[i+1])
            i++;                                //�Һ��ӹؼ��ִ������Һ������µ���
        if(R[i]<=p)                     //������ѵĶ��壬�������µ���
            break;
        R[s]=R[i];                                //���ؼ��ִ�ĺ���R[j]������˫�׽��R[i]
        s=i;
		i=2*s+1;//��λ�ں��ӽ��������µ���
    }
    R[s]=p;                                    //�ҵ�����Ѷ����R[0]����λ��i����R[s]�����ڴ�
}
void HeapSort(int *R,int n)
{
    int i;                                        //��N����¼���ж�����
    for(i=n/2-1;i>=0;i--)
        HeapAdjust(R,i,n-1);
        for(i=n-1;i>0;i--)                          //�Գ�ʼ�ѽ���n-1�˶�����
    {
       int p=R[i];                                //�Ѷ���R[1]��ѵ׵�R[i]���н���
        R[i]=R[0];
        R[0]=p;
        HeapAdjust(R,0,i-1);                       //��δ�����ǰi-1��������µ���Ϊ��
    }
	//	for(i=0;i<n;i++){printf("%d\t",R[i].key);}
}*/

int main()
{   int i;
    int p=10;
	int w=1,y=100;
    RecordType R[110];
    time_t t;
    srand((unsigned) time(&t));
	while(p--)                                //��ʮ����������������������
    {
		for(i=0;i<10;i++)
		{
    printf("Hundred random numbers from 0 to 999\n\n");
    for (i=0; i<100; i++)
    {
        R[i].key=rand()%1000;
    printf("%d\t", R[i].key);              //���������
    }
	}

    D_Insert(R,y);
    BubbleSort(R,y);
    //Partition(R,w,y);
    QuickSort(R,w,y);
    //HeapAdjust(R,w,y);
    HeapSort(R,y);
	}
 return 0;
}
