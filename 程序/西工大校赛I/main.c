#include <stdio.h>
#include <stdlib.h>
struct temp
{
    char b[30];
    int k[30];
};

int main()
{
    struct temp te;
    char a[30][30];
    int i=0,j=0,num,t,q,s=0,o;
    for (i=0;i<26;i++)
    {
        te.b[i]='A'+i;
    }
    scanf("%d",&t);
    for (q=1;q<=t;q++)
    {
  //      while (a[i][j]!='\n')
  //      {

          while (a[i][j]!='\n')
          {

            scanf("%c ",&a[i][j]);
            j++;
          }num=j;
    //       i++;
    //    }
    for (i=0;i<num;i++)
    {
        for (j=0;j<num;j++)
        {
            scanf("%c ",&a[i][j]);

        }
    }


        for (j=0;j<num;j++)
        {
            for (i=0;i<num;i++)
            {
                if (a[i][j]=='#')
                    s++;
                    else
                        break;
            }
            te.k[j]=s;
        }
        printf("Case #%d:\n",q);
        printf("%d\n",num);
        for (i=0;i<num;i++)
        {
            if (te.k[i]<te.k[i+1])
            {
                o=te.k[i];
                te.k[i]=te.k[i+1];
                te.k[i+1]=o;

            }

        }
        for (i=0;i<num;i++)

        {
            printf("%c %d\n",te.b[i],te.k[i]);
        }



    }
    return 0;
}
