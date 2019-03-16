#include <iostream>
#include <math.h>
using namespace std;

void Get_k_and_b(int x1,int y1,int x2,int y2)
{
 int k, b;
 k = (y2 - y1) / (x2 - x1);
 b = y1 - k*x1; // b = y2 - k*x2;
 if(b >= 0)
 cout<< "y=" <<k<<"x+"<<b<<endl;
 else
 cout<< "y=" <<k<<"x"<<b<<endl;

}
int main()
{
 int x1,x2,y1,y2;
 cin>>x1;
 cin>>y1;
 cin>>x2;
 cin>>y2;
 Get_k_and_b(x1,y1,x2,y2);
return 0;
}
