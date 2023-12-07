#include "minesweeper.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
    for (int i = 0, j; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i, j;
    for (j = 0; j <= col; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d-", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void SetMine(char board[ROWS][COLS], int row, int col, int number)
{
    while (number)
    {
        int x = (rand() % row) + 1;
        // 棋盘的位置在0~10
        // 雷的位置在1~9
        // 如果是满棋盘的话就是0~8，%row就正好
        int y = (rand() % col) + 1;
        if (board[x][y] != '#')
        {
            board[x][y] = '#';
            int i, j;
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    if (board[x + i][y + j] != '#')
                    {
                        board[x + i][y + j]++;
                    }
                }
            }
            number--;
        }
    }
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int win=ROW*COL-MINENUMBER;
    
    int x, y;
    do
    {
        printf("%d\n",win);
        printf("please input position\n");
        scanf("%d%d", &x, &y);
        if (x > 0 && y > 0 && x <= ROW && y <= COL)
        {
            if (mine[x][y] == '#')
            {
                printf("there is a minue\n");
                //显示所有雷
                break;
            }
            else
            {
                // show[x][y]=mine[x][y];//1
                win=win-LinkShow(mine,show,row,col,x,y);//2
                DisplayBoard(show,row,col);
            }
            
        }
        else
        {
            printf("the position is fail\n");
        }
    // } while (--win);//1
    }while(win);//2
    //do while先进行一次再判断，所以要--win，先减去再判断
    //while先判断，所以用win--，先判断后减去
    int i,j;
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
        {
            if(mine[i][j]=='#')
            {
                show[i][j]=mine[i][j];
            }
        }
    }
    DisplayBoard(show,row,col);
    if(win==0)
    {
        printf("you win\n");
    }
}

int LinkShow(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y)
{
    //1--数字
    //2--0  0的话迭代扩散
    //判断是否出界，出界结束
    //判断是否已经找出，防止重复迭代
    if(x<1||y<1||x>row||y>col)
    {
        return 0;
    }
    if(show[x][y]!='*')
    {
        return 0;
    }
    show[x][y]=mine[x][y];
    if(mine[x][y]!='0')
    {
        return 1;
    }
    else
    {
        return 1+
        LinkShow(mine,show,row,col,x-1,y)+
        LinkShow(mine,show,row,col,x+1,y)+
        LinkShow(mine,show,row,col,x,y-1)+
        LinkShow(mine,show,row,col,x,y+1);
    }
}