/*(7)  �Ӽ�����������ĳ��N ��ѧ���ĳɼ����������У�
�������ʾ�༶ƽ���֡�����sort ��������������������У�
������display �������ɼ��Ӹߵ��ͽ�����ʾ��
Ҫ��ʹ���Ż����ѡ�������㷨��*/

#include<stdio.h>
void display(int a[100]);
void sort(int a[],const int num);
int i,n,num;
int main()
{
    int k=0,ave,a[100];
    printf("�������ͬѧ������\n");
    scanf("%d",&n);
    printf("����ͬѧ�ĳɼ�\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        k=a[i]+k;
    }
    ave=k/n;
    printf("ƽ����Ϊ%d\n",ave);
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

