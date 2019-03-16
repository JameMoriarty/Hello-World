#include<stdio.h>
#include<math.h>
#define PI 3.1415927
int main()
{
    double r=0,v=0;
    while (scanf("%lf",&r)!=EOF)
    {
        v=(4.0/3.0)*PI*pow(r,3);
        printf("%0.3lf\n",v);
    }
    return 0;
}
