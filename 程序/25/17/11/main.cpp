//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    cout <<"Xi'an University of Technology";
//    return 0;
//}

////////////////////////////
//#include <iostream>
//#include <string.h>
//#include <stdio.h>
//using namespace std;
//
//int x[1005][3],y[1005][3],yp[1005];
//int ya[1005];
//
//int main()
//{
//    int n=1,m=1;
//    while(scanf("%d%d",&n,&m)==2)
//    {
//        if (n==0||m==0)
//            break;
//        char a1,a2,a3;
//        for (int i=0;i<n;i++)
//        {
//            cin>>a1>>x[i][0]>>a2>>x[i][1]>>a3;
//        }
//        for (int i=0;i<m;i++)
//        {
//            cin>>a1>>y[i][0]>>a2>>y[i][1]>>a3;
//        }
//
//        for (int i=0;i<m;i++)
//        {
//            scanf("%d",&yp[i]);
//        }
//
//        for (int j=0;j<m;j++)
//        {
//            ya[j]=0;
//            long long jud=0;
//            jud=yp[j]*yp[j];
//            for (int i=0;i<n;i++)
//            {
//                long long ps;
//                ps=((x[i][0]-y[j][0])*(x[i][0]-y[j][0]))+((x[i][1]-y[j][1])*(x[i][1]-y[j][1]));
//                if(ps<=jud)
//                    ya[j]++;
//            }
//        }
//        cout<<ya[0];
//        for (int j=1;j<m;j++)
//        {
//            cout<<" "<<ya[j];
//        }
//        cout <<endl;
//    }
//    return 0;
//}


////////////////
//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//using  namespace std;
//int main()
//{
//    int a;
//    cin>>a;
//    if (a>=3)
//    {
//        cout <<"2"<<endl<<"3"<<endl;
//        for (int i=3;i<=a;i++)
//        {
//            for(int y=2;y<=i;y++)
//             if (i%y==0)
//                break;
//            else
//             cout<<i<<endl;
//        }
//
//    }
//    else if (a==2)
//    {
//        cout<<"2"<<endl;
//    }
//
//
//
//    return 0;
//}

//#include <iostream>
//#include <cmath>
//using namespace std;
//bool prime(int x)
//{
//     int y;
//     for(y=2;y<=sqrt(x);y++)
//         if (x%y==0)
//            return 0;
//     return 1;
//}
//int main ()
//{
//    int n,i;
//    cin>>n;
//
//    if(n>=2)
//        cout<<"2"<<endl;
//    for(i=3;i<=n;i++)
//        if (prime(i))
//            cout<<i<<endl;
//
//    return 0;
//}

//已知两点求到圆心的距离
///////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using  namespace std;
int main()
{
    int n;
    cin>>n;
    while (n)
    {
        double x1,y1,x2,y2,zhx,zhy,r,p;
        char a1,a2,a3,a4,a5,a6;
        cin>>a1>>x1>>a2>>y1>>a3;
        cin>>a1>>x2>>a2>>y2>>a3;
        cin>>a1>>zhx>>a2>>zhy>>a3>>r;
        double A,B,C,d,d1;
        A = y2 - y1;
        B = x1 - x2;
        C = x2*y1 - x1*y2;
        d1=sqrt((A*A+B*B));
 //       cout<<d1<<endl;
        d=abs(A*zhx+B*zhy+C);
 //       cout <<d<<endl;
        d=d/d1;
 //       cout<<d<<endl;
 if(d==r)
 {
     cout <<"QAQ"<<endl;
 }
 else if (d<r)
    cout<<"Ahahaha!!"<<endl;
 else if (d>r)
    cout <<"OH NO!!"<<endl;


        n--;
    }
    return 0;
}
