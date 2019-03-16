#include<stdio.h>
int main(void)
{
	char a,b,c,t;
	while(scanf("%c%c%c",&a,&b,&c)!=EOF) //这里多个分号
	{
                getchar();//滤掉scanf的最后的回车 ，不然循环第二次输入、输出不正常
	if(a>b)t=a,a=b,b=t;//a是小的
	if(a>c)t=a,a=c,c=t;//a是最小的
	if(b>c)t=b,b=c,c=t;//b是中间数
	printf("%c %c %c\n",a,b,c);
	}
	system("pause");
	return 0; //这里少个分号
}
