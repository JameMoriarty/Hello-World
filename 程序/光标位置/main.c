#include <stdio.h>
#include <windows.h>
int main(void)
{
HANDLE hOut;
COORD pos= {0,2}; /* ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��*/
hOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hOut, pos);
printf("��λ���λ��(%d,%d)\n",pos.X,pos.Y);
return 0;
}
