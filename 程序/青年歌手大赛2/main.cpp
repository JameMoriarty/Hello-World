#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n=0;
    double a[150];
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%lf",&a[i]);
        }
        sort (a,a+1);
        double sum=0;
        for (int i=2;i<=n-1;i++)
        {
            sum+=a[i];
        }
        sum=sum/(n-2);
        printf("%.2lf\n",sum);
     //   cout << "%,2lf\n",sum << endl;

    }

    return 0;
}
