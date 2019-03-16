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
    printf("生日快乐！！！！");

    return 0;
}

void first( )
{
    system("cls");
    system("color 1C");
    HANDLE hOut;
    COORD pos= {30,7}; // 光标的起始位（第1列，第3行） 0是第1列 2是第3行//
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
    printf("啦啦啦啦~听说今天是你的生日~是不是？\n");
    COORD a= {40,9}; // 光标的起始位（第1列，第3行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, a);
    Sleep(1000);
    printf("\t啊哈~\n");
    COORD a1= {31,11}; // 光标的起始位（第1列，第3行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, a1);
    Sleep(1000);
    printf("如果是你的生日，那就祝你生日快乐喽~\n");
    COORD a2= {31,13}; // 光标的起始位（第1列，第3行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, a2);
    Sleep(1000);
    printf("如果不是，那就当做是不及时的祝福吧~\n");
    COORD a3= {35,15}; // 光标的起始位（第1列，第3行） 0是第1列 2是第3行//
    SetConsoleCursorPosition(hOut, a3);
    Sleep(1000);
    printf("（撒花ing~ [动态效果省略~]）");
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
    printf("生日快乐啊~送你的大蛋糕~快许愿吧！！（比心~）");
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
    COORD a= {30,25}; /* 光标的起始位（第1列，第3行） 0是第1列 2是第3行*/
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


