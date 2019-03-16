#include <iostream>

using namespace std;
class StoneNum{
public:
    int mmax;
    int mmin;
    int does;
};
void Stone(int n,int x[],StoneNum m[100][100]);
int main()
{
    int n,x[100];
    StoneNum m[100][100];
    cout<<"输入石子堆数量：";
    cin>>n;
    cout<<"输入每堆石子数："<<endl;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    Stone(n,x,m);
    cout<<"小"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<m[i][j].mmin<<" ";
        cout<<endl;
    }
    cout<<"最小得分："<<m[1][n].mmin<<endl;
    cout<<"大"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<m[i][j].mmax<<" ";
        cout<<endl;
    }
    cout<<"最大得分："<<m[1][n].mmax<<endl;
    return 0;
}

void Stone(int n,int x[],StoneNum m[100][100])
{
    for(int i=1;i<=n;i++){
            m[i][i].mmin=0;
            m[i][i].mmax=0;
    }

    for(int i=1;i<n;i++){
            m[i][i+1].mmin=x[i]+x[i+1];
            m[i][i+1].mmax=x[i]+x[i+1];
    }

    for(int r=3;r<=n;r++)
        for(int i=1;i<=n-r+1;i++){
                int j=i+r-1;
                int sum=0;
                for(int k=i;k<=j;k++)
                    sum+=x[k];
                cout<<"sum1="<<sum<<endl;
                m[i][j].mmin=m[i+1][j].mmin+sum;
                m[i][j].mmax=m[i+1][j].mmax+sum;
                int t=0,t1=0;
                for(int k=i+1;k<j;k++){
                    t=m[i][k].mmin+m[k+1][j].mmin+sum;
                    t1=m[i][k].mmax+m[k+1][j].mmax+sum;
                    if(t<m[i][j].mmin)
                        m[i][j].mmin=t;
                    if(t1>m[i][j].mmax)
                        m[i][j].mmax=t1;

                }
            }

}
