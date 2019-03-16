/*#include <iostream>      //特别的 cin 输入 cout 输出
#include <algorithm>     // 算法  sort max 函数~
#include <queue>    //STL
#include <stack>
#include <cstdio>
using namespace std; //命名

int main()
{
    queue <int> q;              //<数据类型名字> 队列
   // q.push (5);
  //  printf("%d\n",q.front());      //访问元素位置
  //  q,empty ();        //  有元素返回为真  无元素返回为假
  //  q.pop ();                  //删除元素
  //  q.size ();    //建双头队列
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

/*#include <iostream>      //特别的 cin 输入 cout 输出
#include <algorithm>     // 算法  sort max 函数~
#include <queue>    //STL
#include <stack>
#include <cstdio>
using namespace std; //命名

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
    printf("有 %d 个元素",stk.size());
    while (!stk.empty())
    {
        printf("%d\n",stk.top());
            stk.pop();
    }
    return 0;
}
*/
#include <iostream>      //特别的 cin 输入 cout 输出
#include <algorithm>     // 算法  sort max 函数~
#include <queue>    //STL
#include <stack>
#include <cstdio>
#include <vector>
using namespace std; //命名

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
    printf("有 %d 个元素\n",a.size());
    for (int i=0;i<a.size();i++)
    {
        printf("%d\n",a[i]);
    }

}


