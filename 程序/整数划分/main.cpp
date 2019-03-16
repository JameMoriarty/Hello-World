#include <iostream>
//例2-4
using namespace std;

int q(int n,int m);

int main()
{
    cout<<"输入要划分的整数n，最大加数不大于m。";
    int n,m,ans;
    cin>>n>>m;
    ans=q(n,m);
    cout<<"不同划分个数为"<<ans<<endl;
	return 0;
}
int q(int n,int m)
{
    if(n<1||m<1) return 0;
    if(n==1||m==1) return 1;
    if(n<m) return q(n,n);
    if(n==m) return q(n,m-1)+1;
    return q(n,m-1)+q(n-m,m);
}
