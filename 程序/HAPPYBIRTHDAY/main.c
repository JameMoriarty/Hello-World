#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void first ( );
void second ( );
int main()
{
    first ();
    second();
    system("cls");
    HANDLE hOut;
    COORD b9= {49,10};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b9);
    printf("���տ��֣�������");

    return 0;
}

void first( )
{
    system("cls");
    system("color 1C");
    HANDLE hOut;
    COORD pos= {30,7}; // ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��//
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
    printf("��������~��˵�������������~�ǲ��ǣ�\n");
    COORD a= {40,9}; // ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��//
    SetConsoleCursorPosition(hOut, a);
    Sleep(1000);
    printf("\t����~\n");
    COORD a1= {31,11}; // ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��//
    SetConsoleCursorPosition(hOut, a1);
    Sleep(1000);
    printf("�����������գ��Ǿ�ף�����տ����~\n");
    COORD a2= {31,13}; // ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��//
    SetConsoleCursorPosition(hOut, a2);
    Sleep(1000);
    printf("������ǣ��Ǿ͵����ǲ���ʱ��ף����~\n");
    COORD a3= {35,15}; // ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��//
    SetConsoleCursorPosition(hOut, a3);
    Sleep(1000);
    printf("������ing~ [��̬Ч��ʡ��~]��");
    Sleep(2000);
}

void second()
{
    system("cls");
    HANDLE hOut;
    ///////////// 0
    system("color 4E");
    COORD b10= {35,8};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b10);
    printf("���տ��ְ�~����Ĵ󵰸�~����Ը�ɣ���������~��");
    COORD b9= {49,10};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b9);
    printf("  *    *    *");
    COORD b8= {49,11};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b8);
    printf(" **   ***   **");
    COORD b7= {49,12};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b7);
    printf("**** ***** ****");
    COORD b6= {50,13};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b6);
    printf("**   ***   **");
    COORD b5= {50,14};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b5);
    printf("**   ***   **");
    COORD b4= {50,15};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b4);
    printf("**   ***   **");

    ///////////// 1
    COORD b3= {44,16};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b3);
    printf("*************************");
    COORD b2= {44,17};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b2);
    printf("*************************");
    COORD b1= {44,18};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b1);
    printf("*************************");
    COORD b= {44,19};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, b);
    printf("*************************");
    ////////////  2
    COORD a10= {36,20};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a10);
    printf("****@***@*****@****@@@@@***@@@@@@**@***@*");
    COORD a9= {36,21};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a9);
    printf("****@@@@@****@@@***@***@***@****@***@*@**");
    COORD a8= {36,22};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a8);
    printf("****@@@@@***@@@@@**@@@@@***@@@@@@****@***");
    COORD a7= {36,23};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a7);
    printf("****@***@**@*****@*@*******@*********@***");
    COORD a6= {36,24};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a6);
    printf("*****************************************");
    ///////////// 3
    COORD a= {30,25}; /* ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��*/
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a);
    printf("*****************************************************");
    COORD a1= {30,26};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a1);
    printf("*****************************************************");
    COORD a2= {30,27};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a2);
    printf("*****************************************************");
    COORD a3= {30,28};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a3);
    printf("*****************************************************");
    COORD a4= {30,29};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a4);
    printf("*****************************************************");
    COORD a5= {30,30};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a5);
    printf("*****************************************************");
     COORD a11= {30,31};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a11);
    printf("*****************************************************");
     COORD a12= {30,32};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, a12);
    printf("*****************************************************");
    Sleep(5000);
}


