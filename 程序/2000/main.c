#include<stdio.h>
int main(void)
{
	char a,b,c,t;
	while(scanf("%c%c%c",&a,&b,&c)!=EOF) //�������ֺ�
	{
                getchar();//�˵�scanf�����Ļس� ����Ȼѭ���ڶ������롢���������
	if(a>b)t=a,a=b,b=t;//a��С��
	if(a>c)t=a,a=c,c=t;//a����С��
	if(b>c)t=b,b=c,c=t;//b���м���
	printf("%c %c %c\n",a,b,c);
	}
	system("pause");
	return 0; //�����ٸ��ֺ�
}
