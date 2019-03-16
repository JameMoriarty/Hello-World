#include<stdio.h>
#include<string.h>
char s1[1000],s2[1000];
int min(int a,int b,int c)
{
    int tmp=a<b?a:b;
    return tmp<c?tmp:c;
}
void editDistance(int len1,int len2)
{
    int **d=new int*[len1+1];
    for(int i=0;i<=len1;i++)
        d[i]=new int[len2+1];
    int i,j;
    for(i=0;i<=len1;i++)
        d[i][0]=i;
    for(j=0;j<=len2;j++)
        d[0][j]=j;
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            int cost=s1[i]==s2[j]?0:1;
            int deletion=d[i-1][j]+1;
            int insertion=d[i][j-1]+1;
            int substitution=d[i-1][j-1]+cost;
            d[i][j]=min(deletion,insertion,substitution);
        }
    }
    printf("¾àÀëÎª:%d\n",d[len1][len2]);
    for(int i=0;i<=len1;i++)
    {
        delete[] d[i];
    }
    delete[] d;
}

int main()
{
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        editDistance(strlen(s1),strlen(s2));
    }
}
