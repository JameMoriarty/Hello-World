#include <stdio.h>                     //直接，冒泡已好
#include <stdlib.h>
#include <time.h>
#define MAXNUM 1000
typedef struct
{
    int key;
}RecordType;

void D_Insert(RecordType RT[],int n)     //直接插入排序
{                                       //对n个记录直接插入排序
    int i,j,mov=0,com=0;
	RecordType R[110];
	for(i=0;i<100;i++)
	{
		R[i].key=RT[i].key;
	}
    for(i=1;i<n;i++)                   //进行n-1次排序
        if(R[i].key<R[i-1].key)
    {
        R[101]=R[i];                      //设置查找监视哨并保存待插入记录R[i]的值
        j=i-1;
        while(R[j].key>R[101].key)
        {                              //将关键字值大于R[i].key的所有R顺序后移一个记录位置
            R[j+1]=R[j];
            j--;
			mov++;
			com=mov;
        }
        R[j+1]=R[101];                     //插入值
    }
		printf("直接插入排序的移动次数为%d次\n              比较次数为%d次\n",mov,com);
}

void BubbleSort(RecordType R[],int n)         //冒泡排序
{                                             //对n个记录进行冒泡排序
    int i,j,swap,mov=0,com=0;
    for(i=1;i<n;i++)                          //进行n-1趟排序
    {
        swap=0;                               //设置未交换标志
        for(j=0;j<n-i;j++)                   //数据两两比较
        {    com++;
			if(R[j].key>R[j+1].key)           //大于则交换
        {
            R[101]=R[j];
            R[j]=R[j+1];
            R[j+1]=R[101];
            swap=1;                           //有交换发生
            mov++;
        }}
        if(swap==0)
            break;                            //未出现交换则排序结束
    }
	printf("冒泡排序的移动次数为%d次\n          比较次数为%d次\n",mov,com);
	//for(j=0;j<n;j++){printf("%d\t",R[j].key);}
}

int Partition(RecordType R[],int i,int j)   //划分算法
{                                           //对R[i]~R[j],以R[i]为基准记录进行划分，并返回R[i]在划分后的正确位置
    R[101]=R[i];                              //暂存基准记录
    while(i<j)                              //从表两端交替向中间进行扫描
    {
        while(i<j&&R[j].key>=R[101].key)       //从右向左扫描查找第一个关键字小于R[0].key的记录
            j--;
        if(i<j)                              //当i<j时，则R[i].key小于R[0].key,将R[j]交换到左边
        {
            R[i]=R[j];
            i++;
        }
        while(i<j&&R[i].key<=R[101].key)       //从左向右扫描查找第一个关键字大于R[0].key的记录R[i]
            i++;
        if(i<j)                              //当i<j时，则R[i].key大于R[0].key的值，交换至表的右边
        {
            R[j]=R[i];
            j--;
        }
    }
    R[i]=R[101];                               //将基准记录送入最终应放好的位置
	return i;                                //返回基准记录R[0]最终放置的位置
}
void QuickSort(RecordType R[],int s,int t)
{
    int i;
    if(s<t)
    {
        i=Partition(R,s,t);                    //i为基准记录的位置将表分为两部分
        QuickSort(R,s,i-1);                    //对表R[s]~R[i-1]进行快速排序
        QuickSort(R,i+1,t);                    //对表R[i+1]~R[t]进行快速排序
    }
	//for(i=0;i<t;i++){printf("%d\t",R[i].key);}
	//printf("快速排序的移动次数为%d次\n          比较次数为%d次\n");
}

void HeapAdjust(RecordType R[],int s,int t,int *mov,int *com)       //基于大顶堆的堆排序
{                                                 //只对R[s]进行调整，使其为根的完全二叉树成为一个堆

    int i,j,com1=0,mov1=0;
    R[101]=R[s];                                    //R[a]暂存于R[0]
    i=s;
    for(j=2*i;j<=t;j=2*j)                         //沿关键字较大的孩子向下调整，先假定为左孩子
    {
//        com1++;
        if(j<t&&R[j].key<R[j+1].key)
        {j=j+1;com1++;}                                //右孩子关键字大，则沿右孩子向下调整
        if(R[101].key>R[j].key)                     //已满足堆的定义，不再向下调整
           {com1++; break;}
        R[i]=R[j]; mov1++;                               //将关键字大的孩子R[j]调整至双亲结点R[i]
        i=j;                                      //定位于孩子结点继续向下调整
    }
    R[i]=R[101];                                  //找到满足堆定义的R[0]放置位置i，将R[s]调整于此
    *com+=com1;
    *mov+=mov1;
}
void HeapSort(RecordType R[],int n)
{
    int i,mov=0,com=0;                                        //对N个记录进行堆排序
    for(i=n/2;i>0;i--)
        HeapAdjust(R,i,n,&mov,&com);
        for(i=n;i>1;i--)                          //对初始堆进行n-1趟堆排序
    {
        R[101]=R[1];                                //堆顶的R[1]与堆底的R[i]进行交换
        R[1]=R[i];
        R[i]=R[101];
        HeapAdjust(R,1,i-1,&mov,&com);                       //将未排序的前i-1个结点重新调整为堆
    }
		printf("堆排序的移动次数为%d次\n          比较次数为%d次\n",mov,com);
	//	for(i=0;i<n;i++){printf("%d\t",R[i].key);}
}
/*void HeapAdjust(int *R,int s,int t)       //基于大顶堆的堆排序
{                                                 //只对R[s]进行调整，使其为根的完全二叉树成为一个堆

   int p=R[s];                                    //R[a]暂存于R[0]
    int i=2*s+1;
	while(i<=t)
                             //沿关键字较大的孩子向下调整，先假定为左孩子
    {
        if(i+1<=t&&R[i]<R[i+1])
            i++;                                //右孩子关键字大，则沿右孩子向下调整
        if(R[i]<=p)                     //已满足堆的定义，不再向下调整
            break;
        R[s]=R[i];                                //将关键字大的孩子R[j]调整至双亲结点R[i]
        s=i;
		i=2*s+1;//定位于孩子结点继续向下调整
    }
    R[s]=p;                                    //找到满足堆定义的R[0]放置位置i，将R[s]调整于此
}
void HeapSort(int *R,int n)
{
    int i;                                        //对N个记录进行堆排序
    for(i=n/2-1;i>=0;i--)
        HeapAdjust(R,i,n-1);
        for(i=n-1;i>0;i--)                          //对初始堆进行n-1趟堆排序
    {
       int p=R[i];                                //堆顶的R[1]与堆底的R[i]进行交换
        R[i]=R[0];
        R[0]=p;
        HeapAdjust(R,0,i-1);                       //将未排序的前i-1个结点重新调整为堆
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
	while(p--)                                //对十组随机生成数进行排序测试
    {
		for(i=0;i<10;i++)
		{
    printf("Hundred random numbers from 0 to 999\n\n");
    for (i=0; i<100; i++)
    {
        R[i].key=rand()%1000;
    printf("%d\t", R[i].key);              //生成随机数
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
