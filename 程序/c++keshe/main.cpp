/*题目：考勤管理系统
基本要求：考勤信息记录了学生的缺课情况，它包括：缺课日期、课程名称、学生姓名、学生学号、缺课类型（迟到、早退、请假及旷课）。设计一个考勤管理系统，使之能提供以下功能：
     (1)可新增一个学生的缺课记录；
(2)修改某个学生的缺课记录；
(3)查询某个学生的缺课情况；
(4)其他功能(自行设计)*/

#include<iostream>
#include<iomanip>
#include <string.h>
#include <fstream>
using namespace std;

class Student{
private:
	char name[10];              //姓名
	char date[20];              //考勤记录日期
	char course[20];            //考勤课程
	char type[10];              //考勤类型
	char num[20];               //学号
public:
	Student()
	{
//	    cout<<"请输入学生姓名、学号、缺课日期、缺课课程、缺课类型"<<endl;
//		cin>>name>>num>>date>>course>>type;
	}
	void input()                                     //输入信息
	{
	    cin>>name>>num>>date>>course>>type;
	}
	void print()                                    //输出
	{
	    cout<<name<<setw(12)<<num<<setw(12)<<date<<setw(12)<<course<<setw(12)<<type<<endl;
	}
	char outnum(char nu[])
	{
	    strcpy(nu,num);
	}
	friend void change(Student s[],int n);
	friend int sreach(Student s[],char nu[],int n);
	friend void sort_stu(Student s[],int n);
	friend void writefile(Student s[],int n);

};

//写入文件
void writefile(Student s[],int n)
{
    ofstream SaveFile("cpp-home.txt");
    while(n!=-1)
    {
        SaveFile << s[n].name<<setw(12)<<s[n].num<<setw(12)<<s[n].date<<setw(12)<<s[n].course<<setw(12)<<s[n].type<<endl;
        n--;
    }
    cout<<"写入成功!"<<endl;
    SaveFile.close();
}

//排序
void sort_stu(Student s[],int n)
{
    Student ch;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n-1;j++)
        {
            if(strcmp(s[i].num,s[j].num)>0)
            {
                ch=s[i];
                s[i]=s[j];
                s[j]=ch;
            }
        }
    }
}

//查找
int sreach(Student s[],int n)
{
    char nu[10],nu1[20];
    cin>>nu;
    for(int i=0;i<n;i++)
    {
        s[i].outnum(nu1);
        if(strcmp(nu1,nu)==0)
        {
            return i;
            break;
        }
        else if(i==n-1)
            cout<<"不存在这个学生的考勤信息"<<endl;
    }
}
//修改
void change(Student s[],int n)
{
    int mark,k;
    k=sreach(s,n);
    do{
    //    cout<<"1.修改学生姓名"<<endl;
        cout<<"1.修改考勤时间"<<endl;
    //    cout<<"3.修改考勤课程"<<endl;
        cout<<"2.修改考勤类型"<<endl;
        cout<<"0.返回上级菜单"<<endl;
        cout<<"请输入你的选择："<<endl;
        cin>>mark;
        switch(mark)
        {
        case 1:
            cout<<"请输入修改后的时间："<<endl;
            cin>>s[k].date;
            cout<<"修改成功！"<<endl;
            break;
        case 2:
            cout<<"请输入修改后的考勤类型："<<endl;
            cin>>s[k].type;
            cout<<"修改成功！"<<endl;
            break;
        }
    }while(mark!=0);
}

//菜单
void menu()
{
    cout<<"1.录入学生考勤信息"<<endl;
    cout<<"2.浏览学生考勤信息"<<endl;
    cout<<"3.修改学生考勤信息"<<endl;
    cout<<"4.查询学生考勤信息"<<endl;
    cout<<"5.新增学生考勤记录"<<endl;
    cout<<"6.存入文件"<<endl;
    cout<<"0.退出"<<endl;
}

int main()
{
    int j,n,pass=0;
    Student s[100];
    cout<<"请输入密码："<<endl;
    cin>>pass;
    if (pass==1234)
  {
    do
    {
        menu();
        cout<<"请输入你的选择："<<endl;
        cin>>j;
        switch(j)
        {
        case 1:
            cout<<"要录入的人数："<<endl;
            cin>>n;
            cout<<"请输入学生姓名、学号、缺课日期、缺课课程、缺课类型"<<endl;
            for (int i=0;i<n;i++)
                s[i].input();
            cout<<"录入成功！"<<endl;
            break;
        case 2:
        //    cout<<n<<endl;
            sort_stu(s,n);
            cout<<"学生姓名"<<setw(8)<<"学号"<<setw(12)<<"缺课日期"<<setw(12)<<"缺课课程"<<setw(12)<<"缺课类型"<<endl;
            for(int i=0;i<n;i++)
            {
                s[i].print();
            }
            break;
        case 3:
            cout<<"输入要修改的学生学号"<<endl;
            change(s,n);
            break;
        case 4:{
            cout<<"输入要查询的学生学号"<<endl;
            int mark;
            mark=sreach(s,n);
            cout<<"学生姓名"<<setw(8)<<"学号"<<setw(12)<<"缺课日期"<<setw(12)<<"缺课课程"<<setw(12)<<"缺课类型"<<endl;
            s[mark].print();
            break;}
        case 5:{
            cout<<"输入要新增的学生人数："<<endl;
            int nadd=0;
            cin>>nadd;
            cout<<"请输入学生姓名、学号、缺课日期、缺课课程、缺课类型"<<endl;
            for (int i=n;i<n+nadd;i++)
                s[i].input();
            cout<<"录入成功！"<<endl;
            n+=nadd;
            break;}
        case 6:
            writefile(s,n);
            break;
        }
    }
    while(j!=0);
  }
  else
    cout<<"密码错误无法登陆！"<<endl;
    return 0;
}
