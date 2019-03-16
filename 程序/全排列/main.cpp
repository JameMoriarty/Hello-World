#include <iostream>
//例2-4
using namespace std;
void perm(char lists[],int k,int m);
int main()
{
    char lists[100];
    int k,m,n;
    cout<<"请输入要排列的元素个数：";
    cin>>n;
    k=0;
    m=n-1;
    cout<<"请输入要排列的元素：";
    for(int i=0;i<n;i++){
        cin>>lists[i];
    }
    perm(lists,k,m);
    return 0;
}
void perm(char lists[],int k,int m){
    if(k==m){
        for(int i=0;i<=m;i++){
            cout<<lists[i];
        }
        cout<<endl;
    }
    else
        for(int i=k;i<=m;i++){
                if((i!=k&&lists[k]!=lists[i])||i==k){
                    swap(lists[k],lists[i]);
                    perm(lists,k+1,m);
                    swap(lists[k],lists[i]);
                }
            }
}
