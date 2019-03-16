
//k
//#include <iostream>
//#include <cstdio>
//#include <math.h>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;

//int main()
//{
//    int t;
//    cin>>t;
//    for(int i=0;i<t;i++)
//    {
//        int s;
//        cin>>s;
//        int a[10050]={0};
//        for (int j=0;j<s;j++)
//        {
//            cin>>a[j];
//
//        }
//        int l=0,b[10050];
//        for(int j=1;j<s;j++)
//        {
//            b[l]=a[j]-a[j-1]-1;
//            l++;
//        }
//        int minb=0;
//        minb=min(b[0],b[s-2]);
////        cout<<minb<<endl;
//        int ans=0;
//        for(int j=0;j<s-1;j++)
//        {
// //           cout<<b[j];
//            ans+=b[j];
//
//        }
//        ans=ans-minb;
// //       cout<<endl;
// //       int num=0;
//
////        num=a[s-1]-a[0]+1;
//
////        if(num-s<=0)
////        {
////            ans=0;
////        }
////        else if(num-s>0&&num-s<s)
////        {
////            ans=num-s;
////        }
////        else if(num-s>0&&num-s>s)
////        {
////            ans=b[s-2]-1;
////        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <string.h>
using namespace std;

//#define MAXL (2^64)+2
//#define MAXA MAXL*4
//#define MAXL 200
//#define MAXA 200

int main()
{
    int T;
    cin>>T;
 //   char a[MAXL],b[MAXL],c[MAXL],d[MAXL],totl[MAXA];
    string a,b,c,d,total;
    for (int l=0;l<T;l++)
    {
//        memset(a,0,sizeof(a));
//        memset(b,0,sizeof(b));
//        memset(c,0,sizeof(c));
//        memset(d,0,sizeof(d));
        int i=0,j=0,k=0,p=0;
//        char s;
//        while(cin>>a[i++])
//        {
//            if(a[i]==32)
//                break;
//        }
        cin>>a;
        cin>>b;
        cin>>c;
        cin>>d;
        total=a+b+c+d;
        cout<<total<<endl;
//        cout<<"end"<<endl;
//        while(scanf("%d",&b[j])!=EOF)
//        {
//            j++;
//        }
//        while(scanf("%d",&c[k])!=EOF)
//        {
//            k++;
//        }
//        while(scanf("%d",&d[p])!=EOF)
//        {
//            p++;
//        }
//        cout<<"ok"<<endl;

    }
    return 0;
}

