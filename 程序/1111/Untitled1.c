#include<stdio.h>
int zhengfu(int n);
int n;
int main()
{
    printf("input a number:\n");
    scanf("%d",&n);
    zhengfu(n);
    return 0;

}
int zhengfu(int n)
{
    if (n<0)
        printf("negative");
    else if (n==0)
        printf("zero");
    else
        printf("positive");
    return n;
}
