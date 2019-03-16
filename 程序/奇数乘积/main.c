#include<stdio.h>
int main()
{
    int a=0,i=0,n=0;
    while (scanf("%d",&n)!=EOF)
    {
        int ans=1;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a);
            if (a&1)
            {
                ans*=a;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
