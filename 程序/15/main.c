#include <stdio.h>

int main()
{
    int i;
    int *p;
    p=&i;

    scanf("i��ֵ%d",&i);
    printf("i�����֣�%d\n",i);
    printf("i�ĵ�ַ��%d\n",&i);
    printf("ͨ��p:%d\n",*p);
    printf("ͨ��p:%d\n",p);
    return 0;
}
