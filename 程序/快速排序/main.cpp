#include<iostream>
using namespace std;
int Partition(int a[],int p,int r,int n);
void QuickSort(int a[],int p,int r,int n);
int main()
{
	int a[100],p,r,n;
	cout<<"输入数字个数："<<endl;
	cin>>n;
	cout<<"输入数字："<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	p=1;
	r=n;
	QuickSort(a,p,r,n);
	for(int j=1;j<=n;j++){
		cout<<a[j]<<" ";
	}
	return 0;
}

int Partition(int a[],int p,int r,int n){
	int i=p,j=r+1,x1;
	int x=a[p];
	while(true){
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j) break;
		x1=a[i];
		a[i]=a[j];
		a[j]=x1;
		for(int j=1;j<=n;j++){
		cout<<a[j]<<" ";
        }
        cout<<endl;
	}
	a[p]=a[j];
	a[j]=x;
	for(int j=1;j<=n;j++){
		cout<<a[j]<<" ";
        }
        cout<<endl;
	return j;
}

void QuickSort(int a[],int p,int r,int n){
	if(p<r){
		int q=Partition(a,p,r,n);
		QuickSort(a,p,q-1,n);
		QuickSort(a,q+1,r,n);
	}
}

