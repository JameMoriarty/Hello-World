#include <iostream>
#include <algorithm>
using namespace std;
void MatrixChain(int p[100][100],int m[100][100],int n,int k,int s);
void Traceback(int f,int b,int s[100][100]);
int main()
{
    int n,p[100][100]={0},m[100][100]={0},k,s;
    cout<<"几个矩阵连乘："<<endl;
    cin>>n;
    cout << "输入每个矩阵的行数和列数:" << endl;
    for(int i=1;i<=n;i++)        //p[i][0]第i个矩阵的行数，p[i][1]第i个矩阵的列数；
        cin>>p[i][0]>>p[i][1];
    cout<<"求第几个矩阵乘到第几个矩阵："<<endl;
    cin>>k>>s;
    //for(int i=1;i<=n;i++)
    //    cout<<p[i][0]<<" "<<p[i][1]<<endl;
    MatrixChain(p,m,n,k,s);
    return 0;
}
void MatrixChain(int p[100][100],int m[100][100],int n,int k,int s)
{
    int mark[100][100]={0};          //记录每个矩阵的前一个矩阵
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int i=n-1;i>=1;i--)
        for(int j=i-1;j<=n;j++){
            int a[100]={0},num=0,a1[100];
            for(int z=i;z<=j-1;z++)
             {
                 a[num]=m[i][z]+m[z+1][j]+p[i][0]*p[z][1]*p[j][1];
                 a1[z]=a[num];
                 num++;
             }
             sort(a,a+num);
             int v=0;
             for(v=i;v<=j-1;v++)
                if(a1[v]==a[0])
                    break;
             mark[i][j]=v;
             //cout<<"gh:";
             //for(int gh=0;gh<num;gh++)
             //   cout<<a[gh]<<" ";
            //cout<<endl;
            m[i][j]=a[0];

        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<"结果为"<<m[k][s]<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=i)
                mark[i][j]=0;
            cout<<mark[i][j];
        }
        cout<<endl;
    }
    Traceback(k,s,mark);
}

void Traceback(int f,int b,int s[100][100])
{
    if(f==b) return ;
    Traceback(f,s[f][b],s);
    Traceback(s[f][b]+1,b,s);
    cout<<"Multiply A"<<f<<","<<s[f][b];
    cout<<"and A"<<(s[f][b]+1)<<","<<b<<endl;
}
