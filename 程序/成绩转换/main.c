#include<stdio.h>

int day[20]={0,31,0,31,30,31,30,31,31,30,31,30,31};

//char str[50]="0123456789ABCDEFGHIJKLMN";
int main()
{
    int y,m,d,i;
    while (scanf("%d/%d/%d",&y,&m,&d)!=EOF)
    {
        int ans=0;
        if (y%4!=0)
        {
            day[2]=28;
        }
        else
        {
            if(y%100==0)
            {
                if(y%400==0)    day[2]=29;
                else            day[2]=28;
            }
            else
            {
                day[2]=29;
            }
        }
        for (i=1;i<=m-1;i++)
        {
            ans+=day[i];
        }
        ans=ans+d;
        printf("%d\n",ans);

    }
    return 0;
}
