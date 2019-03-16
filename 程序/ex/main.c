#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXNUM 1000
typedef struct
{
    int key;
}RecordType;

void D_Insert(RecordType A[],int n)     //ֱ�Ӳ�������
{                                       //��n����¼ֱ�Ӳ�������
    int i,j,com=0,mov=0;
    RecordType R[110];
    for(i=1;i<10;i++)
    {
        R[i].key=A[i].key;
    }
    for(i=2;i<=n;i++)                   //����n-1������
        if(R[i].key<R[i-1].key)
    {
        R[0]=R[i];                      //���ò��Ҽ����ڲ�����������¼R[i]��ֵ
        j=i-1;
        while(R[j].key>R[0].key)
        {                              //���ؼ���ֵ����R[i].key������R˳�����һ����¼λ��
            R[j+1]=R[j];
            j--;
			mov++;
	    	com=mov;
        }
        R[j+1]=R[0];                    //����ֵ

		}
	printf("ֱ�Ӳ���������ƶ�����Ϊ%d��\n              �Ƚϴ���Ϊ%d��\n",mov,com);
	printf("output:\n");
    for(i=1;i<=10;i++)
    {
        printf("%d ",R[i]);
    }
    printf("\n");
}

void BubbleSort(RecordType A[],int n)         //ð������
{                                             //��n����¼����ð������
    int i,j,swap,com=0,mov=0;
    RecordType R[110];
    for(i=1;i<10;i++)
    {
        R[i].key=A[i].key;
    }
    for(i=1;i<n;i++)                          //����n-1������
    {
        swap=0;                               //����δ������־
        for(j=1;j<=n-i;j++)                   //���������Ƚ�
         if(R[j].key>R[j+1].key)           //�����򽻻�
        {
		    R[0]=R[j];
            R[j]=R[j+1];
            R[j+1]=R[0];
            swap=1;                       //�н�������
			mov++;
        }
				com++;
        //if(swap==0)                          //δ���ֽ������������
          //  break;
		}

	printf("ð��������ƶ�����Ϊ%d��\n          �Ƚϴ���Ϊ%d��\n",mov,com);
}

int Partition(RecordType A[],int i,int j)   //�����㷨
{   int mov=0,com=0;
    RecordType R[110];
    for(i=1;i<10;i++)
    {
        R[i].key=A[i].key;
    }                                        //��R[i]~R[j],��R[i]Ϊ��׼��¼���л��֣�������R[i]�ڻ��ֺ����ȷλ��
    R[0]=R[i];                              //�ݴ��׼��¼
    while(i<j)                              //�ӱ����˽������м����ɨ��
    {
		mov++;
        while(i<j&&R[j].key<=R[0].key)       //��������ɨ����ҵ�һ���ؼ���С��R[0].key�ļ�¼
            j--;
		    com++;
            R[i]=R[j];
		    mov++;
        while(i<j&&R[i].key>=R[0].key)       //��������ɨ����ҵ�һ���ؼ��ִ���R[0].key�ļ�¼R[i]
		{
		    i++;
		    com++;
		}

            R[j]=R[i];
			mov++;
    }
    R[i]=R[0];                               //����׼��¼��������Ӧ�źõ�λ��
    return i;                                //���ػ�׼��¼R[0]���շ��õ�λ��
}
void QuickSort(RecordType A[],int s,int t)
{
	int i,mov=0,com=0;

    for(i=1;i<10;i++)
    {
        R[i].key=A[i].key;
    }
    if(s<t)
    {
        i=Partition(R,s,t);                    //iΪ��׼��¼��λ�ý����Ϊ������
        QuickSort(R,s,i-1);                    //�Ա�R[s]~R[i-1]���п�������
        QuickSort(R,i+1,t);                    //�Ա�R[1+1]~R[t]���п�������
    }
//	printf("����������ƶ�����Ϊ%d��\n          �Ƚϴ���Ϊ%d��\n",mov,com);
}

void HeapAdjust(RecordType A[],int s,int t)       //���ڴ󶥶ѵĶ�����
{                                                 //ֻ��R[s]���е�����ʹ��Ϊ������ȫ��������Ϊһ����
    int i,j;
    RecordType R[110];
    for(i=1;i<10;i++)
    {
        R[i].key=A[i].key;
    }
    R[0]=R[s];                                    //R[a]�ݴ���R[0]
    i=s;
    for(j=2*i;j<=t;j=2*j)                         //�عؼ��ֽϴ�ĺ������µ������ȼٶ�Ϊ����
    {
        if(j<t&&R[j].key<R[j+1].key)
            j=j+1;                                //�Һ��ӹؼ��ִ������Һ������µ���
        if(R[0].key>R[j].key)                     //������ѵĶ��壬�������µ���
            break;
        R[i]=R[j];                                //���ؼ��ִ�ĺ���R[j]������˫�׽��R[i]
        i=j;                                      //��λ�ں��ӽ��������µ���
    }
    R[i]=R[0];                                    //�ҵ�����Ѷ����R[0]����λ��i����R[s]�����ڴ�
}
void HeapSort(RecordType A[],int n)
{
    int i;                                        //��N����¼���ж�����
    RecordType R[110];
    for(i=1;i<10;i++)
    {
        R[i].key=A[i].key;
    }
    for(i=n/2;i>0;i--)
        HeapAdjust(R,i,n);
        for(i=n;i>i;i--)                          //�Գ�ʼ�ѽ���n-1�˶�����
    {
        R[0]=R[1];                                //�Ѷ���R[1]��ѵ׵�R[i]���н���
        R[1]=R[i];
        R[i]=R[0];
        HeapAdjust(R,1,i-1);                       //��δ�����ǰi-1��������µ���Ϊ��
    }
	printf("��������ƶ�����Ϊ%d��\n          �Ƚϴ���Ϊ%d��\n");
}

int main()
{
    int p;
	int w=1,y=10;
    for(p=0;p<10;p++)
    {
        int i;
        RecordType R[110];
        time_t t;
        srand((unsigned) time(&t));
        printf("Hundred random numbers from 0 to 999\n\n");
       for (i=0; i<10; i++)
    {
        R[i].key=rand()%1000;
    printf("%d\t", rand()%1000);//�����
    }

    D_Insert(R,y);
    printf("main\n");
     for(i=1;i<=10;i++)
    {
        printf("%d ",R[i]);
    }
    printf("\n");
    BubbleSort(R,y);
    Partition(R,w,y);
    QuickSort(R,w,y);
	//printf("����������ƶ�����Ϊ%d��\n          �Ƚϴ���Ϊ%d��\n");
    HeapAdjust(R,w,y);
    HeapSort(R,y);
    }
 return 0;
}
