/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100005],b;
    int n=0,k=0;
    while (scanf("%d %d",&n,&k)==2)
    {
        int i=0,j=0,mark=0,numa=0,numb=0;
        getchar( );
        for (i=0;i<n;i++)
        {
            scanf("%c",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            if (a[i]=='a')
                numa++;
            else
                numb++;
        }
        if (numa>numb)
            b='a';
        else
            b='b';
        for (j=0;j<k;j++)
        {
            for (i=mark;i<n;i++)
            {
                if (a[i]!=b&&(a[i+1]==b||a[i+1]=='\0'||a[i-1]==b||a+i-1!=NULL))
                {
                    a[i]=b;
                    mark=i;
                    break;
                }
            }
        }
        //////////
        for (i=0;i<n;i++)
        {
            printf("%c",a[i]);
        }
        printf("\n");
        //////////////
        j=0;
        for (i=0;i<n;i++)
        {
            if (a[i]==b)
                j++;
            if (a[i+1]!=b)
                break;
            else
                j=j+0;

        }
        printf("%d\n",j);
    }
    return 0;
}
*/


#include <stdio.h>
#include <string.h>
int main ()
{
    char a[100005],b;
    int n,k;
    while (scanf("%d %d",&n,&k)==2)
    {
        int i,j,addra[100005],addrb[100005],numa[100005]={0},numb[100005]={0},*p;
        for (i=0;i<n;i++)
        {
            scanf("%c",&a[i]);
        }
        addra[0]=a;
        addrb[0]=a;
        for (j=1;j<n;j++)
        {
            for (i=0;i<n;i++)
            {
                if (a[i]=='a')
                    numa[j]++;
                else
                    break;
            }
            addra[j]+=numa[j];
            for (i=0;i<n;i++)
            {
                if (a[i]=='b')
                    numb[j]++;
                else
                    break;
            }
            addrb[j]+=numb[j];
        }
        ////////////
        max(numa);和max(numb);比大小
        将最大的前一个指针和后面的指针写出来，
        然后在最大的和同种值的第二大的之间改字母。


    }
    return 0;
}

