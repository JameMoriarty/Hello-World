#include <cstdio>

using namespace std;

bool check(int a,int b)
{
    int cnt=0;
    for(int i=1;i<=a>>1;i++)
    {
        if(a%i==0)  cnt+=i;
    }
    if(cnt==b)  return 1;
    else        return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(check(a,b)&&check(b,a))  printf("YES\n");
        else                        printf("NO\n");
    }
    return 0;
}
