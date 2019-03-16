#include <stdio.h>
#include <windows.h>
int main(void)
{
HANDLE hOut;
COORD pos= {0,2}; /* 光标的起始位（第1列，第3行） 0是第1列 2是第3行*/
hOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hOut, pos);
printf("定位光标位置(%d,%d)\n",pos.X,pos.Y);
return 0;
}
