/*
//数组中查找一个值并输出它的编号
#include <iostream>
#include <cstdio>
int sort1(int x,int a[]);
using namespace std;
int main()
{
    int a[100],x,b;
    b=sort1(x,a);
    cout << b;
    return 0;
}
int sort1(int x,int a[])
{
    bool is;
    int i;
    for (i=0;i<10;i++)
    {
        cin >> a[i];
    }
    cin >> x ;
    for (i=0;i<10;i++)
    {
        if (a[i]==x)
        {
            is = true ;
            break;
        }
    }
    if (is)
        return i+1;
    else
        return 0;

}
*/

#include <iostream>
using namespace std ;
class Box
{
    public :
        double length;   //长度
        double breadth;  // 宽度
        double height;    //高度
        double volume;    //体积
};
int main()
{
    Box Box1;
    Box Box2;
    ///////////// Box1的属性
    Box1.length=5.0;
    Box1.height=6.0;
    Box1.breadth=7.0;
    ///////////// Box2的属性
    Box2.length=10.0;
    Box2.height=12.0;
    Box2.breadth=13.0;
    /////////// 体积
    Box1.volume=Box1.breadth*Box1.height*Box1.length;
    Box2.volume=Box2.breadth*Box2.height*Box2.length;
    cout << "Box1 的体积：" << Box1.volume<<endl;
    cout << "Box2 的体积：" << Box2.volume<<endl;
    return 0;
}
