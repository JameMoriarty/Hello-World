//#include <iostream>
//#include <cstring>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int T;
//    cin>>T;
//    while(T--)
//    {
//        int k,i=0;
//        cin>>k;
//        char str[100006];
//        scanf("%c",&str[0]);
//        while(str[i]!='\n')
//        {
//            i++;
//            scanf("%c",&str[i]);
//        }
//
//    }
//    return 0;
//}



#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long poi;
        long long sum,j=0;
        scanf("%lld%lld",&sum,&poi);
        long long  num[100060],oth[100060];
        for(int i=0;i<sum;i++)
        {
            scanf("%d",&num[i]);
        }
        for(int i= 0;i<sum;i++)
        {
            if(num[i]!=poi)
            {
                oth[j]=num[i];
                j++;
            }
        }
        long long k=j;
        j=0;
        int h=0;
        while(h!=k-1)
        {
            if(oth[h]>oth[h+1])///µÝÔö
            {
                j=1;
                break;
            }
            h++;
        }
        h=0;
        int l=0;
        if(j==1)
        {
            while(h!=k-1)
            {
                if(oth[h]<oth[h+1])
                {
                    l=1;
                    break;
                }
                h++;
            }
        }
        if((j==1&&l==1)||k==0||k==1)
            printf("A is a magic array.\n");
        else
            printf("A is not a magic array.\n");
    }
    return 0;
}
