#include <iostream>

using namespace std;
void MargeSort(int a[],int n);
void Marge(int c[],int d[],int l,int m,int r);
void MargePess(int x[],int y[],int s,int n);
//void Copys(int a[],int d[],int left,int right);
//int d[100]={0};
int main()
{
    int a[100],left,right,i=0,num=0;
    cout<<"输入要排序的数字个数："<<endl;
    cin>>num;
    cout<<"输入要排序的数字："<<endl;
    while(i<num){
        cin>>a[i];
        i++;
    }
    //left=1;
    //right=i;
    //num=8;
    MargeSort(a,num);  //最后合并给了a
    for(int j=0;j<num;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}
void Marge(int c[],int d[],int l,int m,int r){
    int i=l,j=m+1,k=l;
    while((i<=m)&&(j<=r))
        if(c[i]<=c[j]) d[k++]=c[i++];
        else d[k++]=c[j++];
    if(i>m) for(int q=j;q<=r;q++) d[k++]=c[q];
    else for(int q=i;q<=m;q++) d[k++]=c[q];
}
void MargePess(int x[],int y[],int s,int n)
{
    int i=0;
    while(i<=n-2*s){
        Marge(x,y,i,i+s-1,i+2*s-1);
        i=i+2*s;
    }
    if(i+s<n) Marge(x,y,i,i+s-1,n-1);
    else for(int j=i;j<=n-1;j++) y[j]=x[j];
}

void MargeSort(int a[],int n)
{
    int *b=new int [n];
    int s=1;
    while(s<n){
        MargePess(a,b,s,n);
        s+=s;
        MargePess(b,a,s,n);
        s+=s;
    }
    //for(int j=0;j<n;j++){
    //    cout<<a[j]<<" ";
    //}
}
