#include <iostream>

using namespace std;
void Knapasck(int w[],int v[],int c,int n,int m[100][100]);
void Traceback(int m[100][100],int w[],int c,int n,int x[100]);
int main()
{
    int m[100][100],n,c,w[100],v[100],x[100],vmax=0;
    cout<<"输入背包容量，物品个数："<<endl;
    cin>>c>>n;
    cout<<"物品的重量："<<endl;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    cout<<"物品的价值："<<endl;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    Knapasck(w,v,c,n,m);
    Traceback(m,w,c,n,x);

    for(int i=1;i<=n;i++)
    {
        if(x[i]==1)
            vmax+=v[i];
    }
    cout<<"最大价值:"<<m[1][c]<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++)
            cout<<m[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}
void Knapasck(int w[],int v[],int c,int n,int m[100][100])
{
    int jMax=min(w[n],c);
    for(int j=1;j<=jMax;j++)
        m[n][j]=0;
    for(int j=w[n];j<=c;j++)
        m[n][j]=v[n];
    for(int i=n-1;i>=1;i--){
        jMax=min(w[i],c);
        for(int j=1;j<=jMax;j++)
            m[i][j]=m[i+1][j];
        for(int j=w[i];j<=c;j++)
            m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
    }
    if(c>=w[1])
        m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}
void Traceback(int m[100][100],int w[],int c,int n,int x[100])
{
    for(int i=1;i<n;i++)
        if(m[i][c]==m[i+1][c])
            x[i]=0;
        else {
            x[i]=1;
            c-=w[i];
        }
        x[n]=m[n][c]?1:0;
}
