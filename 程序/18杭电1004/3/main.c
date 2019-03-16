#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    while (scanf("%d",&t)==1)
    {
        int i,j,a1[1005],b1[1005],max=1,c[2000]={0},k;
        char a[1005],b[1005];
        for (k=0;k<=10;k++)
        {
             printf("%d",c[k]);
        }

        fflush(stdin);
     /*   while (1)
        {
            scanf("%c",&a[i]);
            if (a[i]==' ')
                break;
            i++;
        }   */
        gets(a);
      //  getc(c);
      //  printf("10\n");
       // fflush(stdin);
        gets(b);
      //  printf("10\n");
        for (i=0;i<strlen(a);i++)
        {
            a1[i]=a[i]-48;
        }
     //   printf("10\n");
      //  getchar();
       // gets(b);
       if (strlen(a)>strlen(b))
        max=strlen(a);
       else
        max=strlen(b);
        for (i=strlen(a)-1,j=strlen(b),k=0;i>=0,j>=0,k<=max;i--,j--,k++)
        {
            if (a1[i]+b1[i]<10)
            {

                c[k]=c[k]+a1[i]+b1[j];
            }
            else
            {
                c[k]=c[k]+(a1[i]+b1[j])%10;
                c[k+1]=1;
            }
        }

        for (j=0;j<strlen(b);j++)
        {
            b1[j]=b[j]-48;
        }
        for (i=0;i<strlen(a);i++)
        {
            printf("%d",a1[i]);
        }
        printf(" + ");
        for (j=0;j<strlen(b);j++)
        {
            printf("%d",b1[j]);
        }
        printf(" = ");
        for (k=max-1;k>=0;k--)
        {
            printf("%d",c[k]);
        }
        printf("\n");

    }
    return 0;
}
