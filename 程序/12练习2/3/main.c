#include <stdio.h>
#include <string.h>
#include <math.h>
//int num[6405],addr[6405][4];
//int min(int numb);
int main()
{
    int n,m,b[805][805],numb=0,k,num[6405],addr[6405][4];
    while (scanf("%d%d",&n,&m)==2)
    {
        fflush(stdin);
        char a[805][805];
        int i,j;   //,addr[6405][4];
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                scanf("%c",&a[i][j]);
            }
            fflush(stdin);
        }
       // int b[805][805],numb=0,k;
    /*    for (i=0;i<n;i++)
        {
            k=0;
            for (j=0;j<m;j++)
            {
                if (a[i][j]=='0')
                {
                    b[i][j]=0;
                //    addr[k][1]=i;
                //    addr[k][2]=j;
                //    numb++;
                //    k++;
                }

                else
                    b[i][j]=1;
            }
        }
        */
    /*    for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                //if (b[i][j]!=0)
                //{
                    for (k=0;k<numb;k++)
                    {
                        num[k]=abs(i-addr[k][1])+abs(j-addr[k][2]);
                    }
                    b[i][j]=min(numb);
                //}
            }
        }   */
        /////////////
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                printf("%c ",a[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
/*
int min(int numb)
{
    int i,j,k=0;
    for (i=0;i<numb-1;i++)
    {
        for (j=i+1;j<numb;j++)
        {
            if (num[i]>num[j])
            {
                k=num[i];
                num[i]=num[j];
                num[j]=k;
            }

        }
    }
    return num[0];
}

*/
