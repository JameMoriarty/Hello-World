#include<math.h>
#include<stdio.h>
int main()
{
    double x1=0,x2=0,y1=0,y2=0,s=0;
    while (scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
    {
        s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        printf("%0.2lf\n",s);
    }
    return 0;
}
