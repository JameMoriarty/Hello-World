/*��Ŀ�����ڹ���ϵͳ
����Ҫ�󣺿�����Ϣ��¼��ѧ����ȱ���������������ȱ�����ڡ��γ����ơ�ѧ��������ѧ��ѧ�š�ȱ�����ͣ��ٵ������ˡ���ټ����Σ������һ�����ڹ���ϵͳ��ʹ֮���ṩ���¹��ܣ�
     (1)������һ��ѧ����ȱ�μ�¼��
(2)�޸�ĳ��ѧ����ȱ�μ�¼��
(3)��ѯĳ��ѧ����ȱ�������
(4)��������(�������)*/

#include<iostream>
#include<iomanip>
#include <string.h>
#include <fstream>
using namespace std;

class Student{
private:
	char name[10];              //����
	char date[20];              //���ڼ�¼����
	char course[20];            //���ڿγ�
	char type[10];              //��������
	char num[20];               //ѧ��
public:
	Student()
	{
//	    cout<<"������ѧ��������ѧ�š�ȱ�����ڡ�ȱ�ογ̡�ȱ������"<<endl;
//		cin>>name>>num>>date>>course>>type;
	}
	void input()                                     //������Ϣ
	{
	    cin>>name>>num>>date>>course>>type;
	}
	void print()                                    //���
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

//д���ļ�
void writefile(Student s[],int n)
{
    ofstream SaveFile("cpp-home.txt");
    while(n!=-1)
    {
        SaveFile << s[n].name<<setw(12)<<s[n].num<<setw(12)<<s[n].date<<setw(12)<<s[n].course<<setw(12)<<s[n].type<<endl;
        n--;
    }
    cout<<"д��ɹ�!"<<endl;
    SaveFile.close();
}

//����
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

//����
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
            cout<<"���������ѧ���Ŀ�����Ϣ"<<endl;
    }
}
//�޸�
void change(Student s[],int n)
{
    int mark,k;
    k=sreach(s,n);
    do{
    //    cout<<"1.�޸�ѧ������"<<endl;
        cout<<"1.�޸Ŀ���ʱ��"<<endl;
    //    cout<<"3.�޸Ŀ��ڿγ�"<<endl;
        cout<<"2.�޸Ŀ�������"<<endl;
        cout<<"0.�����ϼ��˵�"<<endl;
        cout<<"���������ѡ��"<<endl;
        cin>>mark;
        switch(mark)
        {
        case 1:
            cout<<"�������޸ĺ��ʱ�䣺"<<endl;
            cin>>s[k].date;
            cout<<"�޸ĳɹ���"<<endl;
            break;
        case 2:
            cout<<"�������޸ĺ�Ŀ������ͣ�"<<endl;
            cin>>s[k].type;
            cout<<"�޸ĳɹ���"<<endl;
            break;
        }
    }while(mark!=0);
}

//�˵�
void menu()
{
    cout<<"1.¼��ѧ��������Ϣ"<<endl;
    cout<<"2.���ѧ��������Ϣ"<<endl;
    cout<<"3.�޸�ѧ��������Ϣ"<<endl;
    cout<<"4.��ѯѧ��������Ϣ"<<endl;
    cout<<"5.����ѧ�����ڼ�¼"<<endl;
    cout<<"6.�����ļ�"<<endl;
    cout<<"0.�˳�"<<endl;
}

int main()
{
    int j,n,pass=0;
    Student s[100];
    cout<<"���������룺"<<endl;
    cin>>pass;
    if (pass==1234)
  {
    do
    {
        menu();
        cout<<"���������ѡ��"<<endl;
        cin>>j;
        switch(j)
        {
        case 1:
            cout<<"Ҫ¼���������"<<endl;
            cin>>n;
            cout<<"������ѧ��������ѧ�š�ȱ�����ڡ�ȱ�ογ̡�ȱ������"<<endl;
            for (int i=0;i<n;i++)
                s[i].input();
            cout<<"¼��ɹ���"<<endl;
            break;
        case 2:
        //    cout<<n<<endl;
            sort_stu(s,n);
            cout<<"ѧ������"<<setw(8)<<"ѧ��"<<setw(12)<<"ȱ������"<<setw(12)<<"ȱ�ογ�"<<setw(12)<<"ȱ������"<<endl;
            for(int i=0;i<n;i++)
            {
                s[i].print();
            }
            break;
        case 3:
            cout<<"����Ҫ�޸ĵ�ѧ��ѧ��"<<endl;
            change(s,n);
            break;
        case 4:{
            cout<<"����Ҫ��ѯ��ѧ��ѧ��"<<endl;
            int mark;
            mark=sreach(s,n);
            cout<<"ѧ������"<<setw(8)<<"ѧ��"<<setw(12)<<"ȱ������"<<setw(12)<<"ȱ�ογ�"<<setw(12)<<"ȱ������"<<endl;
            s[mark].print();
            break;}
        case 5:{
            cout<<"����Ҫ������ѧ��������"<<endl;
            int nadd=0;
            cin>>nadd;
            cout<<"������ѧ��������ѧ�š�ȱ�����ڡ�ȱ�ογ̡�ȱ������"<<endl;
            for (int i=n;i<n+nadd;i++)
                s[i].input();
            cout<<"¼��ɹ���"<<endl;
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
    cout<<"��������޷���½��"<<endl;
    return 0;
}
