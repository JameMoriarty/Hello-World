#include <iostream>
#include <string.h>
using namespace std;

void Swap(char & a,char & b)
{
        char temp=a;
        a=b;
        b=temp;
}

int isSwap(char list[],int k,int m)
{
    int mark = 1;
    for(int i=m;i>k;i--)
    {
        if(list[m]==list[i-1])
        {
            mark = 0;
            return mark;
        }
    }
    return mark;
}

void Perm(char list[],int k,int m)
{
    if(k==m)
    {
        for(int i=0;i<=m;i++) cout<<list[i];
        cout<<endl;
    }
    else
        for(int i=k;i<=m;i++)
        {
            if(isSwap(list,k,i)!=0)
            {
//                cout<<"**0**"<<k<<" "<<i<<endl;
                Swap(list[k],list[i]);
                Perm(list,k+1,m);
                Swap(list[k],list[i]);
            }
        }
}

int main()
{
    char list[100];
    cin>>list;
    int k=0,m;
    m=strlen(list);
    cout<<"È«ÅÅÁĞÎª£º"<<endl;
    Perm(list,k,m-1);
    return 0;
}
