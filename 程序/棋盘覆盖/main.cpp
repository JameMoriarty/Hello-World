#include <iostream>

using namespace std;
void chessboard(int tr,int tc, int dr,int dc,int sizes,int& t,int board[100][100]);
int tile=0;
int main()
{
    int board1[100][100],tr,tc,dr,dc,sizes;
    cout << "输入棋盘的规格sizes×sizes：" <<endl;
    cin>>sizes;
    cout << "输入左上角方格的行号：" <<endl;
    cin>>tr;
    cout << "输入左上角方格的列号：" <<endl;
    cin>>tc;
    cout << "输入特殊方格的行号：" <<endl;
    cin>>dr;
    cout << "输入特殊方格的列号：" <<endl;
    cin>>dc;
    int tile=0;
    chessboard(tr,tc,dr,dc,sizes,tile,board1);
    cout<<tile<<endl;
    for(int i=0;i<sizes;i++){
        for(int j=0;j<sizes;j++)
            cout<<board1[i][j];
        cout<<endl;
    }
    return 0;
}
void chessboard(int tr,int tc, int dr,int dc,int sizes,int& t,int board[100][100])
{
    if(sizes==1) return;
    t++;
    int s=sizes/2;
    if(dr<tr+s&&dc<tc+s)
        chessboard(tr,tc,dr,dc,s,t,board);
    else{
        board[tr+s-1][tc+s-1]=t;
        chessboard(tr,tc,tr+s-1,tc+s-1,s,t,board);
    }
    if(dr<tr+s&&dc>=tc+s)
        chessboard(tr,tc+s,dr,dc,s,t,board);
    else{
        board[tr+s-1][tc+s]=t;
        chessboard(tr,tc+s,tr+s-1,tc+s,s,t,board);
    }
    if(dr>=tr+s&&dc>=tc+s)
        chessboard(tr+s,tc,dr,dc,s,t,board);
    else{
        board[tr+s][tc+s-1]=t;
        chessboard(tr=s,tc,tr+s,tc+s-1,s,t,board);
    }
    if(dr>=tr+s&&dc>=tc+s)
        chessboard(tr=s,tc+s,dr,dc,s,t,board);
    else{
        board[tr+s][tc+s]=t;
        chessboard(tr+s,tc+s,tr+s,tc+s,s,t,board);
    }
   // cout<<t;
}
