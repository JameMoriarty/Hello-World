//求A和B的编辑距离
//字符串比较，判断位置不同的地方。
//
#include <iostream>
#include <string.h>
using namespace std;
char A[100],B[100];
void distance(char A[],char B[],int d[100][100])
{
    int flag=-1;
    for(int i=0;i<=strlen(A);i++)
    {
        d[i][0]=i;
    }
    for(int j=0;j<=strlen(B);j++)
    {
        d[0][j]=j;
    }
    for(int i=1;i<=strlen(A);i++)
    {
        for(int j=1;j<=strlen(B);j++)
        {
                if(A[i]!=B[j])
                {
                    flag=1;
                }
                else
                    flag=0;
                int s1=d[i-1][j]+1;
                int s2=d[i][j-1]+1;
                int s3=d[i-1][j-1]+flag;
                d[i][j]=min(min(s1,s2),s3);
        }
    }
    cout<<d[strlen(A)][strlen(B)];
}
int main()
{
    int d[100][100];  //最短编辑距离
    cout << "输入字符串A：" << endl;
    cin>>A;
    cout<<"输入字符串B："<<endl;
    cin>>B;
    distance(A,B,d);
//    cout<<d[strlen(A)][strlen(B)];
    return 0;
}
