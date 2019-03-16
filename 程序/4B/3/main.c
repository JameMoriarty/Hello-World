#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void check(char a[],char b[],int m,int mid,int l);
int main()
{
    char a[200001],b[200001];
    int c[200001],i=0;
  //  while (a[0]!='\n')
  //  {
        gets(a);
        i=strlen(a);
   //     int j=0;
        gets(b);
   //     j=strlen(b);
        int k=0;
        for (k=0;k<i;k++)
        {
            scanf("%d",&c[k]);
        }
        int l=0,m=0,mid =0;
        l=0;
        m=strlen(a);
        mid =(l+m)/2;
        //////////////
        check(a,b,m,mid,l);

  //  }
 //   for (i=1;i<=n;i++)
 //   printf("%c",a[i]);
    return 0;
}

void check(char a[],char b[],int m,int mid,int l)
{
    int i1=0,j1=0;
            for (i1=0;i1<mid;i1++)
            {
                a[i1]=0;
            }
            int mark=0,h=0;
  /*          for (j1=0;j1<strlen(b);j1++)
            {
                for (i1=h;i1<mid;i1++)
                {
                    if (b[j1]==a[i1])
                       {
                          mark++;
                          h=i1;
                       }
                }
            }

            printf("mark %d\n",mark);
            */
      //      if (mark>=strlen(b))
            if (strstr(a,b))
            {
                mid=(mid+m)/2;
                check(a,b,m,mid,l);
           //     printf("try 1 : %d\n",mid);

            }
       //     else if (mark<strlen(b))
       //     {
            else
            {
                mid =(mid)/2;
                check(a,b,m,mid,l);
       //         printf("%d\n",mid+1);
            }
             printf("%d\n",mid+1);


}
