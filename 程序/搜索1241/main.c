#include    <stdio.h>

#include    <string.h>

#include    <stdlib.h>



int count,m,n;

char map[103][103];

int memo[103][103];

int direction[8][2]={{1,0},{1,-1},{1,1},{-1,0},{-1,-1},{-1,1},{0,1},{0,-1}};



void dfs(int x,int y)

{

    if(memo[x][y]==0)   return;

    if(x<=0||x>n||y<=0||y>m)      return;

    memo[x][y]=0;

    if(map[x][y]=='@')

    {

        int I;

        for(I=0;i<8;i++)

            dfs(x+direction[I][0],y+direction[I][1]);

    }

    else    return;

}





int main()

{

    while(scanf("%d %d",&n,&m)&&n!=0&&m!=0)

    {

        memset(memo,0,sizeof(memo));

        count=0;

        int I,j;

        for(I=1;i<=n;i++)

            for(j=1;j<=m;j++)

            {

                scanf(" %c",&map[I][j]);

                if(map[I][j]=='@')  memo[I][j]=1;

            }

        for(I=1;i<=n;i++)

            for(j=1;j<=m;j++)

            {

                if(memo[I][j])

                {

                    dfs(I,j);

                    count++;

                }

            }

        printf("%d\n",count);

    }

    return 0;
}#include    <stdio.h>

#include    <string.h>

#include    <stdlib.h>



int count,m,n;

char map[103][103];

int memo[103][103];

int direction[8][2]={{1,0},{1,-1},{1,1},{-1,0},{-1,-1},{-1,1},{0,1},{0,-1}};



void dfs(int x,int y)

{

    if(memo[x][y]==0)   return;

    if(x<=0||x>n||y<=0||y>m)      return;

    memo[x][y]=0;

    if(map[x][y]=='@')

    {

        int I;

        for(I=0;i<8;i++)

            dfs(x+direction[I][0],y+direction[I][1]);

    }

    else    return;

}





int main()

{

    while(scanf("%d %d",&n,&m)&&n!=0&&m!=0)

    {

        memset(memo,0,sizeof(memo));

        count=0;

        int I,j;

        for(I=1;i<=n;i++)

            for(j=1;j<=m;j++)

            {

                scanf(" %c",&map[I][j]);

                if(map[I][j]=='@')  memo[I][j]=1;

            }

        for(I=1;i<=n;i++)

            for(j=1;j<=m;j++)

            {

                if(memo[I][j])

                {

                    dfs(I,j);

                    count++;

                }

            }

        printf("%d\n",count);

    }

    return 0;
}
