/* 6的半数集是{6,16,26,126,36,136} */
#include <iostream>

using namespace std;

void half(int n,int &num)
{
    if(n!=1)
    {
        for(int x=1;x<=n/2;x++)
        {
            num++;
//            cout<<"num="<<num<<endl;//          half(n,a,num);

            half(x,num);
        }
    }
}

int main()
{
    int n,num=0;
    cin>>n;
//    while(n)
//    {
        half(n,num);
        cout<<num+1<<endl;
//    }
    return 0;
}

