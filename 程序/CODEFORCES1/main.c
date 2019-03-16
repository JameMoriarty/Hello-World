#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,a[200001],b[200001];
    scanf ("%d",&n);
    int i=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    int ans=0,k=0;
    for (i=1;i<=n;i++)
    {
        int j=a[i];
        if (a[i]==i||a[j]==i)
            ans++;
            if (b[i]==0)
                k++;
    }
    ans=ans/2;
    if (k==n)
        ans=ans+1;
    printf("%d\n",ans);

  return 0;
}
