/*
//�����в���һ��ֵ��������ı��
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
        double length;   //����
        double breadth;  // ���
        double height;    //�߶�
        double volume;    //���
};
int main()
{
    Box Box1;
    Box Box2;
    ///////////// Box1������
    Box1.length=5.0;
    Box1.height=6.0;
    Box1.breadth=7.0;
    ///////////// Box2������
    Box2.length=10.0;
    Box2.height=12.0;
    Box2.breadth=13.0;
    /////////// ���
    Box1.volume=Box1.breadth*Box1.height*Box1.length;
    Box2.volume=Box2.breadth*Box2.height*Box2.length;
    cout << "Box1 �������" << Box1.volume<<endl;
    cout << "Box2 �������" << Box2.volume<<endl;
    return 0;
}
