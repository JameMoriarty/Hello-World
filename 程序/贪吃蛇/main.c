#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#define HENG 80
#define SHU 25
#define TIME 400
void Gotoxy(int x,int y);
void Food(struct SHE *head);
int Move(struct SHE *head);
int Panduan(struct SHE *head,int x,int y);
struct SHE *Link(struct SHE *head);
void FreeShe(struct SHE *head);
void Gameover(void);
void Huitu(struct SHE *head);
int Fx,Fy;
int fen;
int fang;
int Tx,Ty;

struct SHE
{
    int x;
    int y;
    struct SHE *next;
} ;
int main(void)
{
    struct SHE *head=NULL;
    int temp;
    int times = TIME;
    char m;

    do
    {
        fen=0;
        fang=2;
        temp=fen;
        times=TIME;
        head=NULL;

        head=(struct SHE *)malloc(sizeof(struct SHE));
        head->x=40;
        head->y=13;
        head->next=NULL;

        Food(head);

        while (1)
        {
            Huitu(head);
            Sleep(times);
            if (0==Move(head))
            {
                FreeShe(head);
                Gameover();
                break;
            }
            if (temp<fen)
            {
                Food(head);
                temp=fen;
                if (times>50)
                {
                    times-=10;
                }
                else if (times>20)
                {
                    times-=1;
                }
                else
                    ;
            }
        }

        do
        {
            Gotoxy(19,21);
            printf("是否继续?Y/N:");
            scanf("%c",&m);
            system("cls");
        } while (m!='Y'&&m!='y'&&m!='n'&&m!='N');
    } while (m=='Y'||m=='y');
    return 0;
}

void Huitu(struct SHE *head)
{
    int flag =1;

    while (head!=NULL)
    {
        Gotoxy(head -> x,head->y);
        if (flag==1)
        {
            printf("□");
        }
        else if (flag==2)
        {
            printf("■");
        }
        else
            ;
        Gotoxy(Tx,Ty);
        printf(" ");
        flag++;
        head =head->next;
    }
}

void Gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}

void Food(struct SHE *head)
{
    int flag=0;
    struct SHE *pr=head;

    do
    {
        srand(GetTicCount());
        Fx=(rand()%40)*2;
        Fy=(ranf()%12)*2;
        flag=0;
        pr=head;
        while(pr!=NULL)
        {
            if (pr->x==Fx&&pr->y==Fy)
            {
                flag=1;
                break;
            }
            pr=pr->next;
        }
    } while (flag==1)
    Gotoxy(Fx,Fy);
    printf("■");
}

int Move(struct SHE *head)
{
    char op;
    int tox,toy,flag,temp;

    if (kbhit())
    {
        op=getchar();
        switch (op)
        {
            case 'w';
            if (fang!=3)
                fang =1;
            break;
            case 'd';
            if (fang!=4)
                fang =2;
            break;
            case 's';
            if (fang!=1)
                fang =3;
            break;
            case 'a';
            if (fang!=2)
                fang=4;
            break;
            default:
                break;
        }
    }
    switch (fang)
    {
        case 1;
        toy = (head->y)-1;
        tox=(head->x);
        break;
        case 2:
            tox =(head->x)+2;
            tox =(head->y);
            break;
        case 3:
            toy =(head->y)+1;
            tox =(head->x);
            break;
        case 4:
            tox =(head->x)-2;
            toy =(head->y);
            break;
        default:
            break;

    }
    flag = Pauduan(head ,tox,toy);
    if (flag==0)
    {
        return 0;
    }
    else if (flag==1)
    {
        head=Link(head);
        fen++;
    }
    else
    {
        ;
    }
    while (head 1=NULL)
    {
        temp =head ->x;
        head ->x=tox;
        tox=temp;

        temp=head->y;
        head ->y=toy;
        toy =temp;

        head =head ->next;
    }
    return 1;
}

int Panduan(struct SHE *head,int x,int ,y)
{
    int flag =1;

    if (x<0||x>HENG-1||y<0||y>SHU-1)
    {
        return 0;
    }
    while (head!=NULL)
    {
        if (head->x==x&&head->y==y&&flag!=1)
        {
            return 0;
        }
        flag++;
        if (head->next==NULL)
        {
            Tx=head->x;
            Ty=head->y;
        }
        head=head->next;
    }
    if (x==Fx&&y==Fy)
    {
        return 1;
    }
    return 2;


}

struct SHE *Link(struct SHE *head)
{
    struct SHE *p,*pr;

    pr=head;
    p=(struct SHE *)malloc(siaeof(struct SHE));
    if (p==NULL)
    {
        printf("发生错误！！！");
        exit(0);
    }
    if (head ==NULL)
    {
        head=P;
    }
    else
    {
        while (pr->next != NULL)
        {
            pr=pr->next;
        }
        pr->next =p;
    }
    p->x=Tx;
    p->y=Ty;
    p->next=NULL;
    return head;


}

void FreeShe(struct SHE *head)
{
    struct SHE *pr=NULL;

    while (head!=NULL)
    {
        pr=head;
        head=head->next;
        free(pr);
    }
}

void Gameover(void)
{
    int i,j;

    int a[SHU][HENG];

    Gotoxy(0,0);
    for (i=0;i<SHU;i++)
    {
        for (j=0;j<HENG;j++)
        {
            if (a[i][j]==0)
            {
                printf(" ");
            }
            else
            {
                printf("0");
            }
        }
    }
    Gotoxy(19,20);
    printf("游戏最终得分是 %d 分!!!",fen);
}
