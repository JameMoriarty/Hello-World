/*#include <iostream>      //�ر�� cin ���� cout ���
#include <algorithm>     // �㷨  sort max ����~
#include <queue>    //STL
#include <stack>
#include <cstdio>
using namespace std; //����

int main()
{
    queue <int> q;              //<������������> ����
   // q.push (5);
  //  printf("%d\n",q.front());      //����Ԫ��λ��
  //  q,empty ();        //  ��Ԫ�ط���Ϊ��  ��Ԫ�ط���Ϊ��
  //  q.pop ();                  //ɾ��Ԫ��
  //  q.size ();    //��˫ͷ����
    for (int i=1;i<=100;i++)
    {
        if (i%3==0)
        {
            q.push (i);
            printf("%d  ",q.front());
            q.pop();

        }

    }


    return 0;
}
*/

/*#include <iostream>      //�ر�� cin ���� cout ���
#include <algorithm>     // �㷨  sort max ����~
#include <queue>    //STL
#include <stack>
#include <cstdio>
using namespace std; //����

int main()
{
    stack<int > stk;
    for (int i=1;i<=100;i++)
    {
        if (i%3==0)
        {
            stk.push(i);
        }
    }
    printf("�� %d ��Ԫ��",stk.size());
    while (!stk.empty())
    {
        printf("%d\n",stk.top());
            stk.pop();
    }
    return 0;
}
*/
#include <iostream>      //�ر�� cin ���� cout ���
#include <algorithm>     // �㷨  sort max ����~
#include <queue>    //STL
#include <stack>
#include <cstdio>
#include <vector>
using namespace std; //����

int main()
{
    vector <int > a;
    for (int i=1;i<=100;i++)
    {
        if (i%3==0)
        {
            a.push_back(i);
        }
    }
    printf("�� %d ��Ԫ��\n",a.size());
    for (int i=0;i<a.size();i++)
    {
        printf("%d\n",a[i]);
    }

}


