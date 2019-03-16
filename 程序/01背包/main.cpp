#include <iostream>

using namespace std;
int cb=0,nb=0,v[50],m[100][100],w[50],x[100];
void Kinapsack(int v[],int w[],int c,int n,int m[100][100])
{
    int jMax=min(w[n]-1,c);
    for(int j=0;j<jMax;j++) m[n][j]=0;
    for(int j=w[n];j<=c;j++) m[n][j]=v[n];
    for(int i=n-1;i>1;i--)
    {
        jMax=min(w[i]-1,c);
        for(int j=0;j<=jMax;j++) m[i][j]=m[i+1][j];
        for(int j=w[i];j<=c;j--) m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
    }
    m[1][c]=m[2][c];
    if(c>=w[1]) m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}

void Traceback(int m[100][100],int w[],int c,int n,int x[])
{
    for(int i=1;i<n;i++)
        if(m[i][c]==m[i+1][c]) x[i]=0;
        else {x[i]=1;c-=w[i];}
        x[n]=(m[n][c])?1:0;
}

int main()
{

    cout<<"请输入背包的总容量："<<endl;
    cin>>cb;
    cout<<"请输入物品个数："<<endl;
    cin>>nb;
    cout<<"请输入物品的重量和价值："<<endl;
    for(int i=1;i<=nb;i++)
    {
        cin>>w[i]>>v[i];
    }
    Kinapsack(v,w,cb,nb,m);
    cout<<"背包的最大价值是："<<m[1][cb]<<endl;
    Traceback(m,w,cb,nb,x);
    cout<<"最优装法："<<endl;
    for(int i=1;i<=nb;i++)
    {
        if(x[i]==1)
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
