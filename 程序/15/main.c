#include <stdio.h>

int main()
{
    int i;
    int *p;
    p=&i;

    scanf("i的值%d",&i);
    printf("i的数字：%d\n",i);
    printf("i的地址：%d\n",&i);
    printf("通过p:%d\n",*p);
    printf("通过p:%d\n",p);
    return 0;
}
