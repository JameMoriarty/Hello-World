/*
#include <stdio.h>
#include <string.h>
char a[1000005],d[1000005];
int main ()
{
	int n,i,x=0,j,p=0,k=0,mark;

	scanf("%d\n",&n);
/////////////////////////


///////////////////////////////		///////////////////////////
	for (i=0;i<n;i++)
	{
		gets(a);
		p=0;
		x=0;
		mark=0;
		x=strlen(a);
		d[1000005]='1';
		k=0;
		for (j=x;j>=0;j--)
		{
			if (a[j]>='a'&&a[j]<='z')
			{

				d[k]=a[j]-32;
				k++;
			}
			else if (a[j]>='A'&&a[j]<='Z')
			{
				d[k]=a[j]+32;
				k++;
			}
			else
			{
			//	d[j]='1';

			//	p++;
			//	k++;
			//	for (k=j;k<=x-1;k++)
			//	{
			//		d[k]=d[k+1];
			//
			//	}
			//	d[j]=d[j+k];



			}
		}
	//	printf("%d\n",k);
     //	int k=0;
	//	for (j=x-1;j>=0;j--)
	//	{
	//		if (d[j]=='1')
	//		{
	//			for (k=j;k<x;k++)
	//			{
	//				d[k]=d[k+1];
	//			}
	//		}
	//	}
		for (j=k-1;j>=0;j--)
		{
			printf("%c",d[j]);
		}
		printf("\n");

	}
	return 0;
}
*/


/*
#include <stdio.h>
#include <string.h>
char a[1000000000];
int main()
{
	int t,i;
	scanf("%d\n",&t);
	for (i=0;i<t;i++)
	{
		int n;
	//	getchar ();
		gets(a);
		n=strlen(a);
		printf("%c %d",a[n-1],n);
		if (a[n-1]%2==1)
		{
			printf("Yes\n");
		}
		else
			printf("No\n");
	}

	return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
       int n=0,m=0,q=0,p=0;
	   char a[100];
	   scanf(" Week%d %s",&n,a);
	//	gets(a);
		if (strcmp(a,"Monday")==0)
			m=0;
		else if (strcmp(a,"Tuesday")==0)
			m=1;
		else if (strcmp(a,"Wednesday")==0)
			m=2;
		else if (strcmp(a,"Thursday")==0)
			m=3;
		else if (strcmp(a,"Friday")==0)
			m=4;
		else if (strcmp(a,"Saturday")==0)
			m=5;
		else if (strcmp(a,"Sunday")==0)
			m=6;
        p=((n-1)*7+m);
		q=p%6;
		printf("%c sir\n",'A'+q);
	//	if (q==1)
	//		printf("A sir\n");
	//	else if (q==2)
	//		printf("B sir\n");
	//	else if (q==3)
	//		printf("C sir\n");
	//	else if (q==4)
	//		printf("D sir\n");
	//	else if (q==5)
	//		printf("E sir\n");
	//	else if (q==6)
	//		printf("F sir\n");

	}
	return 0;

}
*/

#include <stdio.h>
#include <string.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    for (i=0;i<t;i++)
    {
        int n,m[100],j;
        scanf ("%d",&n);
        for (j=0;j<n;j++)
        {
            scanf("%d",&m[j]);
        }
        //先取最大的，再判断剩下的和能否等于他，
        //不能则取第二大的。
    }
}
