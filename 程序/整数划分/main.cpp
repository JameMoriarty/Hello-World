#include <iostream>
//��2-4
using namespace std;

int q(int n,int m);

int main()
{
    cout<<"����Ҫ���ֵ�����n��������������m��";
    int n,m,ans;
    cin>>n>>m;
    ans=q(n,m);
    cout<<"��ͬ���ָ���Ϊ"<<ans<<endl;
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
