#include <iostream>
#include <string.h>
//未完成
using namespace std;
void LCSlength(int m,int n,char x[],char y[],int c[100][100],int b[100][100]);
void LCS(int i,int j,char x[],int b[100][100]);
int main()
{
    char x[100],y[100];
    int c[100][100]={0},b[100][100]={0},m,n;
    cout<<"输入第一个序列的长度："<<endl;
    cin>>m;
    cout<<"输入第一个序列:";
    for(int i=1;i<=m;i++)
    {
        cin>>x[i];
    }
    cout<<"输入第二个序列的长度："<<endl;
    cin>>n;
    cout<<"输入第二个序列:";
    for(int i=1;i<=n;i++)
    {
        cin>>y[i];
    }
    //for(int i=1;i<=n;i++)
    //{
    //    cout<<x[i];
    //}
    LCSlength(m,n,x,y,c,b);
    return 0;
}
void LCSlength(int m,int n,char x[],char y[],int c[100][100],int b[100][100])
{
    int i,j;
    for(i=1;i<=m;i++) c[i][0]=0;
    for(i=1;i<=n;i++) c[0][i]=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }

        }
    }
    /*for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    cout<<i<<" "<<j<<endl;*/
    i=m;
    j=n;
    LCS(m,n,x,b);
}
void LCS(int i,int j,char x[],int b[100][100])
{
    if(i==0||j==0) return;
    if(b[i][j]==1)
    {
        LCS(i-1,j-1,x,b);
        cout<<x[i];
    }
    else if(b[i][j]==2) LCS(i-1,j,x,b);
    else LCS(i,j-1,x,b);
}
