#include "minesweeper.h"

void menu()
{
    printf("**********************\n");
    printf("****0-exit 1-began****\n");
    printf("**********************\n");
}

void game()
{
    // 布置雷
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    Initboard(mine, ROWS, COLS, '0');
    Initboard(show, ROWS, COLS, '*');
    // 打印棋盘
    SetMine(mine, ROW, COL, MINENUMBER);
    DisplayBoard(mine, ROW, COL);

    FindMine(mine, show, ROW, COL);
}

void test()
{
    int flage;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        scanf("%d", &flage);
        switch (flage)
        {
        case 0:
            printf("exit the game\n");
            break;
        case 1:
            printf("began the game\n");
            game();
            break;
        default:
            printf("the input is fail\n");
            break;
        }
    } while (flage);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
