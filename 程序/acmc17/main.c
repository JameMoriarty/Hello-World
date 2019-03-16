#include <stdio.h>
#include <stdlib.h>
struct caoyao
{
    int a;
    int b;
}cy[150];
int main()
{
    int t=0,m=0;
    scanf("%d%d",&t,&m);
    int i=0;
    for (i=0;i<m;i++)
    {
        scanf("%d%d",&cy[i].a,&cy[i].b);
    }
    struct caoyao k;
    for (i=0;i<m;i++)
    {
        if (cy[i].a<cy[i+1].a)
        {
           k=cy[i];
           cy[i]=cy[i+1];
           cy[i+1]=k;
        }
    }
    int j=0;
    for (i=0;i>m;i++)
    {
        if (cy[i].a>t)
        {
            j++;
        }

    }
    for (i=j;i<m;i++)
    {
        if (cy[i].b<cy[i+1].b)
        {
           k=cy[i];
           cy[i]=cy[i+1];
           cy[i+1]=k;
        }
    }
    int q=0,s[150][150];
    for (i=j;i<=m;i++)
    {
        for (q=i+1;q<=m;q++)
        {
            if (cy[i].a==t)
            {
                s[i][q]=cy[i].b;
            }
            else if (cy[i].a+cy[q].a==t)
            {
                s[i][q]=cy[i].b+cy[q].b;
            }
            else if (cy[i].a+cy[q].a<t)
            {
                cy[i+1].a=cy[i].a+cy[q].a;
                cy[i+1].b=cy[i].b+cy[q].b;
            }
            else if (cy[i].a<t&&cy[i].a+cy[q].a>t)
            {
                s[i][q]=cy[i].b;
            }
        }
    }
    int d=0;
    for (i=j;i<=m;i++)
    {
        for (q=0;q<=m;q++)
        {
        if (s[i][q]<s[i][q+1])
        {
           d=s[i][q];
           s[i][q]=s[i][q+1];
           s[i][q+1]=d;
        }
        }
    }
    for (i=0;i<=m;i++)
    {
        if (s[i][0]<s[i+1][0])
        {
            d=s[i][0];
           s[i][0]=s[i+1][0];
           s[i+1][0]=d;
        }

    }
    printf("%d",s[j][0]);
    return 0;
}

