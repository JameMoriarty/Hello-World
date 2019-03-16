#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 3
struct people
{
char name[20];
char sex;//M or F
int year;
}peo[N];

void input()
{
    int i;
for(i=0;i<N;i++)
{
scanf("%s %c%d",peo[i].name,&peo[i].sex,&peo[i].year);
}
}

void sort(struct people *p,int n)
{
struct people tmp;
int i,j;
for(i=0;i<N;i++)
{
for(j=i+1;j<N;j++)
{
if(strcmp(p[i].name,p[j].name)>0)
{
tmp=p[i];
p[i]=p[j];
p[j]=tmp;
}
}
}
}

void output()
{
    int i;
for(i=0;i<N;i++)
{
printf("%s %c %d",peo[i].name,peo[i].sex,peo[i].year);
printf("\n");
}
}
int main()
{
printf("please input the data:\n");
input();
sort(peo,N);
printf("after sort:\n");
output();
return 0;
}
