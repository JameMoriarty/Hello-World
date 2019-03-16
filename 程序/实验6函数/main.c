/*(7)  从键盘任意输入某班N 个学生的成绩存入数组中，
算出并显示班级平均分。调用sort 函数对数组进行升序排列，
最后调用display 函数按成绩从高到低降序显示。
要求使用优化后的选择排序算法。*/

#include<stdio.h>
void display(int a[100]);
void sort(int a[],const int num);
int i,n,num;
int main()
{
    int k=0,ave,a[100];
    printf("输入班里同学的人数\n");
    scanf("%d",&n);
    printf("输入同学的成绩\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        k=a[i]+k;
    }
    ave=k/n;
    printf("平均分为%d\n",ave);
    sort(a,num);
    display(a);
    return 0;
}

void display(int a[100])
{
    for (i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
}

void sort(int a[],const int num)
{
    int i,j,d=0;
    for (i=0;i<num-1;i++)
    {
        for (j=i+1;j<num;j++)
        {
            if (a[i]>a[j])
            {
                d=a[j];
                a[j]=a[i];
                a[i]=d;
            }
        }
    }
}

