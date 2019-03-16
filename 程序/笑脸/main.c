#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include <bios.h>
main()
{ int i,key,x,y;/*存放笑脸坐标*/


for(i=20;i<=60;i++)/*绘制第一行星号*/
{ gotoxy(i,1);printf("*");}

gotoxy(20,2);printf("*"); /*绘制第二行*/
gotoxy(40,2);printf("%c",003);
gotoxy(60,2);printf("*");


for(i=20;i<=60;i++) /*绘制第三行星号*/
{ gotoxy(i,3); printf("*");}

for(i=15;i<=65;i++)/*绘制上方框*/
{ gotoxy(i,4);printf("%c",219);}

for(i=5;i<=24;i++)/*绘制左右方框*/
{ gotoxy(15,i);printf("%c",219);gotoxy(65,i);printf("%c",219);}


for(i=15;i<=65;i++)/*绘制下方框*/
{ gotoxy(i,25);printf("%c",219);}


gotoxy(40,15);printf("%c",001);
gotoxy(40,15);
x=40;
y=15;

/*看键盘移动*/
for(;;) /*死循环*/
{
key=bioskey(0);
switch(key)
{ case 0x4800:
if(y<=5){continue;}
printf(" ");
y--;
gotoxy(x,y);
printf("\1");
gotoxy(x,y);
break;/*向上*/
case 0x4b00:if(x<=16){continue;}printf(" ");x--;gotoxy(x,y);printf("\1");gotoxy(x,y);break;/*左*/
case 0x5000:if(y>=24){continue;}printf(" ");y++;gotoxy(x,y);printf("\1");gotoxy(x,y);break;/*下*/
case 0x4d00:if(x>=64){continue;}printf(" ");x++;gotoxy(x,y);printf("\1");gotoxy(x,y);break;/*右*/
}
if(key==0x11b)
{ exit(0);
}
}


getch();
}
